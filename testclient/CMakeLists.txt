cmake_minimum_required(VERSION 3.0)

PROJECT(robotclient)

add_compile_options(-std=c++11)

FILE(GLOB_RECURSE SRC_LIST *.cpp)
AUX_SOURCE_DIRECTORY(../common SRC_LIST)


IF (WIN32)  
ELSE()
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x -fno-omit-frame-pointer ")
	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -D_DEBUG -DDEBUG -O0 -g -Werror -Wno-unused -Wno-unused-function -Wno-unused-variable -Wno-invalid-offsetof -Wno-sign-compare ")
	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -D_DEBUG -DDEBUG -DDNA_LIVE_ENV -O1 -g -Werror -Wno-unused -Wno-unused-function -Wno-unused-variable -Wno-invalid-offsetof -Wno-sign-compare ")
ENDIF()  


INCLUDE_DIRECTORIES( .  )
INCLUDE_DIRECTORIES( ../common)

INCLUDE_DIRECTORIES(../asio-1.10.8/include )

ADD_DEFINITIONS(-DASIO_STANDALONE)
ADD_DEFINITIONS(-DASIO_HAS_STD_CHRONO)

#behaviac 
INCLUDE_DIRECTORIES(../behaviac_3.6/inc )
INCLUDE_DIRECTORIES( ../common/behaviac_generated)
INCLUDE_DIRECTORIES( ../common/behaviac_generated/behaviors)
AUX_SOURCE_DIRECTORY(../common/behaviac_generated/behaviors SRC_LIST)
AUX_SOURCE_DIRECTORY(../common/behaviac_generated/types/internal SRC_LIST)
IF (WIN32)  
    LINK_LIBRARIES( libbehaviac_msvc_debug )
ELSE()
ENDIF()  
LINK_DIRECTORIES( ../behaviac_3.6/bin )
#behaviac 





IF (WIN32)  
ELSE()
    LINK_LIBRARIES( pthread )
ENDIF()  

ADD_EXECUTABLE(robotclient ${SRC_LIST})
