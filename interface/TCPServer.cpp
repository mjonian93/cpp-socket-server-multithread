#include "TCPServer.h"
#include "TCP_exceptions.h"
#include <thread>
#include <utility>

const std::string TCPServer::greeting {"Welcome to t4i socket server!"};
const int TCPServer::PORT {5000};
const int TCPServer::OPTED {1};
const int TCPServer::MAX_CLIENTS {3};

TCPServer::TCPServer()
    :done {false}, sem{TCPServer::MAX_CLIENTS}
{

}

TCPServer::~TCPServer()
{
    //Forcefully kill all threads
    // for (std::thread &thread : tcp_clients)
        // thread.terminate();
}

TCPServer::TCPServer(TCPServer&& ts) 
    :done {false}, sem{TCPServer::MAX_CLIENTS}
{

}

void TCPServer::client_desconnected(int socket_fd)
{
    auto it = tcp_clients.find(socket_fd);
    if (it != tcp_clients.end())
    {
        delete it->second.first;
        tcp_clients.erase(it);
    }

}

template <class S>
void TCPServer::run() 
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
    
    while(!done) {
        sem.acquire();
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0)
            throw AcceptFailedException();
        iTCPAgent *ta = new S(new_socket, this); 
        std::thread new_client {&iTCPAgent::run, ta};
        tcp_clients.insert({new_socket, std::make_pair(std::move(ta), std::move(new_client))});

        //Any max client limitation strategy goes here
    }
}