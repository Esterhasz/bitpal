cmake_minimum_required (VERSION 3.10)
cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("include")
project ("bitpal")

file (GLOB_RECURSE SRC_FILES 
	"include/*.h"
	"include/*.hpp"
	"src/*.cpp")

add_executable(bitpal ${SRC_FILES})