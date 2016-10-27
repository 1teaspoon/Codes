cmake_minimum_required(VERSION 2.6)
project(classes_01)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cc Student.cc Class.cc MITPerson.cc)

