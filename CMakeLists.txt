cmake_minimum_required(VERSION 3.10.0)

# 查找vcpkg，必须写在project命令之前
set(VCPKG_ROOT "" CACHE PATH "")
if(NOT EXISTS ${VCPKG_ROOT}/.vcpkg-root)
	message(FATAL_ERROR "请指定VCPKG根目录")
endif()
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(ZeroMQ_Demo)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

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

# 查找cppzmq
find_package(cppzmq CONFIG REQUIRED)

# 查找Qt
option(USE_QT "Whether or not use qt" OFF)
if(USE_QT)
	find_package(Qt5 COMPONENTS Core Widgets)
endif()

add_subdirectory(src)
