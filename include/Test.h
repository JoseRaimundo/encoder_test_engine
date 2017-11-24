#ifndef Test_H
#define Test_H

#include "common.h"

using namespace std;

class Test{

	public:
		Test(string mode_flag, 
			string codec_eva_path, 
			string codec_ref_path, 
			string thread_count, 
			string frame_rate,
			string total_frames, 
			string out_video_path,
			string out_log_path,

			vector<string> cfg_vet,
	    	vector<string> coeficient_vet,
	    	vector<Video> videos_vet,        
			vector<string> file_out_ref,
			vector<string> file_out_eva,
			vector<string> command_line
		);

		~Test();

		bool isBkp();
	

		string getModeFlag();
		string getCodecEvaPath();
		string getCodecRefPath();
		string getThreadCount();
		string getFrameRate();
		string getTotalFrames();
		string getCfgCount();
		string getVideoCount();
		string getOutVideoPath();
		string getOutLogPath();

		int getCommandCount();
		
		vector<string> getCommandLine();


		void setModeFlag(string mode_flag);
		void setCodecEvaPath(string codec_eva_path);
		void setCodecRefPath(string codec_ref_path);
		void setThreadCount(string thread_count);
		void setFrameRate(string frame_rate);
		void setTotalFrames(string total_frames);
		void setCfgCount(string cfg_count);
		void setVideoCount(string video_count);
		void setOutVideoPath(string out_video_path);
		void setOutLogPath(string out_log_path);




	private:
		
		vector<string> command_line;
		string mode_flag;
		string codec_eva_path;
		string codec_ref_path;
		string thread_count;
		string frame_rate;
		string total_frames;
		string cfg_count;
		string video_count;
		string out_video_path;
		string out_log_path;
		bool is_bkp;

	
		int computer_interval;
		int count_quant;
		
		vector<string> cfg_vet;
	    vector<string> coeficient_vet;
	    vector<Video> videos_vet;        
		vector<string> file_out_ref;
		vector<string> file_out_eva;

};
#endif
