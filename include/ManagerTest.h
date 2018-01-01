#ifndef ManagerTest_H
#define ManagerTest_H

#include "../include/EncoderExec.h"
#include "../include/Parse.h"

#include "common.h"

using namespace std;

class ManagerTest {

	public:
		ManagerTest(string mode_flag, 
					string thread_count, 
			    	vector<UnitTest> unit_tests,
			    	vector<InputVideo> 	videos_vet    
		);

		~ManagerTest();

		void executeEncodes();
		vector<UnitTest> getUnitTests();

	private:

		int converterStrToInt(string str);
		double totalTime(string file_log);
		int thread_qtd; 
		string mode_flag; 
    	vector<UnitTest> unit_tests;
    	vector<InputVideo> 	videos_vet;
    	vector<LogFile> file_logs;

};
#endif
