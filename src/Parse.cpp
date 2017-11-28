#include "../include/Parse.h"


Parse::Parse(){
}

Parse::~Parse(){
}

int Parse::findInFile(string file_path){
    double  y_psnr,
            u_pnsr,
            v_psnr;

    double bit_rate;

    double total_time;

    ifstream cod_file;
    string temp_string;
    bool chave = true;
    cod_file.open(file_path.c_str());

    //set evaluated codec log
    if(!cod_file.is_open()){
            cout << "Erro eva, arquivo não encontrado!" << endl;
            return 0;
    }
    while(!cod_file.eof()){
        cod_file >> temp_string;
        if(temp_string.compare("YUV-PSNR") == 0 || chave){
            cod_file >> temp_string;
            total_frames = atof(temp_string.c_str());
            cod_file >> temp_string;
            cod_file >> temp_string;
            bit_rate = atof(temp_string.c_str());
            cod_file >> temp_string;
            y_psnr = atof(temp_string.c_str());
            cod_file >> temp_string;
            u_pnsr= atof(temp_string.c_str());
            cod_file >> temp_string;
            v_psnr = atof(temp_string.c_str());
            chave = false;
        }

        if(temp_string.compare("Time:") == 0){
            cod_file >> temp_string;
            total_time= atof(temp_string.c_str());
            break;
        }
    }
    this->log_file = new LogFile( y_psnr, u_pnsr, v_psnr, bit_rate, total_time);    
    return 1;
}


LogFile* Parse::getFile(){
    return this->log_file;
}

