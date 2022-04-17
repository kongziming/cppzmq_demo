#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <thread>
#include <zmq.hpp>

using namespace std::chrono_literals;

int main()
{
    std::cout << "Pull Starting...\n";

    // Pull socket
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::pull);
    sock.connect("tcp://127.0.0.1:5555");

    while (true)
    {
        // 接收消息
        zmq::message_t message;
        sock.recv(message);

        std::cout << "Receive random number: " << message.to_string() << std::endl;
    }
}
