#include <iostream>
#include <chrono>
#include <zmq.hpp>

using namespace std::chrono_literals;

int main()
{
    std::cout << "Proxy Starting...\n";

    zmq::context_t ctx;
    zmq::socket_t frontend(ctx, zmq::socket_type::xsub);
    frontend.bind("tcp://127.0.0.1:5555");
    zmq::socket_t backend(ctx, zmq::socket_type::xpub);
    backend.bind("tcp://127.0.0.1:5556");

    zmq::proxy(frontend, backend);
}
