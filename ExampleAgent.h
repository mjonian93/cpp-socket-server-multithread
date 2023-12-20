#ifndef T4IAGENT_H
#define T4IAGENT_H

#include "interface/iTCPAgent.h"

class ExampleAgent : public iTCPAgent
{
public:
    ExampleAgent(int socket_fd, TCPServer *parentServer);
    ~ExampleAgent();
    ExampleAgent(ExampleAgent &&ta);
    virtual void run() override;

private:

};

#endif