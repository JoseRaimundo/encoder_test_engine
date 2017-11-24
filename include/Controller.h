#ifndef Controller_H
#define Controller_H


#include "../include/common.h"
#include "../include/Parse.h"
#include "../include/CodecExecutor.h"
#include "../include/Bjontegaard.h"
#include "../include/MountTest.h"
#include "common.h"


using namespace std;

class Controller{

	public:
		Controller(const char *argv[], int argc);
		~Controller();
		void executeEncodes();

	private:
		Test *test;
		Parse *parse;
		vector<string> command_line;
		int count_execution,
			thread_qtd;

		bool is_bkp;
			
		void 	computerBjontegaard(vector<double> psnr_ref, vector<double> rate_ref, vector<double> psnr_eva, vector<double> rate_eva);
		void 	initController(const char *argv[], int argc);
		int 	conversorStrToInt(string input);
		string 	conversorIntToStr(int number);
		string 	computerTime(double t_total);
		double 	totalTime(string file_log);
		
};
#endif