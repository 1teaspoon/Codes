cmake_minimum_required(VERSION 2.6)
project(l08_misc_functions)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(l08_misc_functions main.cpp)

install(TARGETS l08_misc_functions RUNTIME DESTINATION bin)
