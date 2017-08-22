cmake_minimum_required(VERSION 3.8)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LinkedList.cpp LinkedList.h SubSequence.cpp SubSequence.h)
add_executable(LeetCode ${SOURCE_FILES})