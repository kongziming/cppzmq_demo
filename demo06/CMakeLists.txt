add_executable(
	demo06_Publisher
	Publisher.cpp
)

add_executable(
	demo06_Subscriber
	Subscriber.cpp
)

target_link_libraries(
	demo06_Publisher
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo06_Subscriber
	PRIVATE
	cppzmq
)