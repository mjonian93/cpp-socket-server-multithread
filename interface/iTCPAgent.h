#ifndef TCPAGENT_H
#define TCPAGENT_H

#include <sys/socket.h>
#include <unistd.h>

class TCPServer;

class iTCPAgent
{
public:
    iTCPAgent(int socket_fd, TCPServer *parentServer);
    virtual ~iTCPAgent();
    iTCPAgent(iTCPAgent &&ta);

    virtual void run() = 0;
    void close_connection();

protected:
    int socket_fd;
private:
    TCPServer *parentServer;
};

#endif