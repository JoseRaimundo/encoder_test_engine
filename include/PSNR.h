#ifndef PSNR_H
#define PSNR_H

#include "Video.h"

using namespace std;


class PSNR
{
    public:
       
        double computePSNR(Video &RefVideo, Video &TestVideo, int row, int col);
        double getPSNR();

    protected:

    private:
        double PSNR;
        long t0; // Executions time of the method computePSNR();
        long t1;
        double deltat;
};

#endif
