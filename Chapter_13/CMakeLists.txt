cmake_minimum_required(VERSION 2.6)
project(Chapter_11)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(usett0 usett0.cpp tabtenn0.cpp)
add_executable(usett1 usett1.cpp tabtenn1.cpp)
add_executable(usedma usedma.cpp dma.cpp)
add_executable(usebrass1 usebrass1.cpp brass.cpp )
add_executable(usebrass2 usebrass2.cpp brass.cpp )
add_executable(usebrass3 usebrass3.cpp acctabc.cpp )