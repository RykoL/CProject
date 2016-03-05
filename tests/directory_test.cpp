#include "Directory.hpp"
#include "gtest/gtest.h"
#include <dirent.h>

TEST(DirectoryTest, Create)
{
	cproject::Directory d;

	DIR* dir = opendir("foo");
	if(dir)
	{
		closedir(dir);
		rmdir("foo");
	}

	d.Create("foo", cproject::Permission::kUserWrite);

	dir = opendir("foo");
	
	EXPECT_NE(dir , nullptr);
	closedir(dir);
}

