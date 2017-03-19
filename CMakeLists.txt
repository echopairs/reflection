cmake_minimum_required(VERSION 3.5)
project(message)

set(CMAKE_CXX_STANDARD 11)



set(SOURCE_FILES src/reflection_factory.h
				 src/Message.h 
				 src/Message1.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

enable_testing ()
ADD_SUBDIRECTORY (tests)