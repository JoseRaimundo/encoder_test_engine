
#include "../include/Controller.h"
//make clean; clear; make; ./bin/CodecTest -mod 1 -thr 2 -eva test/codec/eva/TAppEncoderStatic -ref test/codec/ref/TAppEncoderStatic -vin 1 test/videos/video.yuv -o test/videosout/ -cfg 1 test/cfg/config.cfg

string result_file = "result_test.txt";

Controller::Controller(const char *argv[], int argc){
    initController(argv, argc);
}

Controller::~Controller(){
}

void Controller::initController(const char *argv[], int argc){
    vector<string> command_in;
    for (int i = 0; i < argc; i++){
        command_in.push_back(argv[i]);
    }

    MountInputTest mount_input_test = MountInputTest(command_in);

    //init class
    this->input_test        = mount_input_test.getTest();
    this->total_tests       = input_test->getCommandCount();

    this->test_units        = input_test->getTests();
    this->thread_qtd        = converterStrToInt(input_test->getThreadCount());

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



void Controller::executeEncodes(){

    struct timeval start, end;
    gettimeofday(&start, NULL);

    int current_test = 0;
    count_execution = total_tests;
    EncoderExec *encoder_exec[total_tests];

    for (int i = 0; i < total_tests; i++){

        if (count_execution < thread_qtd)   {
            thread_qtd = count_execution;       
        }
    
        for (int j = 0; j < thread_qtd; j++){
            // if(this->test_units[i].getStatus() == COMPLETE){
            //     i++;
            //     continue;
            // }
            cout << this->test_units[i].getCommand() << endl;
            encoder_exec[j] = new EncoderExec(this->test_units[i++].getCommand());   
            encoder_exec[j]->start();         

        }

        i--;

        for (int j = 0; j < thread_qtd; j++){
            encoder_exec[j]->join();  
        }

        for (int j = 0; j < thread_qtd; j++){
            delete encoder_exec[j];   
            
            //fazer
            // ofstream file("backup/backup.txt");
    
            // file << this->command_line[j] << endl;
     
            //     file.close();


            this->file_logs.push_back(Parse::parseLog(this->test_units[current_test++].getOutFile()));

            this->test_units[current_test].setStatus(COMPLETE);
            count_execution--;  
        }
       
    }

    // //se a métrica bjontegaard estiver ativa entra aqui
    // if (true){



    //     vector<double> psnr_eva;
    //     vector<double> rate_eva;
    //     vector<double> psnr_ref;
    //     vector<double> rate_ref;

    //     int block_test = 0;

    //     //take evaluate encoder variables
    //     for (int i = block_test; i < MAX_QP + block_test; ++i) {
    //         psnr_eva.push_back(this->file_logs[i++].getOutFile())
    //     }

    //     block_test += MAX_QP;

    //     for (int i = block_test; i < MAX_QP + block_test; ++i) {
    //         /* code */
    //     }
        
    // }

    

   // if(true){ //metricas atividas

        // //decoding all videos
        // ComputerMetric *computer_metric[total_tests];
        // for (int i = 0; i < total_tests; i++){

        //     int current_test = 0;
        //     count_execution = total_tests;

        //     if (count_execution < thread_qtd)   {
        //         thread_qtd = count_execution;       
        //     }
        
        //     for (int j = 0; j < thread_qtd; j++){
        //         computer_metric[j] = new ComputerMetric(this->test_units[i].getOutVideo(),
        //                                                 this->test_units[i].getInputVideo(),
        //                                                 0);   
        //         computer_metric[j]->start();         
        //     }

        //     i--;

        //     for (int j = 0; j < thread_qtd; j++){
        //         computer_metric[j]->join();  
        //     }

        //     for (int j = 0; j < thread_qtd; j++){
        //         delete computer_metric[j];   
        //         count_execution--;  
        //     }
        // }  

            // computerBjontegaard(parse->getYPSNREva(), parse->getBitRateEva(), parse->getYPSNRRef(), parse->getBitRateRef());

        gettimeofday(&end, NULL);
        double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
                 end.tv_usec - start.tv_usec) / 1.e6;

        ofstream result(result_file.c_str(), ios::app);
        if (!result){
            cout << "File couldn't open" << endl;
        }else{
            result << "Total time: " + FormatTime::formatTime(delta) << endl;
            result.close();
        } 
    //}
}


void Controller::computerBjontegaard( vector<double> psnr_eva, vector<double> rate_eva, vector<double> psnr_ref, vector<double> rate_ref){

    Bjontegaard *bjontegaard = new Bjontegaard(psnr_eva, rate_eva, psnr_ref, rate_ref);
    
    double avg  = bjontegaard->bdAvg();
    double rate = bjontegaard->bdRate();
    
    ofstream result("Result_test.txt", ios::app);
    if (!result){
        cout << "File couldn't open" << endl;
    }else{
        result <<"Bjontegaard AVG .....:  " << avg << endl; 
        result <<"Bjontegaard Rate ....: " << rate <<endl;
    }
}


double Controller::totalTime(string file_log){
    ifstream cod_file;
    cod_file.open(file_log.c_str());

    if(!cod_file.is_open()){
        cout << "Erro ref, arquivo não encontrado!" << endl;
        return 0;
    }

    string temp_string;
    double temp_aux = 0;

    while(!cod_file.eof()){
        cod_file >> temp_string;
        temp_aux += atof(temp_string.c_str());
    }
    return temp_aux;    
} 





int Controller::converterStrToInt(string str){
    stringstream convert(str); 
    int temp_nuber;
    if(!(convert >> temp_nuber))
        return 0;
    return temp_nuber;
}
