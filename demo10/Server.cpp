#include <zmq.hpp>
#include <iostream>
#include <string>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

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

        // 解析接收到的Json数据
        QByteArray bytes = static_cast<char*>(recvMessage.data());
        QJsonDocument jsonDoc = QJsonDocument::fromJson(bytes);
        if (!jsonDoc.isObject())
        {
	        continue;
        }
        QJsonObject jsonObj = jsonDoc.object();
        QString name = jsonObj.value("name").toString();
        int age = jsonObj.value("age").toInt();
        QJsonArray hobbyArray = jsonObj.value("hobby").toArray();
        std::cout << "name:" << name.toStdString() << " age:" << age;
        std::cout << " hobby:";
        for (int i = 0; i < hobbyArray.size(); ++i)
        {
            std::cout << hobbyArray[i].toString().toStdString() << " ";
        }
        std::cout << std::endl;

        // 发送消息到客户端
        zmq::message_t replyMessage(name);
        serverSock.send(replyMessage, zmq::send_flags::none);
    }

    serverSock.close();

    return 0;
}
