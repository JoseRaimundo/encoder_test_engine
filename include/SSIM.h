#ifndef SSIM_H
#define SSIM_H



#include "Video.h"

using namespace std;

class SSIM
{
    public:
        double computeSSIM(Video& RefVideo, Video& TestVideo, int row, int col);
		//void SSIM();
    protected:

    private:
		double SSIM;
		long t0,t;
		double deltat;
};

#endif // SSIM_H
