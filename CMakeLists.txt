cmake_minimum_required(VERSION 3.4.3)
project(CProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -g")

include_directories("include/")
include_directories("include/goggletest")

add_executable(CProject "")
