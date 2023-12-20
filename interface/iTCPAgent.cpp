#include "iTCPAgent.h"
#include "TCPServer.h"

iTCPAgent::iTCPAgent(int socket_fd, TCPServer *parentServer)
    : socket_fd{socket_fd}, parentServer{parentServer}
{

}

iTCPAgent::~iTCPAgent()
{
    close(socket_fd);
}

iTCPAgent::iTCPAgent(iTCPAgent &&ta)
    : socket_fd{ta.socket_fd}, parentServer{ta.parentServer}
{

}

void iTCPAgent::close_connection(){
    parentServer->client_desconnected(socket_fd);
}