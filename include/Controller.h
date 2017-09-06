#ifndef Controller_H
#define Controller_H


#include "../include/CodecExecutor.h"
#include "../include/Bjontegaard.h"
#include "../include/Parse.h"
#include "common.h"


using namespace std;

class Controller{

	public:
		Controller(const char *argv[], int argc);
		~Controller();
		void Execute();

	private:
		Parse *parse;
		vector<string> command_line;
		int count_execution,
			thread_qtd;

		bool is_bkp;
			
		void ComputerBjontegaard(vector<double> psnr_ref, vector<double> rate_ref, vector<double> psnr_eva, vector<double> rate_eva);
		void InitController(vector<string> command_in);
		int 			ConversorStrToInt(string input);
		string 			ConversorIntToStr(int number);
		string ComputerTime(double t_total);
		double TotalTime(string file_log);
		
};
#endif