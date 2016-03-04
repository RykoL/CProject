cmake_minimum_required(VERSION 3.4.3)
project(CProject)

set(GTEST_LIBRARY "lib/gtest_main.a")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -g")

enable_testing()
include_directories("include/")
include_directories("include/gtest")

# Unit Testing with GTES# Unit Testing with GTESTT

add_executable(runUnitTests tests/example.cpp tests/tests_main.cpp) 
target_link_libraries(runUnitTests ${CMAKE_SOURCE_DIR}/${GTEST_LIBRARY})
target_link_libraries(runUnitTests pthread)

add_test(
	NAME runUnitTests
	COMMAND runUnitTests
)

	#add_executable(CProject "")
