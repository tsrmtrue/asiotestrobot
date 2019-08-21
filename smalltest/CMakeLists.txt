cmake_minimum_required(VERSION 3.0)

PROJECT(smalltest)

AUX_SOURCE_DIRECTORY(./ SRC_LIST)

IF (WIN32)  
ELSE()
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x -fno-omit-frame-pointer ")

	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -D_DEBUG -DDEBUG -O0 -g  -Wno-unused -Wno-unused-function -Wno-unused-variable -Wno-invalid-offsetof -Wno-sign-compare ")

	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -D_DEBUG -DDEBUG -DDNA_LIVE_ENV -O1 -g -Werror -Wno-unused -Wno-unused-function -Wno-unused-variable -Wno-invalid-offsetof -Wno-sign-compare ")
ENDIF()
INCLUDE_DIRECTORIES( .  )

IF (WIN32)  
ELSE()
    LINK_LIBRARIES(  )
ENDIF()  

ADD_EXECUTABLE(smalltest ${SRC_LIST})
