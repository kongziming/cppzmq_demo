set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(
	Json_Client
	Client.cpp
)

add_executable(
	Json_Server
	Server.cpp
)

target_link_libraries(
	Json_Client
	PRIVATE
	cppzmq
	Qt5::Core
)

target_link_libraries(
	Json_Server
	PRIVATE
	cppzmq
	Qt5::Core
)

set_property(TARGET Json_Client PROPERTY FOLDER "demo_json")
set_property(TARGET Json_Server PROPERTY FOLDER "demo_json")