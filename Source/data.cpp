#include <iostream>
#include "buildnumbers.h"
#include <fstream>
#include <string>
#include "file.h"
#include "data.h"

std::vector<std::string> Log::data;

void Log::Save(std::string fd) {
	data.push_back(fd);
	std::ofstream log_file("hist.txt", std::ios::app); //файл hist.txt
	log_file << fd << "\n";
	log_file.close();
}

void Log::TakeHist() {
	std::string line;
	std::ifstream log_file("hist.txt");
	while(getline(log_file, line)) {
		std::cout << line << "\n";
	}
}