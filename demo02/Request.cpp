#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <thread>
#include <zmq.hpp>

using namespace std::chrono_literals;

int main()
{
    std::cout << "Client Starting...\n";

    // �ͻ��˴���REQ socket
    zmq::context_t ctx;
    zmq::socket_t clientSock(ctx, zmq::socket_type::req);
    clientSock.connect("tcp://127.0.0.1:5555");

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 100);// 0��100�������

    while (true)
    {
        // ���������
        const int randomNum = dist(mt);

        // ������Ϣ��������
        zmq::message_t message(std::to_string(randomNum));
        clientSock.send(message, zmq::send_flags::none);

        // ���մӷ��������ص���Ϣ
        zmq::message_t recvMessage;
        clientSock.recv(recvMessage);
        std::cout << "Sending: " << randomNum
            << " Received: " << recvMessage.to_string() << std::endl;

        std::this_thread::sleep_for(1000ms);
    }
}
