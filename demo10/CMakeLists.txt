add_executable(
	demo10_Server
	Server.cpp
)

add_executable(
	demo10_Client
	Client.cpp
)

target_link_libraries(
	demo10_Server
	PRIVATE
	cppzmq
	Qt5::Core
)

target_link_libraries(
	demo10_Client
	PRIVATE
	cppzmq
	Qt5::Core
)