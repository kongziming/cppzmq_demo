add_executable(
	demo07_Publisher
	Publisher.cpp
)

add_executable(
	demo07_Proxy
	Proxy.cpp
)

add_executable(
	demo07_Subscriber
	Subscriber.cpp
)

target_link_libraries(
	demo07_Publisher
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo07_Proxy
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo07_Subscriber
	PRIVATE
	cppzmq
)

set_property(TARGET demo07_Publisher PROPERTY FOLDER "07_pub_sub_proxy")
set_property(TARGET demo07_Proxy PROPERTY FOLDER "07_pub_sub_proxy")
set_property(TARGET demo07_Subscriber PROPERTY FOLDER "07_pub_sub_proxy")