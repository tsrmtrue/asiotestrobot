cmake_minimum_required(VERSION 3.0)

PROJECT(smalltest)

set(CMAKE_BUILD_TYPE "Release")


IF (WIN32)  
ELSE()
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x -fno-omit-frame-pointer -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free ")

	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS}  -O0 -g ")

	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -g -Werror ")
ENDIF()
INCLUDE_DIRECTORIES( .  )
INCLUDE_DIRECTORIES( ../AESever/common  )


AUX_SOURCE_DIRECTORY(./ SRC_LIST)
AUX_SOURCE_DIRECTORY(../AESever/common SRC_LIST)

IF (WIN32)  
ELSE()
    LINK_LIBRARIES( tcmalloc )
ENDIF()  

ADD_EXECUTABLE(smalltest ${SRC_LIST})
