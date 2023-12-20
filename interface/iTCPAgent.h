#ifndef TCPAGENT_H
#define TCPAGENT_H

#include <sys/socket.h>
#include <unistd.h>
#include "../../share/mailbox.h"
#include "../../share/mark_buffer.h"
#include "../../share/command.h"

class TCPServer;

class iTCPAgent
{
public:
    iTCPAgent(int socket_fd, TCPServer *parentServer);
    virtual ~iTCPAgent();
    iTCPAgent(iTCPAgent &&ta);

    virtual void run() = 0;
    void close_connection();

private:
    int socket_fd;
    TCPServer *parentServer;
};

#endif