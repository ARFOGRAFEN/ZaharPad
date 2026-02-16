#include <iostream>
#include <fstream>
#include <string>
#include "file.h"
#include "data.h"

void File_Act::ReadFile(std::string filename) {
	std::ifstream file(filename);
	std::string line;
	while(getline(file, line)) {
		std::cout << line << "\n";
	}
	file.close();
}

void File_Act::EditFile(std::string filename, std::string command_stop) {
	std::string user_input;
	ReadFile(filename);
	std::ofstream file(filename, std::ios::app);
	while(user_input != command_stop) {
		std::cin >> user_input;
		file << user_input;
	}
}

void File_Act::CreateFile(std::string filename) {
	Log::Save(filename);
	if(filename == "") {
		filename = "NewFileZaharPad.txt";
	}
	EditFile(filename, "stop");
}
void File_Act::LoadFile() {
	std::cout << "Enter the Directory and Name File: ";
	std::string filename;
	std::cin >> filename;
	Log::Save(filename);
	EditFile(filename, "stop");
}