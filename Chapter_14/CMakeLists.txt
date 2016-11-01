cmake_minimum_required(VERSION 2.6)
project(Chapter_14)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(use_stuc use_stuc.cpp studentc.cpp)
add_executable(stacktem stacktem.cpp)
add_executable(stckoptr1 stckoptr1.cpp)
add_executable(twod twod.cpp)
add_executable(pairs pairs.cpp)
add_executable(tempmemb tempmemb.cpp)   		#not goign to be covered on the exam

add_executable(use_stui use_stui.cpp studenti.cpp) 	#Not going to be covered on the exam
add_executable(worktest worker0.cpp worktest.cpp)  	#Not going to be covered on the exam
add_executable(workmi workmi.cpp workermi.cpp)		#Not going to be covered on the exam
add_executable(frnd2tmp frnd2tmp.cpp)			#Not going to be covered on the exam	
add_executable(manyfrnd manyfrnd.cpp)			#Not going to be covered on the exam
add_executable(tempparm tempparm.cpp)			#Not going to be covered on the exam