add_executable(
	demo04_Pair1
	Pair1.cpp
)

add_executable(
	demo04_Pair2
	Pair2.cpp
)

target_link_libraries(
	demo04_Pair1
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo04_Pair2
	PRIVATE
	cppzmq
)

set_property(TARGET demo04_Pair1 PROPERTY FOLDER "04_pair")
set_property(TARGET demo04_Pair2 PROPERTY FOLDER "04_pair")