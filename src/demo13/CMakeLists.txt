add_executable(
	demo13_Client
	Client.cpp
)

add_executable(
	demo13_Server
	Server.cpp
)

target_link_libraries(
	demo13_Client
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo13_Server
	PRIVATE
	cppzmq
)