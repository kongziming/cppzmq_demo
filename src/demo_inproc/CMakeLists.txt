add_executable(
	Inproc
	Inproc.cpp
)

target_link_libraries(
	Inproc
	PRIVATE
	cppzmq
)

set_property(TARGET Inproc PROPERTY FOLDER "demo_inproc")