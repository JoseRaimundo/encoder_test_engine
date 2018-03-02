#include "../include/ManagerMetrics.h"
#define row 3840
#define col 2160

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
		int frames = MAX_FRAMES;

		double 	psnr_eva = 0, 
				ssim_eva = 0, 
				pwssim_eva = 0, 
				bdrate_eva = 0, 
				bd_psnr_eva = 0;

		double 	psnr_ref = 0, 
				ssim_ref = 0, 
				pwssim_ref = 0, 
				bdrate_ref = 0, 
				bd_psnr_ref = 0;

		Video reference, encoded, encoded2;
		PSNR  psnr, psnr2 ;
		SSIM ssim, ssim2;
		PWSSIM pwssim, pwssim2;
		

		//maping video matriz
		reference.setCoefs( 2, 2, row, col);
		reference.openFile(reference_video.c_str(), row, col, frames);

		encoded.setCoefs(2,2,row,col);
		encoded.openFile(unit_tests[i].getOutVideo().c_str(), row, col, frames);
		encoded2.setCoefs(2,2,row,col);
		encoded2.openFile(unit_tests[i + MAX_QP].getOutVideo().c_str(), row, col, frames);
		
		int numFrames = reference.returnFrames();
			

		if (true){ 
			psnr_eva = psnr.computePSNR(reference,encoded,row,col);
			psnr_ref = psnr.computePSNR(reference,encoded2,row,col);
		}

		if (true){ 
			ssim_eva = ssim.computeSSIM(reference,encoded,row,col);
			ssim_ref = ssim.computeSSIM(reference,encoded2,row,col);
		}

		if (true){
			pwssim_eva = pwssim.computePWSSIM(reference,encoded,row,col);
			pwssim_ref = pwssim.computePWSSIM(reference,encoded2,row,col);
		}


		file_eva_logs.push_back(Parse::parseLog(unit_tests[i].getOutFile()));
		file_ref_logs.push_back(Parse::parseLog(unit_tests[i+MAX_QP].getOutFile()));


		ofstream result("Result_test.txt", ios::app);
		if (!result){
		    cout << "File couldn't open" << endl;
		}else{
		    result 	<<"QP:  " << unit_tests[continue_cont].getQP() 
		    		<<"		 Evaluate 		Reference"	<< endl
   				 	<< "PSNR ......: "<< psnr_eva << "  		" << psnr_ref	<< endl
   				 	<< "SSIM ......: "<< ssim_eva << "  		" << ssim_ref	<< endl 
   				 	<< "PW-SSIM ...: "<< pwssim_eva << "  		" << pwssim_ref	<< endl
   				 	<< "BitRate ...: "<< file_eva_logs[continue_cont].getBitRate() 	<< "  		" << file_ref_logs[continue_cont].getBitRate()	<< endl
   				 	<< "Time (s)...: "<< file_eva_logs[continue_cont].getTime() 	<< "  		" << file_ref_logs[continue_cont].getTime()	<< endl; 
   				 	continue_cont++;

		}

		reference.deallocatePixelMap();
		encoded.deallocatePixelMap();
		encoded2.deallocatePixelMap();
		reference.closeFile();
		encoded.closeFile();
		encoded2.closeFile();

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