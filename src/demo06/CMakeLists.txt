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

set_property(TARGET demo06_Publisher PROPERTY FOLDER "06_pub_sub")
set_property(TARGET demo06_Subscriber PROPERTY FOLDER "06_pub_sub")