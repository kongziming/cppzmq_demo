add_executable(
	demo02_Request
	Request.cpp
)

add_executable(
	demo02_Reply
	Reply.cpp
)


target_link_libraries(
	demo02_Reply
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo02_Request
	PRIVATE
	cppzmq
)