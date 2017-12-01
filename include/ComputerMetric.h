#ifndef ComputerMetric_H
#define ComputerMetric_H



#include "common.h"
#include "Thread.h"


using namespace std;

class ComputerMetric : public Thread {

	public:
		ComputerMetric(string input_video, string ref_video, string file_result);
		void *run();
		int escrever();
		~ComputerMetric();
	private:
		void codecSystemCommand(string command);
		string 	command_line;
};
#endif