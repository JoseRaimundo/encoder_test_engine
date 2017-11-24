
#ifndef Chart_H
#define Chart_H

#include "gnuplot-iostream.h"
#include "common.h"


using namespace std;

class Chart{

	public:
		Chart(vector<double> psnr_eva, vector<double> rate_eva, vector<double> psnr_ref, vector<double> rate_ref, vector<double> qp, string name_test);
		~Chart();

	private:
		vector<double> psnr_eva; 
		vector<double> rate_eva;
		vector<double> psnr_ref;
		vector<double> rate_ref;
		vector<double> qp;
		string name_test;


		void chartPSNRxGP();
		void chartBRxGP();
		// void ChartPSNRxBR();
	};
#endif