add_executable(
	demo03_Reply
	Reply.cpp
)

add_executable(
	demo03_Request
	Request.cpp
)

target_link_libraries(
	demo03_Request
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo03_Reply
	PRIVATE
	cppzmq
)

set_property(TARGET demo03_Request PROPERTY FOLDER "03_req_rep")
set_property(TARGET demo03_Reply PROPERTY FOLDER "03_req_rep")