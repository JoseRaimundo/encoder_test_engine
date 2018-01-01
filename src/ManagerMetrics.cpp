#include "../include/ManagerMetrics.h"
#define row 352
#define col 288

ManagerMetrics::ManagerMetrics(vector<UnitTest> unit_tests){//, 
	this->unit_tests = unit_tests;
}

ManagerMetrics::~ManagerMetrics(){
}


void ManagerMetrics::computerMetrics(){
	vector<LogFile> file_ref_logs;
	vector<LogFile> file_eva_logs;
	int continue_cont = 0;
	for (int i = 0; i < MAX_QP; i++){
		

		string reference_video 	= unit_tests[i].getInputVideo();
		int frames = 3;

		double 	psnr_res = 0, 
				ssim_res = 0, 
				pwssim_res = 0, 
				bdrate_res = 0, 
				bd_psnr_res = 0;

		Video reference, encoded, encoded2;
		PSNR  psnr, psnr2 ;
		SSIM ssim, ssim2;
		PWSSIM pwssim, pwssim2;
		
		reference.setCoefs( 2, 2, row, col);
		
		reference.openFile(reference_video.c_str(), row, col, frames);

		encoded.setCoefs(2,2,row,col);
		encoded.openFile(unit_tests[i].getOutVideo().c_str(), row, col, frames);
		
		int numFrames = reference.returnFrames();
			
		if (true){ 
			psnr_res = psnr.computePSNR(reference,encoded,row,col);
		}

		if (true){ 
			ssim_res = ssim.computeSSIM(reference,encoded,row,col);
		}

		if (true){
			pwssim_res = pwssim.computePWSSIM(reference,encoded,row,col);
		}
		
		file_eva_logs.push_back(Parse::parseLog(unit_tests[i].getOutFile()));
		file_ref_logs.push_back(Parse::parseLog(unit_tests[i+MAX_QP].getOutFile()));


		ofstream result("Result_test.txt", ios::app);
		if (!result){
		    cout << "File couldn't open" << endl;
		}else{
		    result 	<<"QP:  " << unit_tests[continue_cont++].getQP() 
		    		<<"		 Evaluate 		Reference"	<< endl
   				 	<< "PSNR ......: "<< psnr_res << "  		" << 256	<< endl
   				 	<< "SSIM ......: "<< ssim_res << "  		" << 256	<< endl 
   				 	<< "PW-SSIM ...: "<< pwssim_res << "  		" << 256	<< endl; 
		}

		reference.deallocatePixelMap();
		encoded.deallocatePixelMap();
		reference.closeFile();
		encoded.closeFile();

		if (file_ref_logs.size() == MAX_QP){
			computerBjontegaard(file_eva_logs, file_ref_logs);
		    //limpar file_logs
		}

	}

}

void ManagerMetrics::computerBjontegaard(vector<LogFile> file_eva_logs, vector<LogFile> file_ref_logs){

	vector<double> psnr_eva;
	vector<double> rate_eva;
	vector<double> psnr_ref;
	vector<double> rate_ref;

	for (int i = 0; i < MAX_QP; i++){
		psnr_eva.push_back(file_eva_logs[i].getYPSNR());
		rate_eva.push_back(file_eva_logs[i].getBitRate());
	}

	for (int i = 0; i < MAX_QP; i++){
		psnr_ref.push_back(file_ref_logs[i].getYPSNR());
		rate_ref.push_back(file_ref_logs[i].getBitRate());
	}

    Bjontegaard *bjontegaard = new Bjontegaard(psnr_eva, rate_eva, psnr_ref, rate_ref);
    
    double avg  = bjontegaard->bdAvg();
    double rate = bjontegaard->bdRate();
    
    ofstream result("Result_test.txt", ios::app);
    if (!result){
        cout << "File couldn't open" << endl;
    }else{
    	result <<"-------------------------"<< endl; 
        result <<"Bjontegaard AVG .....: " << avg << endl; 
        result <<"Bjontegaard Rate ....: " << rate <<endl;
    }
}



// // void ManagerMetrics::computerPSNR(){

// // }