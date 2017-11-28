
#include "../include/Controller.h"
//make clean; clear; make; ./bin/CodecTest -mod 1 -thr 2 -eva test/codec/eva/TAppEncoderStatic -ref test/codec/ref/TAppEncoderStatic -vin 1 test/videos/video.yuv -o test/videosout/ -cfg 1 test/cfg/config.cfg

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
    this->input_test       = mount_input_test.getTest();
    this->parse            = new Parse();
    
    std::vector<string> v  = input_test->getFileOutEva();;

    this->count_execution  = input_test->getCommandCount();
    this->command_line     = input_test->getCommandLine();
    this->thread_qtd       = conversorStrToInt(input_test->getThreadCount());
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

int Controller::conversorStrToInt(string str){
    stringstream convert(str); 
    int temp_nuber;
    if(!(convert >> temp_nuber))
        return 0;
    return temp_nuber;
}

string Controller::conversorIntToStr(int temp_nuber){
    stringstream convert;
    if(!(convert << temp_nuber))
        return "0";
    return convert.str();;
}


void Controller::executeEncodes(){

    struct timeval start, end;
    gettimeofday(&start, NULL);

    CodecExecutor *codec_executor[command_line.size()];

    for (int i = 0; i < command_line.size(); i++){
        if (count_execution < thread_qtd)   {
            thread_qtd = count_execution;       
        }
    
        for (int j = 0; j < thread_qtd; j++){
            codec_executor[j] = new CodecExecutor(command_line[i++]);   
            codec_executor[j]->start();         

        }

        i--;

        for (int j = 0; j < thread_qtd; j++){
            codec_executor[j]->join();  
        }

        for (int j = 0; j < thread_qtd; j++){
            delete codec_executor[j];   
            count_execution--;  
        }

        // ofstream file("backup/backup.txt");
        // for (int j = i+1; j < this->command_line.size(); j++) {
        //     file << this->command_line[j] << endl;
        // }
        // file.close();
    }

    gettimeofday(&end, NULL);
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
             end.tv_usec - start.tv_usec) / 1.e6;

    ofstream result("Result_test.txt", ios::app);
    if (!result){
        cout << "File couldn't open" << endl;
    }else{
        result << "Total time: " + computerTime(delta) << endl;
        result.close();
    }   






    //parse->setLogParameters();
   // computerBjontegaard(parse->getYPSNREva(), parse->getBitRateEva(), parse->getYPSNRRef(), parse->getBitRateRef());
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

string Controller::computerTime(double t_total){
    int d = 0, 
        h = 0, 
        m = 0, 
        s = 0,
        aux = (int) t_total;

    string result_time;

    if (aux >= 86400) {
        d = aux/86400;
        aux = aux % 86400;
    }

    if (aux >= 3600){
        h = aux/3600;
        aux = aux % 3600;
    }

    if(aux >= 60){
        m = aux/60;
        aux = aux % 60;
    }
    s = aux;
    result_time =  conversorIntToStr(d) + " : ";
    result_time += conversorIntToStr(h) + " : ";
    result_time += conversorIntToStr(m) + " : ";
    result_time += conversorIntToStr(s);
    cout << result_time << endl;
    return result_time;
}