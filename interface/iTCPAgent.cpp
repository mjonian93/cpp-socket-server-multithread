#include "iTCPAgent.h"
#include "TCPServer.h"

iTCPAgent::iTCPAgent(int socket_fd, TCPServer *parentServer)
    : socket_fd{socket_fd}, parentServer{parentServer}
{

}

iTCPAgent::~iTCPAgent()
{
    client_disconnected();
    close(socket_fd);
}

iTCPAgent::iTCPAgent(iTCPAgent &&ta)
    : socket_fd{ta.socket_fd}, parentServer{ta.parentServer}
{

}

void iTCPAgent::client_disconnected(){
    parentServer->client_desconnected(socket_fd);
}