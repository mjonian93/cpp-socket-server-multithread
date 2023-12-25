#include "TCPServer.h"

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
        
}

TCPServer::TCPServer(TCPServer&& ts) 
    :done {false}, sem{TCPServer::MAX_CLIENTS}
{

}

void TCPServer::client_desconnected(int socket_fd)
{
    sem.release();
}