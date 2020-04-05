cmake_minimum_required(VERSION 3.0)

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


PROJECT(smalltest)

set(CMAKE_BUILD_TYPE "Release")


IF (WIN32)  
ELSE()

	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x -fno-omit-frame-pointer -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free ")
	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS}  -O0 -g ")
	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2 -g -Werror ")
ENDIF()


INCLUDE_DIRECTORIES( .  )
file(GLOB_RECURSE header . *.h)
INCLUDE_DIRECTORIES( ../AESever/common  )
file(GLOB_RECURSE header ../AESever/common *.h)

#添加头文件的目录
foreach(_headerfile IN ITEMS ${header})
    assign_source_group(${_headerfile})
endforeach()


AUX_SOURCE_DIRECTORY(. SRC_LIST)

AUX_SOURCE_DIRECTORY(../AESever/common SRC_LIST)

IF (WIN32)  
ELSE()
    #LINK_LIBRARIES( tcmalloc )
ENDIF()  

my_add_executable(smalltest ${SRC_LIST})
