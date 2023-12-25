#include "ExampleAgent.h"
#include "interface/TCPServer.h"
#include "interface/iTCPAgent.h"
#include <cstring>
#include <unistd.h>
#include <iostream>

ExampleAgent::ExampleAgent(int socket_fd, TCPServer *parentServer)
    : iTCPAgent(socket_fd, parentServer)
{

}

ExampleAgent::~ExampleAgent()
{

}

ExampleAgent::ExampleAgent(ExampleAgent &&ta)
    : iTCPAgent(std::move(ta))
{

}

void ExampleAgent::run() {
    // int result;
    size_t bytesRead {15};
    char *buffer = new char [bytesRead];
    std::cout << "New client handler running." << std::endl;

    while(recv(socket_fd, buffer, bytesRead, 0) > 0)
    {
        std::cout << buffer << std::endl;
    }

    std::cout << "Client disconnected. Thread terminated." << std::endl;

    //This delete is mandatory to avoid memory leaks.
    delete this;
}