#ifndef Parse_H
#define Parse_H

#include "common.h"


using namespace std;

class Parse{

	public:
		Parse(vector<string> command_in);
		~Parse();
		int ComputerBjontegaard();
		vector<string> GetCommand();

		int GetThreadCount();
		int GetCommandCount();
		int GetMode();
		void SetLogParameters();

		vector<double> GetUPSNREva();
		vector<double> GetVPSNREva();
		vector<double> GetYPSNREva();
		vector<double> GetYOUPSNREva();
		vector<double> GetBitRateEva();


		vector<double> GetYPSNRRef();
		vector<double> GetUPSNRRef();
		vector<double> GetVPSNRRef();
		vector<double> GetYOUPSNRRef();

		vector<double> GetBitRateRef();

	private:
		
		int mode_flag,
			video_count,
			cfg_count, 
			count_quant, 
			computer_interval, 
			thread_count,
			wdt_codec,
			hgt_codec,
			f_rate,
			f_total;

		string 	codec_eva_path,
				codec_ref_path,
	            out_video_path,
	            out_log_path;
	
		vector<string> cfg_vet;
	    vector<string> coeficient_vet;
	    vector<string> videos_vet;        
		vector<string> file_out_ref;
		vector<string> file_out_eva;
		vector<string> command_line;

			
		vector<double> ypsnr_eva;
		vector<double> upsnr_eva;
		vector<double> vpsnr_eva;
		vector<double> yuvpsnr_eva;
		vector<double> bit_vet_eva;
		vector<double> total_frames_eva;
		vector<double> bit_rate_eva;

		vector<double> ypsnr_ref;
		vector<double> upsnr_ref;
		vector<double> vpsnr_ref;
		vector<double> yuvpsnr_ref;
		vector<double> bit_vet_ref;
		vector<double> total_frames_ref;
		vector<double> bit_rate_ref;

		void 			CommandManeger(vector<string> command_line);
		void 			CommandCodecMountRef();
		void 			CommandCodecMountEva();
		int 			FindInFile(string file_log, int codec_flag);
		int 			ConversorStrToInt(string input);
		string 			ConversorIntToStr(int number);
		string 			RemoveInvalidChar(string text);
		void 			InitParse();

};
#endif