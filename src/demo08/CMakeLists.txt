add_executable(
	demo08_Dealer
	Dealer.cpp
)

add_executable(
	demo08_Router
	Router.cpp
)

target_link_libraries(
	demo08_Dealer
	PRIVATE
	cppzmq
)

target_link_libraries(
	demo08_Router
	PRIVATE
	cppzmq
)

set_property(TARGET demo08_Dealer PROPERTY FOLDER "08_dealer_router")
set_property(TARGET demo08_Router PROPERTY FOLDER "08_dealer_router")