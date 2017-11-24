#ifndef BJONTEGAARD_H
#define BJONTEGAARD_H


#include "common.h"


using namespace std;

class Bjontegaard{

	public:
		Bjontegaard(vector<double> psnr_eva, vector<double> rate_eva, vector<double> psnr_ref, vector<double> rate_ref);
		~Bjontegaard();
		double bdAvg();
		double bdRate();

	private:

		double *psnr_ref, *rate_ref, *psnr_eva, *rate_eva;

		int order;	
		int countOfElements;

		void initBD();

		int polyfit(double * input_x, double * input_y, double * coefficients);
		void polyint(double *c_in, int deg, double *vet_out);
		double polyval(double *c_in, int deg, double x_in);
};
#endif