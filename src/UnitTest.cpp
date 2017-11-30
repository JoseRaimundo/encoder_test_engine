#include "../include/UnitTest.h"


UnitTest::UnitTest(string command, string out_log, string out_video, string encoder, string decoder){
	this->command 	= command ;
	this->out_log	= out_log;
	this->out_video	= out_video;
	this->encoder	= encoder;
	this->decoder	= decoder;
	this->status_test = 0;
}

// UnitTest::UnitTest(string command, string out_log, string out_video, string encoder, string decoder, int status_test){
// 	this->command 	= command ;
// 	this->out_log	= out_log;
// 	this->out_video	= out_video;
// 	this->encoder	= encoder;
// 	this->decoder	= decoder;
// 	this->status_test = status_test;
// }
// UnitTest::UnitTest(){
// }


UnitTest::~UnitTest() {
}

string UnitTest::getCommand(){
	return this->command;
}


string UnitTest::getOutFile(){
	return this->out_log;
}

void UnitTest::setStatus(int status){
	this->status_test = status;
}

int UnitTest::getStatus(){
	return this->status_test;
}