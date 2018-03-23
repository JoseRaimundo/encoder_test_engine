#ifndef EncoderExec_H
#define EncoderExec_H



#include "common.h"
#include "Thread.h"


using namespace std;

class EncoderExec : public Thread {

	public:
		virtual EncoderExec(Video& RefVideo, Video& TestVideo, int row, int col);
		void *run();
		int escrever();
		~EncoderExec();
	private:
		computeSSIM(Video& RefVideo, Video& TestVideo, int row, int col)
		string 	command_line;
};
#endif