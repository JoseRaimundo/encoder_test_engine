#include "../include/InputTest.h"


InputTest::InputTest(	string mode_flag, 
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
				    	vector<Video> 	videos_vet ){

		this->mode_flag			= mode_flag; 
		this->encoder_eva  	= encoder_eva; 
		this->encoder_ref	= encoder_ref; 
		this->decoder	= decoder; 
		this->thread_count		= thread_count; 
		this->frame_rate 		= frame_rate; 
		this->total_frames 		= total_frames; 
		this->out_video_path	= out_video_path; 
		this->out_log_path 		= out_log_path; 
		this->cfg_vet			= cfg_vet;
		this->qp_vet	= qp_vet;
		this->unit_tests      	= unit_tests;
		this->videos_vet      	= videos_vet;
}


InputTest::~InputTest() {
}

vector<UnitTest> InputTest::getTests(){
	return this->unit_tests;
}


int InputTest::getCommandCount() {
	return this->unit_tests.size(); 
}


void InputTest::setModeFlag(string mode_flag) {
	this->mode_flag = mode_flag; 
}

string InputTest::getModeFlag() {
	return this->mode_flag; 
}


void InputTest::setThreadCount(string thread_count) {
	this->thread_count = thread_count;
}

string InputTest::getThreadCount() {
	return this->thread_count; 
}

void InputTest::setFrameRate(string frame_rate) {
	this->frame_rate = frame_rate;
}

string InputTest::getFrameRate() {
	return this->frame_rate; 
}

void InputTest::setTotalFrames(string total_frames) {
	this->total_frames = total_frames;
}

string InputTest::getTotalFrames() {
	return this->total_frames; 
}

