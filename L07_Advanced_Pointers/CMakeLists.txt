cmake_minimum_required(VERSION 2.6)
project(l07_advanced_poitners)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(l07_advanced_pointers main.cpp)

install(TARGETS l07_advanced_pointers RUNTIME DESTINATION bin)
