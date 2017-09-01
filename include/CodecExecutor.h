#ifndef CodecExecutor_H
#define CodecExecutor_H



#include "common.h"
#include "Thread.h"


using namespace std;

class CodecExecutor : public Thread {

	public:
		void *run();
		int escrever();
		CodecExecutor(string command_line);
		~CodecExecutor();
	private:
		void CodecSystemCommand(string command);
		string 	command_line;
};
#endif