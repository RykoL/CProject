#include "Directory.hpp"
#include "gtest/gtest.h"
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

TEST(DirectoryTest, Create)
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

TEST(DirectoryTest,Mode)
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
