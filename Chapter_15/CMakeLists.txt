cmake_minimum_required(VERSION 2.6)
project(Chapter_15)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#Friends
add_executable(use_tv use_tv.cpp tv.cpp)
add_executable(use_tvfm use_tvfm.cpp tv.cpp)

#Nested Classes
add_executable(nested nested.cpp) 	#Not going to be covered on the exam

#Exception and error handling
add_executable(error1 error1.cpp)
add_executable(error2 error2.cpp)
add_executable(error3 error3.cpp)
add_executable(error4 error4.cpp)
add_executable(error5 error5.cpp)
add_executable(newexcp newexcp.cpp)
add_executable(use_sales use_sales.cpp sales.cpp )

add_executable(newexcpn newexcpn.cpp)	#Not going to be covered on the exam
add_executable(rtti1 rtti1.cpp)		#Not going to be covered on the exam
add_executable(rtti2 rtti2.cpp)		#Not going to be covered on the exam


