cmake_minimum_required(VERSION 2.6)
project(Chapter_10)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(usestock00 usestok0.cpp stock00.cpp)
add_executable(usestock10 usestok1.cpp stock10.cpp)
add_executable(usestock20 usestok2.cpp stock20.cpp)
add_executable(stacker stacker.cpp stack.cpp)

install(TARGETS usestock00 RUNTIME DESTINATION bin)
