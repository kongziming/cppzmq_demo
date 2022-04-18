#include <iostream>
#include <chrono>
#include <thread>
#include <zmq.hpp>
#include "info.pb.h"

using namespace std::chrono_literals;

int main()
{
    std::cout << "Client Starting...\n";

    // 客户端创建REQ socket
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::pair);
    sock.connect("tcp://127.0.0.1:5555");

    while (true)
    {
        Info userInfo;
        userInfo.set_name("宋祖浩");
        userInfo.set_age(38);
        userInfo.add_hobby("Sing");
        userInfo.add_hobby("Dance");
        userInfo.add_hobby("Rap");
        userInfo.add_hobby("Basketball");

        // 发送消息到服务器
        size_t bytes = userInfo.ByteSizeLong();
        zmq::message_t message(bytes);
        userInfo.SerializeToArray(message.data(), bytes);
        sock.send(message, zmq::send_flags::none);

        std::this_thread::sleep_for(1000ms);
    }
}
