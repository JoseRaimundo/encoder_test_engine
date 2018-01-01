#ifndef Controller_H
#define Controller_H


#include "../include/common.h"
#include "../include/MountManagerTest.h"


#include "common.h"

using namespace std;

class Controller{

	public:
		Controller(ManagerTest *input_test, vector<string> command_in);
		~Controller();
		

	private:
		ManagerTest *input_test;
		
		vector<UnitTest>test_units;
		vector<string> command_line;

		bool is_bkp;
			
		string 	converterIntToStr(int number);
		string 	computerTime(double t_total);
		double 	totalTime(string file_log);
		
};
#endif