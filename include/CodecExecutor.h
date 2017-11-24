#ifndef CodecExecutor_H
#define CodecExecutor_H



#include "common.h"
#include "Thread.h"


using namespace std;

class CodecExecutor : public Thread {

	public:
		CodecExecutor(string command_line);
		void *run();
		int escrever();
		~CodecExecutor();
	private:
		void codecSystemCommand(string command);
		string 	command_line;
};
#endif