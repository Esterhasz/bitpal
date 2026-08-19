cmake_minimum_required (VERSION 3.10)
cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("include")
project ("bitpal")

file (GLOB_RECURSE SRC_FILES 
	"include/*.h"
	"include/*.hpp"
	
	"demos/*.hpp"
	"demos/*.h"
	"demos/*.cpp"
)

add_executable(bitpal ${SRC_FILES})

add_custom_command(
    TARGET bitpal POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/content"
            "$<TARGET_FILE_DIR:bitpal>/content"
)