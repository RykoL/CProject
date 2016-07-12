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
			CMakeFile(const std::string& projectName, const std::string& minVersion , const std::string& executableName);
			CMakeFile(const std::string& file = "./CMakeLists.txt") {_writer.open(file);};

			~CMakeFile() {_writer.close();};

			/*
			 * Sets the CMake project name
			 * const std::string& name Name of the CMake project
			 */
			void SetProjectName(const std::string &name) {_name = name;};

			/* 
			 * Sets the minimum required option to the given version 
			 * const std::string& version : Minimum required version as string
			 */
			void SetCMakeMinVersion(const std::string &version) {_min_version = version;};

			/* 
			 * Adds a executable to the CMakeFile
			 * const CMakeExecutable& exe : Object representing a CMake Executable
			 */
			void SetExecutable(const CMakeExecutable& exe);

			/* 
			 * Adds a executable to the CMakeFile
			 * const std::string& name : Name of the executable to be added to the CMake File
			 * const std::vector<std::string>& files : List of all files to be included in the compilation process
			 * e.g source files 
			 */
			void SetExecutable(const std::string& name,const std::vector<std::string>& files);

			/*
			 * Adds a compiler flag to the CMake File
			 * const std::string& flag : Flag to be added to the CMake File
			 */
			void AddCompilerFlag(const std::string& flag);

			/*
			 * Adds compiler flags to the CMake File
			 * const std::vector<std::string>& flags : Flags to be added to the CMake File
			 */
			void AddCompilerFlags(const std::vector<std::string>& flags) {_flags.insert(_flags.begin(), flags.begin(), flags.end());};

			/* 
			 * Adds additional include directories to the CMake file. E.g boost headers
			 * const std::string& dir :  include directory to be added
			 */
			void IncludeDirectory(const std::string& dir) {_directories.push_back(dir);};
			void IncludeDirectories(const std::vector<std::string> &dirs) {_directories.insert(_directories.begin(),
					dirs.begin(), dirs.end());};

			void WriteToFile();
			void WriteHeader();
			void WriteLibraries();	
			void WriteIncludeDirectories();
			void WriteExecutables();

		private:
			std::string _name = "";
			std::string _min_version = "";
			std::vector<CMakeExecutable> _executables;
			CMakeExecutable mainExecutable;
			std::vector<std::string> _flags;
			std::vector<std::string> _directories;
			std::ofstream _writer;
	};
}
#endif
