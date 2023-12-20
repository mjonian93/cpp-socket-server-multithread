#include "TCPServer.h"
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
    sem.release();
    auto it = tcp_clients.find(socket_fd);
    if (it != tcp_clients.end())
    {
        delete it->second.first;
        tcp_clients.erase(it);
    }

}