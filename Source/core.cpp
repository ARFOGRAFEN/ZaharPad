#include <iostream>
#include "buildnumbers.h"
#include <fstream>
#include <string>
#include "file.h"
#include "data.h"

int ver = num_of_build(0,0,3);
const std::string file_default_name = "NewFileZaharPad.txt";

void Command_Message() {
	std::cout << "Command: \n--newfile\n--loadfile\n--recentfile\n--exit" << std::endl;
}

void HelloMessage() {
	std::cout << "ZZZZZZZZ  AAAAAAAA  HH    HH  AAAAAAAA  RRRRRRR   PPPPPPP   AAAAAAAA  DDDDDDD" << std::endl;
	std::cout << "     ZZ   AA    AA  HH    HH  AA    AA  RR    RR  PP    PP  AA    AA  DD    DD" << std::endl;
	std::cout << "    ZZ    AAAAAAAA  HHHHHHHH  AAAAAAAA  RRRRRRR   PPPPPPP   AAAAAAAA  DD    DD" << std::endl;
	std::cout << "   ZZ     AA    AA  HH    HH  AA    AA  RR   RR   PP        AA    AA  DD    DD" << std::endl;
	std::cout << "ZZZZZZZZ  AA    AA  HH    HH  AA    AA  RR    RR  PP        AA    AA  DDDDDDD" << std::endl;
	std::cout << "---------------------\n Version(NewEngine):" << ver << "\n---------------------" << std::endl;
}


void ExitProgramm(bool &running) {
	running = false;
}


int main() {
	HelloMessage();
	Command_Message();
	
	File_Act file_a;
	Log log;
	bool running = true;
	
	while(running) {
		std::string command;
		std::cout << ">";
		std::cin >> command;
		
		if(command == "exit") {
			ExitProgramm(running);
		}
		else if(command == "newfile") {
			file_a.CreateFile(file_default_name);
		}
		else if(command == "loadfile") {
			file_a.LoadFile();
		}
		else if(command == "recentfile") {
			log.TakeHist();
		}
	}
}