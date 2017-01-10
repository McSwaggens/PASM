cmake_minimum_required(VERSION 3.0)
project(pasm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(pasm ${SOURCES})
