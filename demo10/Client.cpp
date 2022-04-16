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

	// 客户端创建REQ socket
	zmq::context_t ctx;
	zmq::socket_t clientSock(ctx, zmq::socket_type::req);
	clientSock.connect("tcp://127.0.0.1:5555");

	while (true)
	{
		// 创建Json
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

		// 发送消息到服务器
		zmq::message_t message(bytes.data(), bytes.size() + 1);
		clientSock.send(message, zmq::send_flags::none);

		// 接收从服务器返回的消息
		zmq::message_t recvMessage;
		clientSock.recv(recvMessage);
		std::cout << "Sending Json Data..."
			<< "Receive " << recvMessage.to_string() << std::endl;

		std::this_thread::sleep_for(1000ms);
	}

	clientSock.close();
}
