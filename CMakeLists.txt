cmake_minimum_required(VERSION 3.1)

project(gagaserver)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Wextra -pedantic -g")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

include_directories("src/external")


file(GLOB SRC
	"src/*.h"
	"src/*.hpp"
	)

find_package(ZMQ REQUIRED)
find_package(Boost REQUIRED)

set(EXE gagaserver)
add_executable(${EXE} ${SRC} src/main.cpp)
target_include_directories(${EXE} PUBLIC ${ZeroMQ_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
target_link_libraries(${EXE} PUBLIC ${ZeroMQ_LIBRARIES})
