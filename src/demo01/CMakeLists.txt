project(demo01)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	cppzmq
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "01_version")