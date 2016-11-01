cmake_minimum_required(VERSION 2.6)
project(usevalarray)

add_executable(usevalarray main.cpp)

install(TARGETS usevalarray RUNTIME DESTINATION bin)
