#ifndef CMAKE_FILE_HPP
#define CMAKE_FILE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include "CMakeExecutable.hpp"

namespace cproject 
{

	class CMakeFile
	{
		public:
			CMakeFile(const std::string& file = "./CMakeLists.txt") {_writer.open(file);};

			~CMakeFile() {_writer.close();};

			void SetProjectName(const std::string &name) {_name = name;};
			void SetCMakeMinVersion(const std::string &version) {_min_version = version;};
			void SetExecutable(const CMakeExecutable& exe);
			void SetExecutable(const std::string& name,const std::vector<std::string>& files);
			void AddCompilerFlag(const std::string& flag);
			void AddCompilerFlags(const std::vector<std::string>& flags) {_flags.insert(_flags.begin(), flags.begin(), flags.end());};
			void IncludeDirectory(const std::string& dir) {_directories.push_back(dir);};
			void IncludeDirectories(const std::vector<std::string> &dirs) {_directories.insert(_directories.begin(),
					dirs.begin(), dirs.end());};

			void WriteToFile();
			void WriteHeader();
			void WriteLibraries();	
			void WriteIncludeDirectories();
			void WriteExecutables();

		private:
			std::string _name;
			std::string _min_version;
			std::vector<CMakeExecutable> _executables;
			std::vector<std::string> _flags;
			std::vector<std::string> _directories;
			std::ofstream _writer;
	};
}
#endif
