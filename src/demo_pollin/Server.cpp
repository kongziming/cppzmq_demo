#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <thread>
#include <zmq.hpp>
#include <zmq_addon.hpp>

using namespace std::chrono_literals;

int main()
{
    std::cout << "Server Starting...\n";

    zmq::context_t ctx;
    zmq::socket_t sock1(ctx, zmq::socket_type::push);
    zmq::socket_t sock2(ctx, zmq::socket_type::pub);
    sock1.bind("tcp://127.0.0.1:5555");
    sock2.bind("tcp://127.0.0.1:5556");

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 100);// 0到100的随机数

    while (true)
    {
        // 创建随机数
        const int randomNum = dist(mt);

        // 偶数通过Push，奇数通过Publish
        zmq::message_t message(std::to_string(randomNum));
        if (randomNum % 2 == 0)
        {
            sock1.send(message, zmq::send_flags::none);
        }
        else
        {
            sock2.send(message, zmq::send_flags::none);
        }

        std::cout << "Sending " << randomNum << std::endl;

        std::this_thread::sleep_for(200ms);
    }

    return 0;
}