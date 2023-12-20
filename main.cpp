#include <thread>
#include <iostream>
#include "interface/TCPServer.h"
#include "ExampleAgent.h"


int main()
{

    TCPServer ts;
    std::unique_ptr<std::thread> comm_thread;

    try {
        comm_thread = std::make_unique<std::thread>(&TCPServer::run<ExampleAgent>, &ts);
        // comm_thread = std::make_unique<std::thread>(TCPServer()); //std::thread tcp_server(TCPServer()/*, params*/);
    }
    catch (std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

}