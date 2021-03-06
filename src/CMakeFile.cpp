#include "CMakeFile.hpp"

namespace cproject
{

	CMakeFile::CMakeFile(const std::string& projectName, const std::string& minVersion , const std::string& executableName)
		: _name{projectName} , _min_version{minVersion}, mainExecutable(executableName, {})
	{
		_writer.open("./CMakeLists.txt");
	}

	void CMakeFile::SetExecutable(const CMakeExecutable& exec)
	{
		this->_executables.push_back(exec);
	}

	void CMakeFile::SetExecutable(const std::string& name, const std::vector<std::string>& files)
	{
		_executables.emplace_back(name, files);
	}

	void CMakeFile::AddCompilerFlags(const std::vector<std::string>& flags)
	{
		_flags.insert(_flags.begin(), flags.begin(), flags.end());
	}

	void CMakeFile::AddCompilerFlag(const std::string& flag)
	{
		auto temp_flag = flag;

		if(flag[0] != '-')
			temp_flag.insert(0, "-");

		_flags.push_back(flag);
	}

	void CMakeFile::WriteToFile()
	{
		WriteHeader();
		WriteIncludeDirectories();
		WriteExecutables();
		WriteLibraries();
		WriteTargetFlags();
	}

	void CMakeFile::WriteTargetFlags()
	{
		_writer << "target_compile_options( " << mainExecutable.GetName() << " PRIVATE ";

		for(auto flag : _flags)
		{
			flag.insert(flag.begin(), 1, '-');
			_writer << flag << " ";
		}

		_writer << " )\n\n";
	}

	void CMakeFile::WriteExecutables()
	{

		_writer << "add_executable(" << mainExecutable.GetName() << " " << mainExecutable.GetFilesToCompileAsString() << " main.cpp )\n\n";

		//TODO: Dont forget to handle the main executable before checking for other executables to write to the file
		if(_executables.size() > 0)
		{
			for(auto exec : _executables) //Iterate trough all executables of the projects
			{
				_writer  << "add_executable(" << exec.GetName() << " " << exec.GetFilesToCompileAsString() << ")\n"; 
			}
		}

	}

	void CMakeFile::WriteIncludeDirectories()
	{
		if(_directories.size() > 0)
		{
			_writer<< "include_directories(";

			for(std::string dir : _directories)
			{
				_writer << dir << " ";
			}

			_writer << ")\n\n";
		}
	}

	void CMakeFile::WriteHeader()
	{
		if(!_writer.is_open())
			return;

		_writer<< "cmake_minimum_required(VERSION "<< _min_version << ")\n"
		<< "project(" << _name << ")\n\n"; 
	}

	void CMakeFile::WriteLibraries()
	{
		//A library is associated with a target/executable

		if(_libraries.size() > 0)
		{
			_writer << "target_link_libraries(" << mainExecutable.GetName() << " ";

			for(auto lib : _libraries)
			{
				_writer << lib << " ";
			}

			_writer << ")\n\n";
		}
	}
}
