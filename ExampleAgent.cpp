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
    bool done = false;
    int result;
    size_t bytesRead {15};
    char *buffer = new char [bytesRead];
    std::cout << "New client handler running." << std::endl;
    while(!done)
    {
        result = read(socket_fd, buffer, bytesRead);
        std::cout << "post-read" << std::endl;
        if (result > 0)
            std::cout << buffer << std::endl;

        if (std::strcmp(buffer, "close") == 0)
            done = true;
    }

    close_connection();
}