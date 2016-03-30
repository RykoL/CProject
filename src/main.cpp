#include "Directory.hpp"
#include "CMakeFile.hpp"
#include <iostream>

int main(int argc, char*argv[])
{
	cproject::Directory d;
	//cproject::CMakeFile cm;
	d.CreateBase("yousuck", cproject::Permission::kUserRead |cproject::Permission::kUserWrite | cproject::Permission::kUserExecute);
	std::cout<< get_current_dir_name() << std::endl;
	std::cout << "Y U CMAKE?" << std::endl;
	return 0;
}
