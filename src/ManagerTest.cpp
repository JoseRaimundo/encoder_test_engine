#include "ManagerTest.h"


ManagerTest::ManagerTest(	string mode_flag, 
              				string thread_count,
              				vector<UnitTest> unit_tests,
              				vector<InputVideo> 	videos_vet){

		this->thread_qtd	= converterStrToInt(thread_count); 
		this->unit_tests    = unit_tests;
		this->videos_vet    = videos_vet;
}
   

ManagerTest::~ManagerTest() {
}


int ManagerTest::converterStrToInt(string str){
    stringstream convert(str); 
    int temp_nuber;
    if(!(convert >> temp_nuber))
        return 0;
    return temp_nuber;
}


void ManagerTest::executeEncodes(){

	int total_tests 	= this->unit_tests.size(); 
    int current_test 	= 0;
    int count_execution = total_tests;

    EncoderExec *encoder_exec[total_tests];

    for (int i = 0; i < total_tests; i++){
        if (count_execution < this->thread_qtd)   {
            this->thread_qtd = count_execution;       
        }
    
        for (int j = 0; j < this->thread_qtd; j++){
            cout << this->unit_tests[i].getCommand() << endl;
            encoder_exec[j] = new EncoderExec(this->unit_tests[i++].getCommand());   
            encoder_exec[j]->start();  
        }

        i--;

        for (int j = 0; j < this->thread_qtd; j++){
            encoder_exec[j]->join();  
        }

        for (int j = 0; j < this->thread_qtd; j++){
            
            // delete encoder_exec[j];   
            //fazer
            // ofstream file("backup/backup.txt");
    
            // file << this->command_line[j] << endl;
     
            //     file.close();
            //this->unit_tests[current_test].setStatus(COMPLETE);
            count_execution--;  
        }       
    }
}


vector<UnitTest> ManagerTest::getUnitTests(){
    return this->unit_tests;
}