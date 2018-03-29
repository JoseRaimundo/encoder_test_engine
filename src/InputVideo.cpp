#include "InputVideo.h"


InputVideo::InputVideo( string video_nome, 
						string video_paht, 
						string video_wdt, 
						string video_hgt, 
						string video_subsampling, 
						string frames, 
						string bit_depth){
	
	this->video_nome 		= video_nome; 	
	this->video_paht 		= video_paht; 	
	this->video_wdt 		= video_wdt;	
	this->video_hgt 		= video_hgt;	
	this->video_subsampling = video_subsampling;	
	this->frames 			= frames;	
	this->bit_depth 		= bit_depth;	
}

InputVideo::~InputVideo() {
}


void InputVideo::setVideoNome(string video_nome) { 
	this->video_nome = video_nome; 
} 

string InputVideo::getVideoNome() { 
	return this->video_nome; 
}

void InputVideo::setVideoPaht(string video_paht) { 
	this->video_paht = video_paht; 
} 

string InputVideo::getVideoPaht() { 
	return this->video_paht; 
}

void InputVideo::setVideoWdt(string video_wdt) { 
	this->video_wdt = video_wdt; 
} 

string InputVideo::getVideoWdt() { 
	return this->video_wdt; 
}

void InputVideo::setVideoHgt(string video_hgt) { 
	this->video_hgt = video_hgt; 
} 

string InputVideo::getVideoHgt() { 
	return this->video_hgt; 
}

void InputVideo::setVideoSubsampling(string video_subsampling) { 
	this->video_subsampling = video_subsampling; 
} 

string InputVideo::getVideoSubsampling() { 
	return this->video_subsampling; 
}

void InputVideo::setFrames(string frames) { 
	this->frames = frames; 
} 

string InputVideo::getFrames() { 
	return this->frames; 
}

void InputVideo::setBitDepth(string bit_depth) { 
	this->bit_depth = bit_depth; 
} 

string InputVideo::getBitDepth() { 
	return this->bit_depth; 
}