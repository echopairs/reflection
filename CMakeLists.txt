cmake_minimum_required(VERSION 3.5)
project(reflection)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cc 
				 src/reflection_factory.h 
				 src/Message.h 
				 src/Message1.h)
add_executable(reflection ${SOURCE_FILES})
