#include <zmq.hpp>
#include <iostream>
#include <random>
#include <string>
#include <thread>

using namespace std::chrono_literals;

int main()
{
    std::cout << "Dealer Starting...\n";

    // Dealer socket
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::dealer);
    // ��Ϊsocket�ֶ�ָ��һ����ʶ�� begin
    //std::string customIdentity = "angelababy";
    //sock.set(zmq::sockopt::routing_id, customIdentity);
    // ��Ϊsocket�ֶ�ָ��һ����ʶ�� end
    sock.connect("tcp://127.0.0.1:5555");

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 100);// 0��100�������

    while (true)
    {
        // ���������
        const int randomNum = dist(mt);

        // ������Ϣ
        zmq::message_t message(std::to_string(randomNum));
        sock.send(message, zmq::send_flags::none);

        std::cout << "Sending ramdom number " << randomNum << std::endl;

        std::this_thread::sleep_for(1000ms);
    }

    return 0;
}
