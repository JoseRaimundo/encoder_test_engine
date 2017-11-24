#ifndef LogFile_H
#define LogFile_H

#include "common.h"


using namespace std;

class LogFile{

	public:
		LogFile(double 	y_psnr, double u_pnsr, double v_psnr, double bit_rate, double total_time);
		~LogFile();
	
		// double getYPSNR();
		// double getUPSNR();
		// double getVPSNR();
		// double getBitRate();

	private:

		double 	y_psnr,
				u_pnsr,
				v_psnr;

		double bit_rate;

		double total_time;
};
#endif