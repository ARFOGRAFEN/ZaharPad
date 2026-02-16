#pragma once

#include <iostream>
#include "buildnumbers.h"
#include <fstream>
#include <string>
#include "file.h"
#include <vector>

class Log {
public:
	static std::vector<std::string> data;
	
	static void Save(std::string fd);
	static void TakeHist();
};