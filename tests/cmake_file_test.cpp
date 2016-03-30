#include "CMakeFile.hpp"
#include "gtest/gtest.h"
#include <fstream>

TEST(CMakeFileTest, WriteHeader)
{
	cproject::CMakeFile cm("Cmake_test.txt");
	cm.SetProjectName("Test");
	cm.SetCMakeMinVersion("3.4.3");
	cm.WriteHeader();

	std::string buffer;
	std::ifstream f("Cmake_test.txt");
	std::getline(f,buffer); 

	EXPECT_EQ(buffer, "cmake_minimum_required(VERSION 3.4.3)");
	std::getline(f, buffer);
	EXPECT_EQ(buffer,"project(Test)");

	f.close();
}

TEST(CMakeFileTest, WriteLibraries)
{
	cproject::CMakeFile cm("Cmake_test.txt");
	cproject::CMakeExecutable exec("TEST",{});
	exec.AddLibraries({"pthread","boost","gtest"});

	cm.SetExecutable(exec);
	cm.WriteLibraries();

	std::string buffer;
	std::ifstream f("Cmake_test.txt");
	std::getline(f,buffer); 

	EXPECT_EQ(buffer, "target_link_libraries(TEST pthread boost gtest )");

	f.close();
}

TEST(CMakeFileTest, IncludeDirectory)
{
	cproject::CMakeFile cm("Cmake_test.txt");
	cm.IncludeDirectories({"include/", "include/gtest", "tests/"});
	cm.WriteIncludeDirectories();

	std::string buffer;
	std::ifstream f("Cmake_test.txt");
	std::getline(f,buffer); 

	EXPECT_EQ(buffer, "include_directories(include/ include/gtest tests/ )");

	f.close();
}

TEST(CMakeFileTest, WriteExecutables)
{
	cproject::CMakeFile cm("Cmake_test.txt");
	cproject::CMakeExecutable exec("TEST",{"test.cpp", "main.cpp","whatever.cpp", "suck.cpp" }); //sigsev after execution
	cm.SetExecutable(exec);
	cm.WriteExecutables();

	std::string buffer;
	std::ifstream f("Cmake_test.txt");
	std::getline(f,buffer); 

	EXPECT_EQ(buffer, "add_executable(TEST test.cpp main.cpp whatever.cpp suck.cpp )");

	f.close();
}
