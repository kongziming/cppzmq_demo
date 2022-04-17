# 版本查询
add_subdirectory(demo01)
# Request Reply模式
add_subdirectory(demo02)
# Request Reply模式：用于演示可以有多个Request
add_subdirectory(demo03)
# Exclusive Pair模式
add_subdirectory(demo04)
# Push Pull模式
add_subdirectory(demo05)
# Publish Subscribe模式
add_subdirectory(demo06)
# Publish Subscribe Proxy
add_subdirectory(demo07)
# Dealer Router
add_subdirectory(demo08)

# 通过zmq发送和接收Json数据
if(Qt5Widgets_FOUND)
	add_subdirectory(demo_json)
endif()
# Pollin
add_subdirectory(demo_pollin)
# 通过inproc的方式进行节点连接
add_subdirectory(demo_inproc)
