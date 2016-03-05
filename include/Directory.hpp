#pragma once
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

namespace cproject
{

	enum Permission
	{
		kUserWrite = S_IWUSR,
		kUserRead = S_IRUSR,
		kUserExecute = S_IXUSR
	};

	class Directory 
	{
		public:
			void Create(const std::string& name, Permission create_permission);
	};
}
