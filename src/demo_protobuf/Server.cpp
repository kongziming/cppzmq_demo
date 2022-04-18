#include <zmq.hpp>
#include <iostream>
#include <string>
#include "info.pb.h"

int main()
{
    std::cout << "Server Starting...\n";

    // 服务器创建REP sock
    zmq::context_t ctx;
    zmq::socket_t serverSock(ctx, zmq::socket_type::pair);
    serverSock.bind("tcp://127.0.0.1:5555");

    while (true)
    {
        // 接收从客户端发来的消息
        zmq::message_t recvMessage;
        serverSock.recv(recvMessage);

        // 解析接收到的消息
        Info userInfo;
        userInfo.ParseFromArray(recvMessage.data(), recvMessage.size());

        std::cout << "Received:" << std::endl;
        std::cout << "name: " << userInfo.name() << std::endl;
        std::cout << "age: " << userInfo.age() << std::endl;
        std::cout << "hobby: ";
        for (int i = 0; i < userInfo.hobby_size(); ++i)
        {
            std::string hobbyItem = userInfo.hobby(i);
            std::cout << hobbyItem << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
