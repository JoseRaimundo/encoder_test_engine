#ifndef EncoderExec_H
#define EncoderExec_H



#include "common.h"
#include "Thread.h"


using namespace std;

class EncoderExec : public Thread {

	public:
		EncoderExec(string command_line);
		void *run();
		int escrever();
		~EncoderExec();
	private:
		void codecSystemCommand(string command);
		string 	command_line;
};
#endif