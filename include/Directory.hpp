//#ifndef DIRECTORY_HPP_
//#define DIRECTORY_HPP_
#pragma once
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>

namespace cproject
{

	enum Permission
	{
		kUserWrite = S_IWUSR,
		kUserRead = S_IRUSR,
		kUserExecute = S_IXUSR,
		kGroupWrite = S_IWGRP,
		kGroupRead = S_IRGRP,
		kGroupExecute = S_IXGRP,
		kOthersWrite = S_IWOTH,
		kOthersRead = S_IROTH,
		kOthersExecute = S_IXOTH
	};

	inline Permission operator|(Permission a, Permission b)
	{
		return static_cast<Permission>( static_cast<int>(a) | static_cast<int>(b));
	}

	class Directory 
	{
		public:
			Directory(const Directory& dir) {};
			Directory() {};

			void Create(const std::string& name, Permission create_permission);
			void CreateFile(const std::string&name, Permission mode);
			void CreateBase(const std::string& name, Permission perm);
	};
}
//#endif
