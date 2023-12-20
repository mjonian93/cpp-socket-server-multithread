#ifndef T4IAGENT_H
#define T4IAGENT_H

#include "interface/iTCPAgent.h"

class t4iAgent : public iTCPAgent
{
public:
    t4iAgent(int socket_fd, TCPServer *parentServer);
    ~t4iAgent();
    t4iAgent(t4iAgent &&ta);
    virtual void run() override;

private:

};

#endif