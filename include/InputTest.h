#ifndef InputTest_H
#define InputTest_H

#include "common.h"

using namespace std;

class InputTest{

	public:
		InputTest(string mode_flag, 
			string encoder_eva, 
			string encoder_ref, 
			string decoder, 
			string thread_count, 
			string frame_rate,
			string total_frames, 
			string out_video_path,
			string out_log_path,
			vector<string> qp_vet,
			vector<string> cfg_vet,
	    	vector<UnitTest> unit_tests,
	    	vector<Video> 	videos_vet    
		);

		~InputTest();


		string getModeFlag();
		string getCodecEvaPath();
		string getCodecRefPath();
		string getThreadCount();
		string getFrameRate();
		string getTotalFrames();

		int getCommandCount();
		


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

		vector<UnitTest> getTests();




	private:

		string mode_flag; 
		string encoder_eva; 
		string encoder_ref; 
		string decoder; 
		string thread_count; 
		string frame_rate;
		string total_frames; 
		string out_video_path;
		string out_log_path;
		vector<string> qp_vet;
		vector<string> cfg_vet;
    	vector<UnitTest> unit_tests;
    	vector<Video> 	videos_vet;
};
#endif
