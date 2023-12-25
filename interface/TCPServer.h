#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <thread>
#include "iTCPAgent.h"
#include "TCP_exceptions.h"
#include <semaphore>
#include <iostream>

class TCPServer
{
private:
    int server_fd;
    int new_socket;
    struct sockaddr_in address;
    int addrlen;
    std::map<int, std::pair<iTCPAgent*,std::thread>> tcp_clients;
    bool done;
    std::counting_semaphore<5> sem;
    
    static const std::string greeting;
    static const int PORT;
    static const int OPTED;
    static const int MAX_CLIENTS;

public:
    TCPServer();
    TCPServer(TCPServer&& ts);
    ~TCPServer();

    void client_desconnected(int socket_fd);

    template <class S>
    void run()
    {
        // Creating socket file descriptor 
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            throw SocketFailedException();

        // Setting sock options
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &TCPServer::OPTED, sizeof(TCPServer::OPTED)))
            throw SetSockOptFailedException();
    
        address.sin_family = AF_INET;  
        address.sin_addr.s_addr = INADDR_ANY;  
        address.sin_port = htons(TCPServer::PORT);

        addrlen = sizeof(address);

        // Forcefully attaching socket to port 8080
        if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
            throw BindFailedException();

        if (listen(server_fd, 3) < 0)
            throw ListenFailedException();
        
        std::cout << "Socket server running. Waiting for a new client connection..." << std::endl;
        while(!done) {
            sem.acquire();
            if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0)
                throw AcceptFailedException();
            iTCPAgent *ta = new S(new_socket, this); 
            std::thread new_client {&iTCPAgent::run, ta};
            new_client.detach();
        }
    }
};

#endif