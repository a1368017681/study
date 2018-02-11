cmake_minimum_required(VERSION 3.10)

#project name
project(cpp11)

# setup compiler
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# define project

# set project version
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSUON_PATCH 0)

option(DEPLOY_TEST "deploy test env" OFF)

# required packages
find_package(Boost REQUIRED COMPONENTS filesystem)

# setup environment
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -std=c++11 -fPIC -Wall -Wno-deprecated")

# Definitions
add_definitions(
    -DDEBUG
)

# link libraries
link_libraries(
    ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES}
    jsoncpp
)

# set include dic path
include_directories(
    "/usr/include/jsoncpp"
    "/usr/include/libxml2"
    "${PROJECT_SOURCE_DIR}"
)

# set link dic path
link_directories(
)

#file(GLOB SOURCES "src/*.cpp")
set(SRC_LIST
    src/main.cpp
)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)
add_executable(prog ${SRC_LIST})

