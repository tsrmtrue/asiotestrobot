function(assign_source_group)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${PROJECT_SOURCE_DIR}" "${_source}")
        else()
            set(_source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
		
		string(SUBSTRING "${_source_path}" "0" "3" _arg_sub_sting)
		string(COMPARE EQUAL "${_arg_sub_sting}" "../" _tmp)
		while(_tmp)
			string(SUBSTRING "${_source_path}" "3" "100" _source_path)
			string(SUBSTRING "${_source_path}" "0" "3" _arg_sub_sting)
			string(COMPARE EQUAL "${_arg_sub_sting}" "../" _tmp)
		endwhile()
		
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
		
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
endfunction(assign_source_group)

function(my_add_executable)
    foreach(_source IN ITEMS ${ARGN})
        assign_source_group(${_source})
    endforeach()
    add_executable(${ARGV})
endfunction(my_add_executable)

cmake_minimum_required(VERSION 3.0)

PROJECT(robotclient)



set(BUILD_USE_64BITS on)
IF (WIN32)  
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj ")

ELSE()
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 ")
	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -D_DEBUG -DDEBUG -O0 -g")
	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2  -fno-omit-frame-pointer")

	set(CMAKE_BUILD_TYPE "Release")

ENDIF()  



set( CMAKE_USE_RELATIVE_PATHS on)

#asio需要定义宏来避免使用boost
ADD_DEFINITIONS(-DASIO_STANDALONE)
ADD_DEFINITIONS(-DASIO_HAS_STD_CHRONO)
ADD_DEFINITIONS(-DCURL_STATICLIB)
ADD_DEFINITIONS(-DFOR_SERVER)



SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../lib)
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})
LINK_DIRECTORIES(../behaviac3.6.39/lib)
LINK_DIRECTORIES(../../lib)

INCLUDE_DIRECTORIES( .  )
INCLUDE_DIRECTORIES(../../thirdparty/asio-1.10.8/include )
INCLUDE_DIRECTORIES(../../protocol )
INCLUDE_DIRECTORIES(../../thirdparty/protobuf-3.3.x/include )
INCLUDE_DIRECTORIES(../../thirdparty/curl-7.40.0/include )
INCLUDE_DIRECTORIES(../../thirdparty )
INCLUDE_DIRECTORIES(../../common/include )
INCLUDE_DIRECTORIES(../behaviac3.6.39/inc )
INCLUDE_DIRECTORIES(../behaviac3.6.39/exported/behaviac_generated/types )
INCLUDE_DIRECTORIES(../../share)
INCLUDE_DIRECTORIES(../../../)
INCLUDE_DIRECTORIES(../../../rogamelibs/)
INCLUDE_DIRECTORIES(./robot_team)
INCLUDE_DIRECTORIES(./robot_base)
INCLUDE_DIRECTORIES(./robot_manager)
INCLUDE_DIRECTORIES(./robot_component)


#FILE(GLOB_RECURSE SRC_LIST *.cpp)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR} SRC_LIST_1)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/../../protocol/pb SRC_LIST_2)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/../behaviac3.6.39/exported/behaviac_generated/types/internal SRC_LIST_3)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/robot_component SRC_LIST_4)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/robot_base SRC_LIST_4)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/robot_manager SRC_LIST_4)


#vs project里面增加但是没有用不知道为什么
#FILE(GLOB_RECURSE  HEAD_FILES_1 "./*.h")
#source_group(".\\" FILES ${HEAD_FILES_1})
#MESSAGE(${HEAD_FILES_1})

#FILE(GLOB_RECURSE  HEAD_FILES_3 "../../protocol/pb/*.h")
#SOURCE_GROUP("..\\..\\protocol/pb" FILES ${HEAD_FILES_3})
#MESSAGE(${HEAD_FILES_3})


set(SRC_LIST 
		${SRC_LIST_1}
		${SRC_LIST_2}
		${SRC_LIST_3}
		${SRC_LIST_4}
		)


#如果要用tcmalloc，则需要加一些文件，和链接tcmalloc库
#使用的自己注意开关
SET (use_tcmalloc_lib )
ADD_DEFINITIONS(-DUSE_TCMALLOC)
LIST(APPEND SRC_LIST ${PROJECT_SOURCE_DIR}/../../share/gperf/gperf_tcmalloc.cpp)
LIST(APPEND SRC_LIST ${PROJECT_SOURCE_DIR}/../../share/gperf/gperf_profiler.cpp)
LIST(APPEND use_tcmalloc_lib tcmalloc unwind profiler )



IF (WIN32)  
ADD_DEFINITIONS(-DDEBUG_TABLE)

    LINK_LIBRARIES( libprotobufd libbehaviac_msvc_debug network libiconv zlibwapi common rogamelibs lua51 libcurld  Wldap32)
ELSE()

    LINK_LIBRARIES( pthread protobuf common_new util_new rogamelibs_release lua behaviac_gcc_release z configlib curl dl crypto 	${use_tcmalloc_lib})
ENDIF()  

SET(EXECUTABLE_OUTPUT_PATH ../../exe)

#ADD_EXECUTABLE(robotclient ${SRC_LIST})
my_add_executable(robotclient ${SRC_LIST})

