cmake_minimum_required(VERSION 2.6)
project(reviewplayground)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pointer pointer.cpp)
add_executable(cubes cubes.cpp)
add_executable(use_new use_new.cpp)
add_executable(arrfun4 arrfun4.cpp)
add_executable(vegnewsGOOD vegnewsSTR_GOOD.cpp string1.cpp)
add_executable(vegnewsBAD vegnewsSTRBAD.cpp strngbad.cpp )


