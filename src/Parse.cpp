#include "../include/Parse.h"


Parse::Parse(const char *argv[], int argc){
    vector<string> command_in;
    for (int i = 0; i < argc; i++){
        command_in.push_back(argv[i]);
    }
    InitParse();
	CommandManeger(command_in);
    CommandCodecMountEva();
    CommandCodecMountRef();
}

Parse::~Parse(){
}

void Parse::InitParse(){
	this->computer_interval = 0;
    this->mode_flag     = 1;
    this->video_count   = 1;
    this->cfg_count     = 1;
    this->wdt_codec     = 3840;
    this->hgt_codec     = 2160;
    this->f_rate        = 30;
    this->f_total       = 130;
}

string Parse::RemoveInvalidChar(string text){
	string result = "";
	char temp;
	for (int i = 0; i < text.size(); i++){
		temp = text[i];
		if(	temp >= '0' && temp <= '9' || 
			temp >= 65 && temp <= 90   || 
			temp >= 97 && temp <= 122) {
			result += temp;
		}
	}
	return result;
}

int Parse::ConversorStrToInt(string str){
    stringstream convert(str); 
    int temp_nuber;
    if(!(convert >> temp_nuber))
        return 1;
    return temp_nuber;
}

string Parse::ConversorIntToStr(int temp_nuber){
    stringstream convert;
    if(!(convert << temp_nuber))
        return "1";
    return convert.str();;
}

void Parse::CommandManeger(vector<string> command_line){
    int count_quant,
        coef_flag = 0;

    string temp_string, temp_aux;
    
    for (int i = 1; i < command_line.size(); i++) {
        temp_string = command_line[i-1];
        if(temp_string.compare("-mod") == 0){
            this->mode_flag = ConversorStrToInt(command_line[i]);
        }else if (temp_string.compare("-thr") == 0){
            this->thread_count = ConversorStrToInt(command_line[i]);
        }else if (temp_string.compare("-outl") == 0){
            this->out_log_path = command_line[i];
        }else if (temp_string.compare("-outv") == 0){
            this->out_video_path = command_line[i];
        }else if (temp_string.compare("-f") == 0){
            this->f_total = ConversorStrToInt(command_line[i]);
        }else if (temp_string.compare("-fr") == 0){
            this->f_rate = ConversorStrToInt(command_line[i]);
        }else if (temp_string.compare("-wdt") == 0){
            this->wdt_codec = ConversorStrToInt(command_line[i]);
        }else if (temp_string.compare("-hgt") == 0){
            this->hgt_codec = ConversorStrToInt(command_line[i]);
        }else if (temp_string.compare("-eva") == 0){
            this->codec_eva_path = command_line[i];
        }else if (temp_string.compare("-ref") == 0){
            this->codec_ref_path = command_line[i];
        }else if(temp_string.compare("-vin") == 0){
            //ver se melhora
            this->video_count = ConversorStrToInt(command_line[i++]);
            for (int j = 0; j < this->video_count; j++){
                videos_vet.push_back(command_line[i++]);
            }
        }else if (temp_string.compare("-cfg") == 0){
            this->cfg_count = ConversorStrToInt(command_line[i++]);
            for (int j = 0; j < this->cfg_count; j++){
                this->cfg_vet.push_back(command_line[i++]);
            }
        }else if (temp_string.compare("-coef") == 0){
            count_quant = ConversorStrToInt(command_line[i++]);
            for (int j = 0; j < count_quant; j++){
                this->coeficient_vet.push_back(command_line[i++]);
            }
            coef_flag = 1;
        }      
    }

    if (coef_flag != 1){//default value
        this->coeficient_vet.push_back("22");
        this->coeficient_vet.push_back("27");
        this->coeficient_vet.push_back("32");
        this->coeficient_vet.push_back("37");
        this->count_quant = coeficient_vet.size();
    }
}

//COMANDOS DO CODIFICADOR AVALIADO
void Parse::CommandCodecMountEva(){
    string temp_string;
    for (int i = 0; i < this->cfg_vet.size(); i++){
        for (int j = 0; j < this->videos_vet.size(); j++){
            for (int k = 0; k < this->coeficient_vet.size(); k++) {
                temp_string = "";
                temp_string =     "."    + this->codec_eva_path + " "
                                + "-c "  + this->cfg_vet[i] + " "
                                + "-q "  + this->coeficient_vet[k] + " "
                                + "-fr " + ConversorIntToStr(this->f_rate) + " "
                                + "-f "  + ConversorIntToStr(this->f_total) + " "
                                + "-wdt "+ ConversorIntToStr(this->wdt_codec) + " "
                                + "-hgt "+ ConversorIntToStr(this->hgt_codec) + " "
                                + "-i "  + this->videos_vet[j] + " "
                                + "-o "  + this->out_video_path + "_"
                                + RemoveInvalidChar(this->videos_vet[j]) + "_" 
                                + RemoveInvalidChar(this->cfg_vet[i]) + "_" 
                                + RemoveInvalidChar(this->coeficient_vet[k]) + "eva_.yuv >";

                this->file_out_eva.push_back(this->out_log_path + "eva_" 
                                        + RemoveInvalidChar(this->videos_vet[j]) + "_" 
                                        + RemoveInvalidChar(this->cfg_vet[i]) + "_" 
                                        + RemoveInvalidChar(this->coeficient_vet[k]) + ".txt ");

                temp_string += file_out_eva.back();            
                this->command_line.push_back(temp_string);
            }
        }
    }
}

