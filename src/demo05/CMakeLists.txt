add_executable(
	demo05_Pull
	Pull.cpp
)

add_executable(
	demo05_Push
	Push.cpp
)

target_link_libraries(
	demo05_Pull
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo05_Push
	PRIVATE
	cppzmq
)

set_property(TARGET demo05_Pull PROPERTY FOLDER "05_pull_push")
set_property(TARGET demo05_Push PROPERTY FOLDER "05_pull_push")