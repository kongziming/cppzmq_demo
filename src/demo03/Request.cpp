#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <thread>
#include <zmq.hpp>

using namespace std::chrono_literals;

static zmq::context_t ctx;

auto func = [](std::string threadId)
{
    std::cout << threadId << "Client Starting...\n";

    // 客户端创建REQ socket
    zmq::socket_t clientSock(ctx, zmq::socket_type::req);
    clientSock.connect("tcp://127.0.0.1:5555");

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 100);// 0到100的随机数

    while (true)
    {
        // 创建随机数
        const int randomNum = dist(mt);

        // 发送消息到服务器
        zmq::message_t message(std::to_string(randomNum));
        clientSock.send(message, zmq::send_flags::none);

        // 接收从服务器返回的消息
        zmq::message_t recvMessage;
        clientSock.recv(recvMessage);
        std::cout << threadId <<" Sending: " << randomNum
            << " Received: " << recvMessage.to_string() << std::endl;

        std::this_thread::sleep_for(1000ms);
    }
};


int main()
{
    std::thread thread1 = std::thread(func, "thread1");
    std::thread thread2 = std::thread(func, "thread2");

    thread1.join();
    thread2.join();
}
