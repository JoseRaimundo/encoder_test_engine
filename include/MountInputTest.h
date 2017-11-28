#ifndef MountInputTest_H
#define MountInputTest_H

#include "common.h"


using namespace std;

class MountInputTest{

	public:
		MountInputTest(vector<string> command_line);
		InputTest* getTest();
		~MountInputTest();

	private:
		void 	mountInputTest(vector<string> command_line);
		void  	mountBaseTest(vector<string> command_line);
		void  	mountCfgFile(vector<string> command_line);
		void  	mountVideos(vector<string> command_line);
		void  	mountQp(vector<string> command_line);
		int 	conversorStrToInt(string str);
		void  	mountFullCommands();
		string 	removeInvalidChar(string text);
		void  mountFile();



		InputTest *input_test;

		vector<string> command_line;
		vector<string> 	cfgs;
		vector<string> 	qps;
		vector<string> 	out_files;
		vector<string> 	encoder_path;
		vector<string> 	full_commands;
		vector<Video> 	videos;

		string 	enc_eva,
				enc_ref,
				mode,
				threads,
				out_log,
				out_video,
				total_frames,
				frame_rate;


};
#endif