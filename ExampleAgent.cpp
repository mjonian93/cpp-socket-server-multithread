#include "ExampleAgent.h"
#include "interface/TCPServer.h"
#include "interface/iTCPAgent.h"
#include <unistd.h>

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

    while(true)
    {

    }

    close_connection();
}