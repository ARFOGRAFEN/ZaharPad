#include <iostream>
#include "buildnumbers.h"
#include <fstream>
#include <string>

int ver = num_of_build(0,0,1);
const std::string file_default_name = "NewFileZaharPad.txt";

void Command_Message() {
	std::cout << "Command: \n--newfile\n--loadfile\n--exit" << std::endl;
}



void HelloMessage() {
	std::cout << "ZZZZZZZZ  AAAAAAAA  HH    HH  AAAAAAAA  RRRRRRR   PPPPPPP   AAAAAAAA  DDDDDDD" << std::endl;
	std::cout << "     ZZ   AA    AA  HH    HH  AA    AA  RR    RR  PP    PP  AA    AA  DD    DD" << std::endl;
	std::cout << "    ZZ    AAAAAAAA  HHHHHHHH  AAAAAAAA  RRRRRRR   PPPPPPP   AAAAAAAA  DD    DD" << std::endl;
	std::cout << "   ZZ     AA    AA  HH    HH  AA    AA  RR   RR   PP        AA    AA  DD    DD" << std::endl;
	std::cout << "ZZZZZZZZ  AA    AA  HH    HH  AA    AA  RR    RR  PP        AA    AA  DDDDDDD" << std::endl;
	std::cout << "---------------------\n Version(NewEngine):" << ver << "\n---------------------" << std::endl;
}


void ReadFile(std::string filename) {
	std::ifstream file(filename);
	std::string line;
	while(getline(file, line)) {
		std::cout << line;
	}
	file.close();
}

void EditFile(std::string filename, std::string command_stop) {
	std::string user_input;
	ReadFile(filename);
	std::ofstream file(filename, std::ios::app);
	while(user_input != command_stop) {
		std::cin >> user_input;
		file << user_input;
	}
}

void CreateFile(std::string filename) {
	if(filename == "") {
		filename = file_default_name;
	}
	EditFile(filename, "stop");
}


void LoadFile() {
	std::cout << "Enter the Directory and Name File: ";
	std::string filename;
	std::cin >> filename;
	EditFile(filename, "stop");
}

void ExitProgramm(bool &running) {
	running = false;
}


int main() {
	HelloMessage();
	Command_Message();
	bool running = true;
	
	while(running) {
		std::string command;
		std::cout << ">";
		std::cin >> command;
		
		if(command == "exit") {
			ExitProgramm(running);
		}
		else if(command == "newfile") {
			CreateFile(file_default_name);
		}
		else if(command == "loadfile") {
			LoadFile(file_default_name);
		}
	}
}