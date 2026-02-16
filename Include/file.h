#pragma once

#include <iostream>
#include <string>

class File_Act {
public:
	void ReadFile(std::string filename);
	void EditFile(std::string filename, std::string command_stop);
	void CreateFile(std::string filename);
	void LoadFile();
};