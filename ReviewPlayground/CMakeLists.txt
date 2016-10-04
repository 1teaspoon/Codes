cmake_minimum_required(VERSION 2.6)
project(reviewplayground)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(reviewplayground main.cpp)

install(TARGETS reviewplayground RUNTIME DESTINATION bin)
