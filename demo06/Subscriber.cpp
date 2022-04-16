#include <iostream>
#include <string>
#include <chrono>
#include <zmq.hpp>

using namespace std::chrono_literals;

int main()
{
    std::cout << "Subscriber Starting...\n";

    // Subscriber socket
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::sub);
    sock.connect("tcp://127.0.0.1:5555");

    // 订阅主题
    {
        std::string topic = "odd";
        sock.set(zmq::sockopt::subscribe, topic);
    }

    while (true)
    {
        // 接收消息
        zmq::message_t topic;
        zmq::message_t payload;
        sock.recv(topic);
        sock.recv(payload);

        std::cout << "Receive random number: " << payload.to_string() << std::endl;
    }
}
