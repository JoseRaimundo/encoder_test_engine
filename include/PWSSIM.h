#ifndef PWSSIM_H
#define PWSSIM_H



#include "Video.h"

using namespace std;

class PWSSIM {

	public:
		double computePWSSIM(Video& RefVideo, Video& TestVideo, int row, int col);
	
	
	private:
		double PWSSIM;
		long t0,t;
		double deltat;

};
#endif
