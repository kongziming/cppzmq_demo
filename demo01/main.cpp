#include <zmq.hpp>

int main(int argc, char* argv[])
{
	int major, minor, patch;
	zmq::version(&major, &minor, &patch);
	printf("current ZMQ version is %d.%d.%d", major, minor, patch);
}
