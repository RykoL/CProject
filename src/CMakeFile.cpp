#include "CMakeFile.hpp"

namespace cproject
{
	void CMakeFile::SetExecutable(const CMakeExecutable& exec)
	{
		this->_executables.push_back(exec);
	}

	void CMakeFile::SetExecutable(const std::string& name, const std::vector<std::string>& files)
	{
		_executables.emplace_back(name, files);
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
		//NOTE: Maybe we'll need it later
	}

	void CMakeFile::WriteExecutables()
	{

		for(auto exec : _executables) //Iterate trough all executables of the projects
		{
			_writer  << "add_executable(" << exec.GetName() << " " << exec.GetFilesToCompileAsString() << ")" <<std::endl;
		}

	}

	void CMakeFile::WriteIncludeDirectories()
	{
		_writer<< "include_directories(";

		for(std::string dir : _directories)
		{
			_writer << dir << " ";
		}

		_writer << ")" << std::endl;
	}

	void CMakeFile::WriteHeader()
	{
		if(!_writer.is_open())
			return;

		_writer<< "cmake_minimum_required(VERSION "<< _min_version << ")\n"
		<< "project(" << _name << ")" << std::endl;  	
	}

	void CMakeFile::WriteLibraries()
	{
		//A library is associated with a target/executable

		for(auto exec : _executables) //Iterate trough all executables of the projects
		{
			_writer  << "target_link_libraries(" << exec.GetName() << " "; 
			
			for(std::string lib : exec.GetLibraries())
			{
				_writer << lib << " ";
			}

			_writer << ")" << std::endl;
		}
	}
}
