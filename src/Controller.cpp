#include "../include/common.h"
#include "../include/Controller.h"
#include "../include/CodecExecutor.h"
#include "../include/Bjontegaard.h"



Controller::Controller(const char *argv[], int argc){
    vector<string> command_in;
    this->is_bkp = false;
    for (int i = 0; i < argc; i++){
        command_in.push_back(argv[i]);
        if(command_in.back().compare("-bkp") == 0){
           this->is_bkp = true;
        }
    }

    InitController(command_in);
    this->count_execution  = parse->GetCommandCount();
    this->thread_qtd       = parse->GetThreadCount();
}

Controller::~Controller(){
}

void Controller::InitController(vector<string> command_in){
    std::fstream fs("backup.txt");
    if(this->is_bkp == true){
        if (fs.is_open()) {
            string command;
            while(!fs.eof()){
                getline(fs,command);
                this->command_line.push_back(command);
            }
        }
        
    }else{
        this->parse         = new Parse(command_in);
        this->command_line  = parse->GetCommand();
        if(fs.is_open()){
            remove("backup.txt");
        }
        ofstream file("backup.txt");
        
        for (int i = 0; i < this->command_line.size(); ++i) {
            file << this->command_line[i] << endl;
        }
        file.close();
    }
}

int Controller::ConversorStrToInt(string str){
    stringstream convert(str); 
    int temp_nuber;
    if(!(convert >> temp_nuber))
        return 1;
    return temp_nuber;
}

string Controller::ConversorIntToStr(int temp_nuber){
    stringstream convert;
    if(!(convert << temp_nuber))
        return "1";
    return convert.str();;
}


void Controller::Execute(){

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
    }

    gettimeofday(&end, NULL);
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
             end.tv_usec - start.tv_usec) / 1.e6;

    ofstream result("Result_test.txt", ios::app);
    if (!result){
        cout << "File couldn't open" << endl;
    }else{
        result << "Total time: " + ComputerTime(delta) << endl;
        result.close();
    }   

    parse->SetLogParameters();
    ComputerBjontegaard(parse->GetYPSNREva(), parse->GetBitRateEva(), parse->GetYPSNRRef(), parse->GetBitRateRef());
}




void Controller::ComputerBjontegaard( vector<double> psnr_eva, vector<double> rate_eva, vector<double> psnr_ref, vector<double> rate_ref){

    Bjontegaard *bjontegaard = new Bjontegaard(psnr_eva, rate_eva, psnr_ref, rate_ref);
    
    double avg  = bjontegaard->BD_avg();
    double rate = bjontegaard->BD_rate();
    
    ofstream result("Result_test.txt", ios::app);
    if (!result){
        cout << "File couldn't open" << endl;
    }else{
        result <<"Bjontegaard AVG .....:  " << avg << endl; 
        result <<"Bjontegaard Rate ....: " << rate <<endl;
    }
}


double Controller::TotalTime(string file_log){
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

string Controller::ComputerTime(double t_total){
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
    result_time =  ConversorIntToStr(d) + " : ";
    result_time += ConversorIntToStr(h) + " : ";
    result_time += ConversorIntToStr(m) + " : ";
    result_time += ConversorIntToStr(s);
    cout << result_time << endl;
    return result_time;
}