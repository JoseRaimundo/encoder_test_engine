#include "../include/InputTest.h"


InputTest::InputTest(	string mode_flag, string codec_eva_path, string codec_ref_path, string thread_count, 
			string frame_rate,	string total_frames, string cfg_count, string out_log_path,
			vector<string> cfg_vet, vector<string> coeficient_vet, vector<Video> videos_vet,        
			vector<string> file_out_ref, vector<string> file_out_eva, vector<string> command_line){

	this->mode_flag			= mode_flag; 
	this->codec_eva_path  	= codec_eva_path; 
	this->codec_ref_path	= codec_ref_path; 
	this->thread_count		= thread_count; 
	this->frame_rate 		= frame_rate; 
	this->total_frames 		= total_frames; 
	this->out_video_path	= out_video_path; 
	this->out_log_path 		= out_log_path; 

	this->cfg_vet			= cfg_vet;
	this->coeficient_vet	= coeficient_vet;
	this->videos_vet      	= videos_vet;
	this->file_out_ref		= file_out_ref;
	this->file_out_eva		= file_out_eva;
	this->command_line		= command_line;

}


InputTest::~InputTest() {
}


// vector<string> InputTest::getFileOutRef() {
// 	return this->file_out_ref;
// }

vector<string> InputTest::getFileOutEva() {
	return this->file_out_eva;
}


int InputTest::getCommandCount() {
	return this->command_line.size(); 
}


void InputTest::setModeFlag(string mode_flag) {
	this->mode_flag = mode_flag; 
}

string InputTest::getModeFlag() {
	return this->mode_flag; 
}

void InputTest::setCodecEvaPath(string codec_eva_path) {
	this->codec_eva_path = codec_eva_path;
}

string InputTest::getCodecEvaPath() {
	return this->codec_eva_path; 
}

void InputTest::setCodecRefPath(string codec_ref_path) {
	this->codec_ref_path = codec_ref_path;
}

string InputTest::getCodecRefPath() {
	return this->codec_ref_path; 
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

void InputTest::setCfgCount(string cfg_count) {
	this->cfg_count = cfg_count;
}

string InputTest::getCfgCount() {
	return this->cfg_count; 
}

void InputTest::setVideoCount(string video_count) {
	this->video_count = video_count;
}

string InputTest::getVideoCount() {
	return this->video_count; 
}

void InputTest::setOutVideoPath(string out_video_path) {
	this->out_video_path = out_video_path;
}

string InputTest::getOutVideoPath() {
	return this->out_video_path; 
}

void InputTest::setOutLogPath(string out_log_path) {
	this->out_log_path = out_log_path;
}

string InputTest::getOutLogPath() {
	return this->out_log_path; 
}

vector<string> InputTest::getCommandLine() {
	return this->command_line; 
}
