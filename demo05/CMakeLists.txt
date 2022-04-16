add_executable(
	demo04_Pull
	Pull.cpp
)

add_executable(
	demo04_Push
	Push.cpp
)

target_link_libraries(
	demo04_Pull
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo04_Push
	PRIVATE
	cppzmq
)