#include "../include/Video.h"


Video::Video(string video_nome, string video_paht, string video_wdt, string video_hgt, string video_subsampling, string frames, string bit_depth){
	this->video_nome 		= video_nome; 	
	this->video_paht 		= video_paht; 	
	this->video_wdt 		= video_wdt;	
	this->video_hgt 		= video_hgt;	
	this->video_subsampling = video_subsampling;	
	this->frames 			= frames;	
	this->bit_depth 		= bit_depth;	
}

Video::~Video() {
}


void Video::setVideoNome(string video_nome) { 
	this->video_nome = video_nome; 
} 

string Video::getVideoNome() { 
	return this->video_nome; 
}

void Video::setVideoPaht(string video_paht) { 
	this->video_paht = video_paht; 
} 

string Video::getVideoPaht() { 
	return this->video_paht; 
}

void Video::setVideoWdt(string video_wdt) { 
	this->video_wdt = video_wdt; 
} 

string Video::getVideoWdt() { 
	return this->video_wdt; 
}

void Video::setVideoHgt(string video_hgt) { 
	this->video_hgt = video_hgt; 
} 

string Video::getVideoHgt() { 
	return this->video_hgt; 
}

void Video::setVideoSubsampling(string video_subsampling) { 
	this->video_subsampling = video_subsampling; 
} 

string Video::getVideoSubsampling() { 
	return this->video_subsampling; 
}

void Video::setFrames(string frames) { 
	this->frames = frames; 
} 

string Video::getFrames() { 
	return this->frames; 
}

void Video::setBitDepth(string bit_depth) { 
	this->bit_depth = bit_depth; 
} 

string Video::getBitDepth() { 
	return this->bit_depth; 
}