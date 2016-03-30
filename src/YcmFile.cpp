#include "YcmFile.hpp"

namespace cproject {

	YcmFile::YcmFile(const std::string& file)
	{
		file_name = file;

		file_writer.open(file);

		if(!file_writer.is_open())
			throw "Couldn't open file: " + file;
	}

	YcmFile::~YcmFile()
	{
		if(file_writer.is_open())
			file_writer.close();
	}

	void YcmFile::WriteHeader()
	{
		file_writer << "import os" << "\n" << "import ycm_core";
	}

}
