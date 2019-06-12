cmake_minimum_required(VERSION 3.6)
project(immortalsDuel)


include_directories (immortalsDuel)
#include_directories ("${PROJECT_SOURCE_DIR}/immortalsDuel")
add_subdirectory (libgamepad)
#include(Findudev)
#set(CMAKE_VERBOSE_MAKEFILE TRUE)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#message(WARNING "The flags:")
#message(WARNING ${CMAKE_CXX_FLAGS})

#message(WARNING ${CMAKE_EXE_LINKER_FLAGS})
#file(GLOB_RECURSE GEN_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.c")



#file(GLOB_RECURSE GEN_LIBGAMEPAD_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.c" "*.h")
#file(REMOVE GEN_LIBGAMEPAD_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/libgamepad/main.c")
#set_source_files_properties(GEN_LIBGAMEPAD_SOURCE_FILES PROPERTIES LANGUAGE C )
#set_source_files_properties(main.cpp PROPERTIES LANGUAGE CXX )

#file(GLOB_RECURSE GEN_HEADER_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.h")

set(SOURCE_FILES main.cpp)

add_executable(immortalsDuel ${SOURCE_FILES})
target_link_libraries(immortalsDuel gamepad)
add_dependencies(immortalsDuel gamepad)
#target_link_libraries(immortalsDuel ${CMAKE_CURRENT_SOURCE_DIR}/libgamepad)
#set(with-libraries "${CMAKE_CURRENT_SOURCE_DIR}/libgamepad/libgamepad.so")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/libgamepad")


