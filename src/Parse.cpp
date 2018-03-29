#include "Parse.h"



LogFile Parse::parseLog(string file_path){
    double  y_psnr,
            u_pnsr,
            v_psnr;

    double bit_rate;

    double total_time;

    double total_frames;

    ifstream cod_file;
    string temp_string;
    bool chave = true;
    cod_file.open(file_path.c_str());

    //set evaluated codec log
    if(!cod_file.is_open()){
            cout << "Error, file not found: " << file_path << endl;
            //return NULL;
    }

    while(!cod_file.eof()){
        cod_file >> temp_string;
        if(temp_string.compare("YUV-PSNR") == 0 && chave){
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
    return LogFile( y_psnr, u_pnsr, v_psnr, bit_rate, total_time);  
}
