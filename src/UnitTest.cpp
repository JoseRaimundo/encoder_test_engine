#include "UnitTest.h"

UnitTest::UnitTest(	int id_test, 
					string command, 
					string out_log, 
					string input_video, 
					string out_video, 
					string encoder,
					string qp){

	this->id_test 	= id_test;
	this->command 	= command ;
	this->out_log	= out_log;
	this->input_video = input_video;
	this->out_video	= out_video;
	this->encoder	= encoder;
	this->status_test = 0,
	this->qp = qp;
}

UnitTest::~UnitTest() {
}

string UnitTest::getCommand(){
	return this->command;
}

string UnitTest::getQP(){
	return this->qp;
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


string UnitTest::getOutVideo(){
	return this->out_video;
}

string UnitTest::getInputVideo(){
	return this->input_video;
}
