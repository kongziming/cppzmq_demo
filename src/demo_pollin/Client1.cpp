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

    while (true)
    {
        zmq::message_t message1;
        zmq::recv_result_t ret1 = sock1.recv(message1);
        if (ret1.has_value())
        {
            std::cout << message1.to_string() << std::endl;
        }

        zmq::message_t message2;
        zmq::recv_result_t ret2 = sock2.recv(message2);
        if (ret2.has_value())
        {
            std::cout << message2.to_string() << std::endl;
        }
    }

    return 0;
}
