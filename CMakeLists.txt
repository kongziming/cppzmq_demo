cmake_minimum_required(VERSION 3.10.0)

set(VCPKG_ROOT "" CACHE PATH "")
if(NOT EXISTS ${VCPKG_ROOT}/.vcpkg-root)
	message(FATAL_ERROR "请指定VCPKG根目录")
endif()
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(ZMQDemo)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 设置库和可执行文件的输出文件
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_RELWITHDEBINFO_POSTFIX rd)
set(CMAKE_MINSIZEREL_POSTFIX s)

if(WIN32)
    if(MSVC)
		option(WIN32_USE_MP "Set to ON to build with the /MP option" ON)
        mark_as_advanced(WIN32_USE_MP)
        if(WIN32_USE_MP)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
        endif()
	endif()
else()
	if(UNIX)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	endif()
endif()

find_package(cppzmq CONFIG REQUIRED)

# 查找Qt的库
if(CMAKE_SYSTEM MATCHES "Windows")
	# VS2015及以后使用Qt5
	if(MSVC_VERSION GREATER_EQUAL 1900)
		set(QT_VERSION "5" CACHE STRING "Qt Version")
	# VS2010使用Qt4
	else()
		set(QT_VERSION "4" CACHE STRING "Qt Version")
	endif()
else()
	set(QT_VERSION "5" CACHE STRING "Qt Version")
endif()
set_property(CACHE QT_VERSION PROPERTY STRINGS 4 5)
if(QT_VERSION VERSION_GREATER "4")
	find_package(Qt5 COMPONENTS Core Widgets Xml Network OpenGL)
else()
	find_package(Qt4)
endif()

# 版本查询
add_subdirectory(demo01)
# Request Reply模式
add_subdirectory(demo02)
# Request Reply模式：用于演示可以有多个Request
add_subdirectory(demo03)
# 互斥Pair模式
add_subdirectory(demo04)
# Push Pull模式
add_subdirectory(demo05)
# Publish Subscribe模式
add_subdirectory(demo06)
# Dealer Router模式
add_subdirectory(demo07)
# 通过zmq发送和接收Json数据
add_subdirectory(demo10)
