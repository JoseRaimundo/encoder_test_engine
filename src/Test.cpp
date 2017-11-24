#include "../include/Test.h"


Test::Test(	string mode_flag, string codec_eva_path, string codec_ref_path, string thread_count, 
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


Test::~Test() {
}



int Test::getCommandCount() {
	return this->command_line.size(); 
}


void Test::setModeFlag(string mode_flag) {
	this->mode_flag = mode_flag; 
}

string Test::getModeFlag() {
	return this->mode_flag; 
}

void Test::setCodecEvaPath(string codec_eva_path) {
	this->codec_eva_path = codec_eva_path;
}

string Test::getCodecEvaPath() {
	return this->codec_eva_path; 
}

void Test::setCodecRefPath(string codec_ref_path) {
	this->codec_ref_path = codec_ref_path;
}

string Test::getCodecRefPath() {
	return this->codec_ref_path; 
}

void Test::setThreadCount(string thread_count) {
	this->thread_count = thread_count;
}

string Test::getThreadCount() {
	return this->thread_count; 
}

void Test::setFrameRate(string frame_rate) {
	this->frame_rate = frame_rate;
}

string Test::getFrameRate() {
	return this->frame_rate; 
}

void Test::setTotalFrames(string total_frames) {
	this->total_frames = total_frames;
}

string Test::getTotalFrames() {
	return this->total_frames; 
}

void Test::setCfgCount(string cfg_count) {
	this->cfg_count = cfg_count;
}

string Test::getCfgCount() {
	return this->cfg_count; 
}

void Test::setVideoCount(string video_count) {
	this->video_count = video_count;
}

string Test::getVideoCount() {
	return this->video_count; 
}

void Test::setOutVideoPath(string out_video_path) {
	this->out_video_path = out_video_path;
}

string Test::getOutVideoPath() {
	return this->out_video_path; 
}

void Test::setOutLogPath(string out_log_path) {
	this->out_log_path = out_log_path;
}

string Test::getOutLogPath() {
	return this->out_log_path; 
}

vector<string> Test::getCommandLine() {
	return this->command_line; 
}
