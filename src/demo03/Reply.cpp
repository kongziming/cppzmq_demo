#include <zmq.hpp>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Server Starting...\n";

    // ����������REP sock
    zmq::context_t ctx;
    zmq::socket_t serverSock(ctx, zmq::socket_type::rep);
    serverSock.bind("tcp://127.0.0.1:5555");

    while (true)
    {
        // ���մӿͻ��˷�������Ϣ
        zmq::message_t recvMessage;
        serverSock.recv(recvMessage);
        int value = std::stoi(recvMessage.to_string());
        std::cout << "Received " << value << std::endl;
        value = value * value;  // ��ƽ��

        // ������Ϣ���ͻ���
        zmq::message_t replyMessage(std::to_string(value));
        serverSock.send(replyMessage, zmq::send_flags::none);
    }

    return 0;
}
