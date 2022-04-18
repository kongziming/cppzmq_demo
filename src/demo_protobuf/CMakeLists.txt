add_executable(
	Proto_Client
	Client.cpp
	info.pb.h
	info.pb.cc
)

add_executable(
	Proto_Server
	Server.cpp
	info.pb.h
	info.pb.cc
)

target_link_libraries(
	Proto_Client
	PRIVATE
	cppzmq
	protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite
)

target_link_libraries(
	Proto_Server
	PRIVATE
	cppzmq
	protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite
)

set_property(TARGET Proto_Client PROPERTY FOLDER "demo_protobuf")
set_property(TARGET Proto_Server PROPERTY FOLDER "demo_protobuf")