//COMANDOS DO CODIFICADOR REFERENCIA
void Parse::CommandCodecMountRef(){
    string temp_string;
    for (int i = 0; i < this->cfg_vet.size(); i++){
        for (int j = 0; j < this->videos_vet.size(); j++){
            for (int k = 0; k < this->coeficient_vet.size(); k++) {
                temp_string = "";
                temp_string =     "."    + this->codec_ref_path + " "
                                + "-c "  + this->cfg_vet[i] + " "
                                + "-q "  + this->coeficient_vet[k] + " "
                                + "-fr " + ConversorIntToStr(this->f_rate) + " "
                                + "-f "  + ConversorIntToStr(this->f_total) + " "
                                + "-wdt "+ ConversorIntToStr(this->wdt_codec) + " "
                                + "-hgt "+ ConversorIntToStr(this->hgt_codec) + " "
                                + "-i "  + this->videos_vet[j] + " "
                                + "-o "  + this->out_video_path + "_"
                                + RemoveInvalidChar(this->videos_vet[j]) + "_" 
                                + RemoveInvalidChar(this->cfg_vet[i]) + "_" 
                                + RemoveInvalidChar(this->coeficient_vet[k]) + "ref_.yuv > ";

                this->file_out_ref.push_back(this->out_log_path + "ref_" 
                                        + RemoveInvalidChar(this->videos_vet[j]) + "_" 
                                        + RemoveInvalidChar(this->cfg_vet[i]) + "_" 
                                        + RemoveInvalidChar(this->coeficient_vet[k]) + ".txt ");

                temp_string += file_out_ref.back();            
                this->command_line.push_back(temp_string);
            }
        }
    }
}


vector<string> Parse::GetCommand(){
	return this->command_line;
}

int Parse::GetThreadCount(){
    return this->thread_count;
}

int Parse::GetMode(){
    return this->mode_flag;
}


void Parse::FindInFile(string file_log, int codec_flag){
	ifstream cod_file;
	string temp_string;
    cod_file.open(file_log.c_str());

    if(!cod_file.is_open()){
        cout << "Erro ref, arquivo não encontrado!" << endl;
    }
    //set evaluated codec log
    if(codec_flag == 1){
    	while(!cod_file.eof()){
    		cod_file >> temp_string;
    		if(temp_string.compare("YUV-PSNR") == 0){
                cod_file >> temp_string;
                total_frames_eva.push_back(atof(temp_string.c_str()));
                cod_file >> temp_string;
                cod_file >> temp_string;
                bit_rate_eva.push_back(atof(temp_string.c_str()));
                cod_file >> temp_string;
                ypsnr_eva.push_back(atof(temp_string.c_str()));
                cod_file >> temp_string;
                upsnr_eva.push_back(atof(temp_string.c_str()));
                cod_file >> temp_string;
                vpsnr_eva.push_back(atof(temp_string.c_str()));
                cod_file >> temp_string;
                yuvpsnr_eva.push_back(atof(temp_string.c_str()));
    			break;
    		}
    	}
    }else{
        while(!cod_file.eof()){
            cod_file >> temp_string;
            if(temp_string.compare("YUV-PSNR") == 0){
                cod_file >> temp_string;
                total_frames_ref.push_back(atof(temp_string.c_str()));
                cod_file >> temp_string;
                cod_file >> temp_string;
                bit_rate_ref.push_back(atof(temp_string.c_str()));
                cod_file >> temp_string;
                ypsnr_ref.push_back(atof(temp_string.c_str()));
                cod_file >> temp_string;
                upsnr_ref.push_back(atof(temp_string.c_str()));
                cod_file >> temp_string;
                vpsnr_ref.push_back(atof(temp_string.c_str()));
                cod_file >> temp_string;
                yuvpsnr_ref.push_back(atof(temp_string.c_str()));      
                cod_file.close();
                break;
            }
        }
    }
} 



void Parse::SetLogParameters(){
    for (int i = 0; i < file_out_eva.size(); i++){
        FindInFile(file_out_eva[i], 1);
    }

	for (int i = 0; i < file_out_ref.size(); i++){
		FindInFile(file_out_ref[i], 2);
	}
}




