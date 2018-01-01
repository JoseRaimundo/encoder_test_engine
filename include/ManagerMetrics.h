#ifndef ManagerMetrics_H
#define ManagerMetrics_H

#include "common.h"
#include "Bjontegaard.h"
#include "Image.h"
#include "Video.h"
#include "Sobel.h"
#include "PSNR.h"
#include "SSIM.h"
#include "PWSSIM.h"


using namespace std;

class ManagerMetrics{

	public:
		ManagerMetrics(vector<UnitTest> unit_tests);
		~ManagerMetrics();
		void computerMetrics();



	private:

		void computerBjontegaard(vector<LogFile> eva_logs, vector<LogFile> ref_logs);
		vector<UnitTest> unit_tests;


};
#endif