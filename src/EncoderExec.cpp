#include "EncoderExec.h"



EncoderExec::EncoderExec(string command_line){
	this->command_line = command_line;
}

EncoderExec::~EncoderExec() {
}

void EncoderExec::codecSystemCommand(string command){
    system(command.c_str());
}


void *EncoderExec::run() {

	struct timeval start, end;
	gettimeofday(&start, NULL);
	
    codecSystemCommand(command_line);
	gettimeofday(&end, NULL);

	double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
	         end.tv_usec - start.tv_usec) / 1.e6;

	ofstream result("Time_per_test.txt", ios::app);
	cout << "\033[1;32m Coding successfully completed!\033[0m\n";
	if (!result){
		cout << "File couldn't open" << endl;
	}else{
		result << delta << endl;
		result.close();
	}	
	
}







