cmake_minimum_required(VERSION 2.6)
project(HW02)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HW02 main.cpp complex.cpp lodepng.cpp)

install(TARGETS HW02 RUNTIME DESTINATION bin)
