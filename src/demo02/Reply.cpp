#include <zmq.hpp>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Server Starting...\n";

    // 服务器创建REP sock
    zmq::context_t ctx;
    zmq::socket_t serverSock(ctx, zmq::socket_type::rep);
    serverSock.bind("tcp://127.0.0.1:5555");

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

    return 0;
}
