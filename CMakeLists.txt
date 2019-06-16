cmake_minimum_required(VERSION 3.6)
project(immortalsDuel)


find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

include_directories (immortalsDuel)
add_subdirectory (libgamepad)
file(GLOB_RECURSE GEN_PROTO_DEF "Source/*.proto")

set(PROTO_SRCS)
set(PROTO_HDRS)

foreach(file ${GEN_PROTO_DEF})
    get_filename_component(FILE_ABS ${file} ABSOLUTE)
    get_filename_component(FILE_WE ${file} NAME_WE)
    get_filename_component(FILE_PATH ${file} DIRECTORY)

    set(GEN_FILE_HEADER "${FILE_PATH}/${FILE_WE}.pb.h")
    set(GEN_FILE_SOURCE "${FILE_PATH}/${FILE_WE}.pb.cc")

    file(RELATIVE_PATH GEN_FILE_HEADER_REL ${CMAKE_CURRENT_SOURCE_DIR} ${GEN_FILE_HEADER})
    file(RELATIVE_PATH GEN_FILE_SOURCE_REL ${CMAKE_CURRENT_SOURCE_DIR} ${GEN_FILE_SOURCE})

    list(APPEND PROTO_SRCS ${GEN_FILE_SOURCE_REL})
    list(APPEND PROTO_HDRS ${GEN_FILE_HEADER_REL})

    add_custom_command(
            OUTPUT ${GEN_FILE_SOURCE}
            ${GEN_FILE_HEADER}
            COMMAND  ${PROTOBUF_PROTOC_EXECUTABLE}
            ARGS --proto_path=${FILE_PATH} --cpp_out=${FILE_PATH} ${FILE_ABS}
            DEPENDS ${FILE_ABS}
            COMMENT "Running C++ protocol buffer compiler on ${file}"
            VERBATIM )
endforeach()

#set(CMAKE_VERBOSE_MAKEFILE TRUE)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#message(WARNING "The flags:")
#message(WARNING ${CMAKE_CXX_FLAGS})

#message(WARNING ${CMAKE_EXE_LINKER_FLAGS})
#file(GLOB_RECURSE GEN_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.c")



file(GLOB_RECURSE GEN_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "Source/*.c" "Source/*.cpp" "/Source/*.cc" "/Source/*.cxx")
file(GLOB_RECURSE GEN_HEADER_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "Source/*.h" "Source/*.hpp")

set(SOURCE_FILES main.cpp
        ${GEN_SOURCE_FILES}
        ${PROTO_SRCS}
        ${GEN_HEADER_FILES}
        ${PROTO_HDRS})

add_executable(immortalsDuel ${SOURCE_FILES})
target_link_libraries(immortalsDuel gamepad ${PROTOBUF_LIBRARIES})
add_dependencies(immortalsDuel gamepad)


