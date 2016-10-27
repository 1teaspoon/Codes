cmake_minimum_required(VERSION 2.6)
project(classes_01)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(simulation simulation.cc Virus.cc Patient.cc)