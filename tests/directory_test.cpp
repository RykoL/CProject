#include "Directory.hpp"
#include "gtest/gtest.h"
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>

TEST(DirectoryTest, CreateDirectory)
{
	cproject::Directory d;

	DIR* dir = opendir("foo");
	if(dir)
	{
		closedir(dir);
		rmdir("foo");
	}

	d.Create("foo", cproject::Permission::kUserWrite | cproject::Permission::kUserRead);

	dir = opendir("foo");
	
	EXPECT_NE(dir , nullptr);
	closedir(dir);
}

TEST(DirectoryTest, DirectoryMode)
{
	cproject::Directory d;

	DIR* dir = opendir("foo");
	if(dir)
	{
		closedir(dir);
		rmdir("foo");
	}

	d.Create("foo", cproject::Permission::kUserWrite | cproject::Permission::kUserRead);

	struct stat buffer;
	stat("foo/", &buffer);

	EXPECT_EQ(buffer.st_mode,static_cast<unsigned int>( S_IFDIR | cproject::Permission::kUserWrite | cproject::Permission::kUserRead));
}

TEST(DirectoryTest, CreateFile)
{
	cproject::Directory d;

	unlink("foo.test");
	
	d.CreateFile("foo.test", cproject::Permission::kGroupWrite);

	FILE* file = fopen("foo.test", "w");

	auto temp = file;
	fclose(file);
	unlink("foo.test");

	EXPECT_NE(temp , nullptr);
}
