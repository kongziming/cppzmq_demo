#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <thread>
#include <zmq.hpp>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

using namespace std::chrono_literals;

int main()
{
	std::cout << "Client Starting...\n";

	// �ͻ��˴���REQ socket
	zmq::context_t ctx;
	zmq::socket_t clientSock(ctx, zmq::socket_type::req);
	clientSock.connect("tcp://127.0.0.1:5555");

	while (true)
	{
		// ����Json
		QJsonArray hobbyArray = { "Sing", "Dance", "Rap", "Basketball" };
		QJsonObject jsonObj
		{
			{"name", "SongZuhao"},
			{"age", 38},
			{"hobby", hobbyArray}
		};
		QJsonDocument jsonDoc(jsonObj);
		QByteArray bytes = jsonDoc.toJson();
		int aaa = bytes.size();

		// ������Ϣ��������
		zmq::message_t message(bytes.data(), bytes.size() + 1);
		clientSock.send(message, zmq::send_flags::none);

		// ���մӷ��������ص���Ϣ
		zmq::message_t recvMessage;
		clientSock.recv(recvMessage);
		std::cout << "Sending Json Data..."
			<< "Receive " << recvMessage.to_string() << std::endl;

		std::this_thread::sleep_for(1000ms);
	}

	clientSock.close();
}
