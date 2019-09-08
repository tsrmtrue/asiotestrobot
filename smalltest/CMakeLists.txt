cmake_minimum_required(VERSION 3.0)

PROJECT(smalltest)

set(CMAKE_BUILD_TYPE "Debug")

AUX_SOURCE_DIRECTORY(./ SRC_LIST)

IF (WIN32)  
ELSE()
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x -fno-omit-frame-pointer -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free ")

	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS}  -O0 -g ")

	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O1 -g -Werror ")
ENDIF()
INCLUDE_DIRECTORIES( .  )

IF (WIN32)  
ELSE()
    LINK_LIBRARIES( tcmalloc )
ENDIF()  

ADD_EXECUTABLE(smalltest ${SRC_LIST})
