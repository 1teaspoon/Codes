cmake_minimum_required(VERSION 2.6)
project(Chapter_12)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bank bank.cpp queue.cpp)
add_executable(placenew1 placenew1.cpp)
add_executable(placenew2 placenew2.cpp )
add_executable(sayings1 sayings1.cpp string1.cpp )
add_executable(sayings2 sayings2.cpp string1.cpp )
add_executable(vegnews vegnews.cpp strngbad.cpp )