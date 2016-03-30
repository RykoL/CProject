#ifndef YCMFILE_HPP_
#define YCMFILE_HPP_
#include <string>
#include <iostream>
#include <fstream>

namespace cproject {

	class YcmFile
	{
		public:
			YcmFile(const std::string& file = ".ycm_extra_conf.py");
			~YcmFile();
			void WriteHeader();
			void CloseWriter() {file_writer.close();};

		private:
			std::string file_name;
			std::ofstream file_writer;
	};
}
#endif
