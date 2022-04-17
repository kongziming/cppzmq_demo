#include <zmq.hpp>
#include <iostream>
#include <random>
#include <string>
#include <thread>

using namespace std::chrono_literals;

int main()
{
    std::cout << "Client Starting...\n";

    zmq::context_t ctx;
    zmq::socket_t sock1(ctx, zmq::socket_type::pull);
    zmq::socket_t sock2(ctx, zmq::socket_type::sub);
    sock1.connect("tcp://127.0.0.1:5555");
    sock2.connect("tcp://127.0.0.1:5556");
    sock2.set(zmq::sockopt::subscribe, "");
    zmq::pollitem_t items[] = {
        {sock1, 0, ZMQ_POLLIN, 0},
        {sock2, 0, ZMQ_POLLIN, 0},
    };

    while (true)
    {
        zmq::poll(items, 2);

        if (items[0].revents)
        {
            zmq::message_t message1;
            sock1.recv(message1, zmq::recv_flags::dontwait);
            std::cout << "\n" << message1.to_string();
        }

        if (items[1].revents)
        {
            zmq::message_t message2;
            sock2.recv(message2, zmq::recv_flags::dontwait);
            std::cout << "\n" << message2.to_string();
        }
    }

    return 0;
}
