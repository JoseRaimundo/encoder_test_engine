#include "LogFile.h"


LogFile::LogFile(double   y_psnr, double u_pnsr, double v_psnr, double bit_rate, double total_time){
    this->y_psnr     = y_psnr;
    this->u_pnsr     = u_pnsr;
    this->v_psnr     = v_psnr;
    this->bit_rate   = bit_rate;
    this->total_time = total_time;
}

LogFile::~LogFile(){
}

double LogFile::getYPSNR(){
	return this->y_psnr;
}

double LogFile::getUPSNR(){
	return this->u_pnsr;
}

double LogFile::getVPSNR(){
	return this->v_psnr;
}

double LogFile::getBitRate(){
	return this->bit_rate;
}

double LogFile::getTime(){
	return this->total_time;
}
