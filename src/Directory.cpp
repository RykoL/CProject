#include "Directory.hpp"

namespace cproject
{
	void Directory::Create(const std::string& name, Permission mode)
	{
		//set the file creation mask
		mode_t mask = umask(0);
		umask(mask);

		if(mkdir(name.c_str(), mode & (0777 & ~mask) ) != 0)
			exit(EXIT_FAILURE);

	}
}
