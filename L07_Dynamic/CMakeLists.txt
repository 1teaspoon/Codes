cmake_minimum_required(VERSION 2.6)
project(l07_dynamic)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(l07_dynamic main.cpp)

install(TARGETS l07_dynamic RUNTIME DESTINATION bin)
