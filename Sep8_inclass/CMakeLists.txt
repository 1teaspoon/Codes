cmake_minimum_required(VERSION 2.6)
project(sep8_inclass)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sep8_inclass main.cpp)

install(TARGETS sep8_inclass RUNTIME DESTINATION bin)
