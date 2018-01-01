#ifndef UnitTest_H
#define UnitTest_H

#include <string>


using namespace std;

class UnitTest{

	public:
		UnitTest(	int id_test,
					string command,
					string out_log, 
					string input_video, 
					string out_video, 
					string encoder,
					string qp);
		~UnitTest();
		string getCommand();

		void setStatus(int status);
		int getStatus();
		string getOutFile();
		string getInputVideo();
		string getOutVideo();
		string getQP();

	private:
		int id_test;
		string input_video;
		string command; 
		string out_log;
		string out_video;
		string encoder;
		string qp;
		int status_test;
};

#endif
