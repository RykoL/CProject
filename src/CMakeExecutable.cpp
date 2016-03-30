#include "CMakeExecutable.hpp"

namespace cproject {

	std::string CMakeExecutable::GetFilesToCompileAsString()
	{
		std::stringstream s;
		
		for(auto x : files_to_compile)
			s << x << " ";

		return s.str();
	}

	CMakeExecutable::CMakeExecutable(const std::string& name, const std::vector<std::string> &files)
	{
		_name = name;
		AddFiles(files);
	}
}
