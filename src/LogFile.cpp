#include "../include/LogFile.h"


LogFile::LogFile(double   y_psnr, double u_pnsr, double v_psnr, double bit_rate, double total_time){
    this->y_psnr     = y_psnr;
    this->u_pnsr     = u_pnsr;
    this->v_psnr     = v_psnr;
    this->bit_rate   = bit_rate;
    this->total_time = total_time;
}

LogFile::~LogFile(){
}


