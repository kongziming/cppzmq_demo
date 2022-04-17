

![logo](./images/logo.gif)

# ZeroMQ

## 消息传递模式

ZeroMQ的消息模式是通过一对类型相匹配的套接字实现的。

内置模式的有：

- Request-Reply：将一组客户端连接到一组服务器。这是一个远程过程调用和任务分发模式。
- Publish-Subscribe：将一组发布者连接到一组订阅者，是一种数据分布模式。
- Pipeline：以扇入/扇出方式连接各节点，是一个并行任务分发和收集的模式。
- Exclusive Pair：以互斥的方式连接两个套接字。

除此之外，还有很多可扩展的模式，下面将详细说明。

### Request Reply

<img src="./images/req_rep.jpg" alt="req_rep" style="zoom: 50%;" />

请求-回复模式

客户端向服务器发出请求之后，必须要等待服务器的回复，否则会出错。

### Exclusive Pair

这种模式下，客户端向服务器发出请求，不需要等待。

但这种情况下，pair是互斥的，只能有一个pair与另一个pair建立连接，不能有第三者出现。

### Push Pull

<img src="./images/push_pull.jpg" alt="push_pull" style="zoom:50%;" />

推拉模式，也叫管道模式。

这种模式下数据是顺流而下的，push socket无法接收数据。

消息是公平队列

### Publish Subscribe

<img src="./images/pub_sub.jpg" alt="pub_sub" style="zoom: 50%;" />

所有订阅者都会收到消息

之前未收到的消息将不会再收到

需要订阅主题

如果不订阅主题，则不会收到任何消息；

如果订阅空字符串主题，则会收到所有消息；

可订阅多个主题，会收到这些主题的消息；

运行中可随时订阅/取消订阅主题。

### Publish Subscribe Proxy

<img src="./images/pub_sub_proxy.jpg" alt="pub_sub_proxy" style="zoom:50%;" />

### Dealer Router

Dealer像是一个异步的Request套接字；

Router像是一个异步的Reply套接字。

router套接字为它的每个连接分配一个默认的标识符，

----

