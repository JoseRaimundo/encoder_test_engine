
#include "Controller.h"
//make clean; clear; make; ./bin/CodecTest -mod 1 -thr 2 -eva test/encoder/eva -ref test/encoder/ref -vin 1 test/vin/video.yuv -o test/vout/ -cfg 1 test/cfg/config.cfg

string result_file = "result_test.txt";

Controller::Controller(ManagerTest *input_test, vector<string> command_in){

    this->input_test = input_test;

    MountManagerTest mount_input_test = MountManagerTest(command_in);

    this->input_test = mount_input_test.getTest();

    

    // if(parse->isBkp()){
    //     std::fstream fs("backup/backup.txt");

    //     if (fs.is_open()) {
    //         string command;
    //         while(!fs.eof()){
    //             getline(fs,command);
    //             this->command_line.push_back(command);
    //         }
    //     }
    // }else{
    //     this->command_line  = parse->getCommand();
    // }
    
}


Controller::~Controller(){
}




