#ifndef CMAKE_EXCECUTABLE_HPP
#define CMAKE_EXCECUTABLE_HPP
#include <string>
#include <vector>
#include <sstream>

namespace cproject
{

	class CMakeExecutable
	{
		public:
			CMakeExecutable() {};
			CMakeExecutable(const std::string& name, const std::vector<std::string> &files);

			void SetName(const std::string& name) {_name = name;};
			std::string GetName() const {return _name;};

			void AddFile(const std::string &file) {files_to_compile.push_back(file);};
			void AddFiles(const std::vector<std::string> &files) {files_to_compile.insert(files_to_compile.begin(),files.begin() ,files.end());};

			std::vector<std::string> GetFilesToCompile() const {return files_to_compile;};
			std::string GetFilesToCompileAsString();

		private:
			std::string _name;
			std::vector<std::string> files_to_compile;
	};



}
#endif
