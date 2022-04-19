add_executable(
	Pollin_Client
	Client.cpp
)
add_executable(
	Pollin_Client1
	Client1.cpp
)
add_executable(
	Pollin_Client2
	Client2.cpp
)
add_executable(
	Pollin_Client3
	Client3.cpp
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
	Pollin_Client1
	PRIVATE
	cppzmq
)
target_link_libraries(
	Pollin_Client2
	PRIVATE
	cppzmq
)
target_link_libraries(
	Pollin_Client3
	PRIVATE
	cppzmq
)

target_link_libraries(
	Pollin_Server
	PRIVATE
	cppzmq
)

set_property(TARGET Pollin_Client PROPERTY FOLDER "demo_pollin")
set_property(TARGET Pollin_Client1 PROPERTY FOLDER "demo_pollin")
set_property(TARGET Pollin_Client2 PROPERTY FOLDER "demo_pollin")
set_property(TARGET Pollin_Client3 PROPERTY FOLDER "demo_pollin")
set_property(TARGET Pollin_Server PROPERTY FOLDER "demo_pollin")