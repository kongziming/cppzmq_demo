#include <zmq.hpp>
#include <iostream>
#include <random>
#include <string>
#include <thread>

using namespace std::chrono_literals;

static zmq::context_t ctx;

auto func1 = []()
{
    std::cout << "Server Starting...\n";

    // 服务器创建REP sock
    zmq::socket_t serverSock(ctx, zmq::socket_type::rep);
    serverSock.bind("inproc://example");

    while (true)
    {
        // 接收从客户端发来的消息
        zmq::message_t recvMessage;
        serverSock.recv(recvMessage);
        int value = std::stoi(recvMessage.to_string());
        std::cout << "Received " << value << std::endl;
        value = value * value;  // 求平方

        // 发送消息到客户端
        zmq::message_t replyMessage(std::to_string(value));
        serverSock.send(replyMessage, zmq::send_flags::none);
    }
};

auto func2 = []()
{
    std::cout << "Client Starting...\n";

    // 客户端创建REQ socket
    zmq::socket_t clientSock(ctx, zmq::socket_type::req);
    clientSock.connect("inproc://example");

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
        std::cout << "Sending: " << randomNum
            << " Received: " << recvMessage.to_string() << std::endl;

        std::this_thread::sleep_for(1000ms);
    }
};

int main()
{
    std::thread thread1 = std::thread(func1);
    std::thread thread2 = std::thread(func2);

    thread1.join();
    thread2.join();
}
