cmake_minimum_required(VERSION 2.6)
project(Chapter_11)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vegnews vegnews.cpp strngbad.cpp)



install(TARGETS vegnews RUNTIME DESTINATION bin)
