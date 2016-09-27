cmake_minimum_required(VERSION 2.6)
project(Chapter_11)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(usetime0 usetime0.cpp mytime.cpp)
add_executable(usetime1 usetime1.cpp mytime1.cpp)
add_executable(usetime2 usetime2.cpp mytime2.cpp)
add_executable(usetime3 usetime3.cpp mytime3.cpp)

add_executable(randwalk randwalk.cpp vect.cpp)

add_executable(stone stone.cpp stonewt.cpp)
add_executable(stone1 stone1.cpp stonewt1.cpp)

install(TARGETS usetime0 RUNTIME DESTINATION bin)
