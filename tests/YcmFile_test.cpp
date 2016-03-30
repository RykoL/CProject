#include "gtest/gtest.h"
#include "YcmFile.hpp"

TEST(YcmFileTests, WriteHeaderTest)
{
	cproject::YcmFile ycm(".ycm_extra_conf_test.py");
	std::ifstream if_s(".ycm_extra_conf_test.py");

	ycm.WriteHeader();
	ycm.CloseWriter();

	std::string vals[2];
	std::getline(if_s, vals[0]);
	std::getline(if_s, vals[1]);

	EXPECT_EQ(vals[0], "import os");
	EXPECT_EQ(vals[1], "import ycm_core");
}
