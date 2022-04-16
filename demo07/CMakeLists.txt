add_executable(
	demo07_Dealer
	Dealer.cpp
)

add_executable(
	demo07_Router
	Router.cpp
)

target_link_libraries(
	demo07_Dealer
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo07_Router
	PRIVATE
	cppzmq
)