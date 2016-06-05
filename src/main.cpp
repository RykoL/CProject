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
	//cproject::CMakeFile cm;
	//d.CreateBase(argv[0], cproject::Permission::kUserRead | cproject::Permission::kUserWrite | cproject::Permission::kUserExecute);
	//d.Create("src", cproject::Permission::kUserRead |cproject::Permission::kUserWrite | cproject::Permission::kUserExecute);
	//d.Create("include", cproject::Permission::kUserRead |cproject::Permission::kUserWrite | cproject::Permission::kUserExecute);

	//std::std::cout<< get_current_dir_name() << std::endl;
	//std::std::cout // Declare the supported options.
	
	try 
	{
		po::options_description desc("Allowed options");
		desc.add_options()
			("help", "print out this message")
			("name", po::value<std::string>()->required(), "name of the project")
			("add-cmake" , "specifies if a CMakeLists.txt should be created")
			("directories",po::value< std::vector<std::string> >() , "specifies the directories to be created")
			("include-directories", po::value<std::vector<std::string > >(),"add include directories to the CMakeLists.txt")
			("libs", po::value<std::vector<std::string > >(),"add a library to the CMakeLists.txt file");

		po::positional_options_description p;
		p.add("directories",-1);
		p.add("name", 1);

		po::variables_map vm;
		po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(),vm);
		po::notify(vm);

		if(vm.count("name"))
		{
			d.CreateBase(vm["name"].as<std::string>());
		}

		if(vm.count("directories"))
		{
			std::cout<< vm["directories"].as<std::vector<std::string>>();
		}
	}
	catch(const std::exception &e)
	{
		std::cerr<< e.what() << std::endl;
		return -1;
	}

	return 0;
}
