#include <iostream>
#include <string>
#include <chrono>
#include <zmq.hpp>
#include <zmq_addon.hpp>

using namespace std::chrono_literals;

int main()
{
    std::cout << "Router Starting...\n";

    // Router socket
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::router);
    sock.bind("tcp://127.0.0.1:5555");

    while (true)
    {
        // 接收消息
        std::vector<zmq::message_t> vecMessage;
        zmq::recv_result_t res = zmq::recv_multipart(sock, std::back_inserter(vecMessage));
        if (res.has_value())
        {
            std::cout << "\n-----------\ntrue";
        }

        for (auto&& msg: vecMessage)
        {
            std::cout << "\n" << msg;
        }
    }
}
