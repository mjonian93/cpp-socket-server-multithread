#include "t4iAgent.h"
#include "interface/TCPServer.h"
#include "interface/iTCPAgent.h"
#include <unistd.h>

t4iAgent::t4iAgent(int socket_fd, TCPServer *parentServer)
    : iTCPAgent(socket_fd, parentServer)
{

}

t4iAgent::~t4iAgent()
{

}

t4iAgent::t4iAgent(t4iAgent &&ta)
    : iTCPAgent(std::move(ta))
{

}

void t4iAgent::run() {

    while(true)
    {

    }

    close_connection();
}