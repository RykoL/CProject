cmake_minimum_required(VERSION 3.4.3)
project(CProject CXX)

set(GTEST_LIBRARY "lib/gtest_main.a")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -g")

enable_testing()
include_directories("include/")
include_directories("include/gtest")
include_directories("/usr/include/boost")

# Unit Testing with GTES# Unit Testing with GTEST

add_executable(runUnitTests tests/directory_test.cpp src/Directory.cpp tests/example.cpp tests/tests_main.cpp src/CMakeExecutable.cpp src/CMakeFile src/YcmFile.cpp tests/cmake_file_test.cpp tests/YcmFile_test.cpp ) 
target_link_libraries(runUnitTests ${CMAKE_SOURCE_DIR}/${GTEST_LIBRARY})
target_link_libraries(runUnitTests pthread)

add_test(
       NAME runUnitTests
       COMMAND runUnitTests
)

add_executable(CProject src/Directory.cpp src/main.cpp src/YcmFile.cpp src/CMakeExecutable.cpp src/CMakeFile)
target_link_libraries(CProject boost_program_options)
set_target_properties(CProject PROPERTIES LINKER_LANGUAGE CXX)
