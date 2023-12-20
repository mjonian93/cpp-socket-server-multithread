#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <thread>
#include "iTCPAgent.h"
// #include <semaphore>

class TCPServer
{
public:
    TCPServer();
    TCPServer(TCPServer&& ts);
    ~TCPServer();

    template <class S>
    void run();
    void client_desconnected(int socket_fd);

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
};

#endif