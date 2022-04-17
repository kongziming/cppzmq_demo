add_executable(
	demo02_Request
	Request.cpp
)

add_executable(
	demo02_Reply
	Reply.cpp
)

target_link_libraries(
	demo02_Request
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo02_Reply
	PRIVATE
	cppzmq
)

set_property(TARGET demo02_Request PROPERTY FOLDER "02_req_rep")
set_property(TARGET demo02_Reply PROPERTY FOLDER "02_req_rep")