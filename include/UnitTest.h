#ifndef UnitTest_H
#define UnitTest_H

#include <string>


using namespace std;

class UnitTest{

	public:
		UnitTest(string command, string out_log, string input_video, string out_video, string encoder, 	string decoder);
		~UnitTest();
		string getCommand();


		void setStatus(int status);
		int getStatus();
		string getOutFile();
		string getInputVideo();
		string getOutVideo();
		string getDecoder();



	private:
		string input_video;
		string command; 
		string out_log;
		string out_video;
		string encoder;
		string decoder;
		int status_test;
};

#endif
