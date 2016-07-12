#include "Directory.hpp"
#include "CMakeFile.hpp"
#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;
template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    copy(v.begin(), v.end(), std::ostream_iterator<T>(os, " "));
    return os;
}

int main(int argc, char*argv[])
{
	cproject::Directory d;
	
	try 
	{
		po::options_description desc("Allowed options");
		desc.add_options()
			("help", "print out this message")
			("name", po::value<std::string>()->required(), "name of the project")
			("add-cmake" , "specifies if a CMakeLists.txt should be created")
			("directories,d",po::value< std::vector<std::string> >()->multitoken() , "specifies the directories to be created")
			("include-directories,i", po::value<std::vector<std::string > >()->multitoken(),"add include directories to the CMakeLists.txt")
			("libs,l", po::value<std::vector<std::string > >()->multitoken(),"add a library to the CMakeLists.txt file");

		po::positional_options_description p;
		p.add("name", 1);

		po::variables_map vm;
		po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(),vm);
		po::notify(vm);

		if(vm.count("help"))
		{
			// Print out the help message
			std::cout<< desc << std::endl;
		}
		// We dont wanna create a base directorie if were searching for help
		else {
			if(vm.count("name")) //Works as intended , not ! 
			{
				d.CreateBase(vm["name"].as<std::string>());
			}

			d.CreateFile("main.cpp", cproject::kDefaultPermission);

			if(vm.count("directories"))
			{
				//Only recognizing 1 argument now ?
				auto dirs = vm["directories"].as<std::vector<std::string>>();
				for(auto dir : dirs)
					d.Create(dir);
			}
			// Handles the logic in case the user specified to create a CMakeFile
			if(vm.count("add-cmake")) //Suddenly works
			{
				cproject::CMakeFile cmakef(vm["name"].as<std::string>(),"2.8",vm["name"].as<std::string>());

				// Check if the user has provided additional include directories
				if(vm.count("include-directories"))
				{
					cmakef.IncludeDirectories(vm["include-directories"].as<std::vector<std::string>>());
				}

				// Check if the user has provided additional libs to include in the compilation process
				if(vm.count("libs"))
				{
					cmakef.AddLibraries(vm["libs"].as<std::vector<std::string>>());
				}
				cmakef.WriteToFile();
			}
		}
	}
	catch(const std::exception &e)
	{
		std::cerr<< e.what() << std::endl;
		return -1;
	}

	return 0;
}
