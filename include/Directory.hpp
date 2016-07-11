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

	/*
	 * Enumeration that maps the file creation masks on unix systems
	 */
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

	/*
	 * Constant that defines the default Unix file creation mask
	 */
	const Permission kDefaultPermission = Permission::kUserRead | Permission::kUserWrite | Permission::kUserExecute |
					Permission::kGroupWrite | Permission::kGroupRead | Permission::kGroupExecute | Permission::kOthersExecute;

	/*
	 * Class that handles directory/file creation in a safer environment
	 */
	class Directory 
	{
		public:
			/*
			 * Creates a directory with specified permissions. 
			 * const std::string& name : Name of the directory to be created , can`t be null or
			 * empty.
			 * Permission perm : File creating mask of the directory to be created.
			 */
			void Create(const std::string& name = "", Permission createPermission = kDefaultPermission); 
			
			
			/* 
			 * Creates a file in the current working directory with given permissions
			 * const std::string& name : Name of the file to be created , can`t be null or
			 * empty.
			 * Permission perm : File creating mask of the file to be created.
			 */
			void CreateFile(const std::string&name, Permission mode);


			/*
			 * Creates a directory with specified permissions and changes the working directory
			 * to the newly created directory.
			 * const std::string& name : Name of the directory to be created , can`t be null or
			 * empty,
			 * Permission perm : File creating mask of the directory to be created,
			 */
			 void CreateBase(const std::string& name, Permission createPermission = kDefaultPermission);
	};
}
//#endif
