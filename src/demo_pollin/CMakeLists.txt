add_executable(
	Pollin_Client
	Client.cpp
)

add_executable(
	Pollin_Server
	Server.cpp
)

target_link_libraries(
	Pollin_Client
	PRIVATE
	cppzmq
)

target_link_libraries(
	Pollin_Server
	PRIVATE
	cppzmq
)

set_property(TARGET Pollin_Client PROPERTY FOLDER "demo_pollin")
set_property(TARGET Pollin_Server PROPERTY FOLDER "demo_pollin")