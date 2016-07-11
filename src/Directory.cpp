#include "Directory.hpp"

namespace cproject
{
	void Directory::Create(const std::string& name, Permission perm)
	{
		if(name != "") {
			mode_t mask = umask(0);
			umask(mask);

			if(mkdir(name.c_str(), perm & (0777 & ~mask) ) != 0)
				exit(EXIT_FAILURE);
		}

	}

	void Directory::CreateFile(const std::string& path, Permission perm)
	{
		FILE* file = nullptr;

		file = fopen(path.c_str(), "w");
		if(file == nullptr)
			std::cerr<< "Error occured while creating a file" << std::endl;
		else
			fclose(file);
	}

	void Directory::CreateBase(const std::string& name, Permission perm)
	{
		Create(name, perm);
		std::string currentDir = get_current_dir_name();
		std::string new_dir;

		if(name[0] != '/')
			new_dir = currentDir + '/' + name;
		else
			new_dir = currentDir + name;

		chdir(new_dir.c_str());
	}
}
