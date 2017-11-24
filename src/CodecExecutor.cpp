#include "../include/CodecExecutor.h"



CodecExecutor::CodecExecutor(string command_line){
	this->command_line = command_line;
}

CodecExecutor::~CodecExecutor() {
}

void CodecExecutor::codecSystemCommand(string command){
    system(command.c_str());
}



void *CodecExecutor::run() {

	struct timeval start, end;
	gettimeofday(&start, NULL);
	
    codecSystemCommand(command_line);
	gettimeofday(&end, NULL);

	double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
	         end.tv_usec - start.tv_usec) / 1.e6;

	ofstream result("Time_per_test.txt", ios::app);
	if (!result){
		cout << "File couldn't open" << endl;
	}else{
		result << delta << endl;
		result.close();
	}	
	
}







