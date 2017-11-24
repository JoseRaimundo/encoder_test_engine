#include "../include/MountTest.h"


MountTest::MountTest(vector<string> command_line){
	this->command_line = command_line;
    mountTest(this->command_line);
    //setar valores default
}

MountTest::~MountTest(){
}


void MountTest::mountTest(vector<string> command_line){
    mountBaseTest(command_line);
    mountCfgFile(command_line);
    mountVideos(command_line);
    mountQp(command_line);
    mountFile();
    mountFullCommands();


    this->test = new Test(
                    mode, 
    				enc_eva, 
    				enc_ref, 
    				threads, 
    				frame_rate, 
    				total_frames, 
    				out_video,	
    				out_log,
    				cfgs,
    				qps,
    				videos,
    				out_files,
    				out_files,
    				full_commands
    				);
}

Test* MountTest::getTest(){
    return this->test;
}


void MountTest::mountBaseTest(vector<string> command_line){
    for (int i = 1; i < command_line.size(); i++) {
        string temp_string = command_line[i-1];
        if(temp_string.compare("-mod") == 0){
            this->mode = command_line[i];
        }else if (temp_string.compare("-thr") == 0){
            this->threads = command_line[i];
        }else if (temp_string.compare("-eva") == 0){
            this->enc_eva = command_line[i];
            this->encoder_path.push_back(enc_eva);
        }else if (temp_string.compare("-ref") == 0){
            this->enc_ref = command_line[i];
            this->encoder_path.push_back(enc_ref);
        }else if (temp_string.compare("-outl") == 0){
            this->out_log = command_line[i];
        }else if (temp_string.compare("-outv") == 0){
            this->out_video = command_line[i];
        }else if (temp_string.compare("-f") == 0){
            this->total_frames = command_line[i];
        }else if (temp_string.compare("-fr") == 0){
            this->frame_rate = command_line[i];
        }
    }
}


void MountTest::mountCfgFile(vector<string> command_line){
	for (int i = 1; i < command_line.size(); i++) {
	    string temp_string = command_line[i-1];
	    if (temp_string.compare("-cfg") == 0){
            int cfg_count = conversorStrToInt(command_line[i++]);
            for (int j = 0; j < cfg_count; j++){
                this->cfgs.push_back(command_line[i++]);
            }
            break;
        }
	}
	//verifica se é null
	//passa para o test
}


void MountTest:: mountVideos(vector<string> command_line){
    //default values
	string 	width,
			height,
			video_subsampling = "4:2:0",
			frames = "300",
			bit_depth = "8";

	for (int i = 1; i < command_line.size(); i++) {
        string temp_string = command_line[i-1];
        if (temp_string.compare("-wdt") == 0){
            width = command_line[i];
        }else if (temp_string.compare("-hgt") == 0){
            height = command_line[i];
        }else if (temp_string.compare("-bdepth") == 0){
            bit_depth = command_line[i];
        }else if (temp_string.compare("-subsamp") == 0){
            video_subsampling = command_line[i];
        }
    }

    for (int i = 1; i < command_line.size(); i++) {
        string temp_string = command_line[i-1];
        if(temp_string.compare("-vin") == 0){
            int video_count = conversorStrToInt(command_line[i++]);
            for (int j = 0; j < video_count; j++){
                this->videos.push_back(Video("", command_line[i++], width, height, video_subsampling, frames, bit_depth));
            }
            break;
        }
    }
    //verifica se é null
}

void MountTest:: mountQp(vector<string> command_line){
	for (int i = 1; i < command_line.size(); i++) {
	    string temp_string = command_line[i-1];
	    if (temp_string.compare("-qp") == 0){
            int count_quant = conversorStrToInt(command_line[i++]);
            for (int j = 0; j < count_quant; j++){
                this->qps.push_back(command_line[i++]);
            }
            break;
        }      
	}
	//verifica se é null
}


int MountTest::conversorStrToInt(string str){
    stringstream convert(str); 
    int temp_nuber;
    if(!(convert >> temp_nuber))
        return 1;
    return temp_nuber;
}


string MountTest::removeInvalidChar(string text){
    string result = "";
    char temp;
    for (int i = 0; i < text.size(); i++){
        temp = text[i];
        if( temp >= '0' && temp <= '9' || 
            temp >= 65 && temp <= 90   || 
            temp >= 97 && temp <= 122) {
            result += temp;
        }
    }
    return result;
}

void MountTest:: mountFile(){
	for (int h = 0; h < encoder_path.size(); h++){
		for (int i = 0; i < cfgs.size(); i++){
			for (int j = 0; j < videos.size(); j++){
				for (int k = 0; k < qps.size(); k++){
					string command 	= 	removeInvalidChar(encoder_path[h])
									+	removeInvalidChar(cfgs[i])
									+	removeInvalidChar(videos[j].getVideoPaht())
									+	removeInvalidChar(qps[k]);
					this->out_files.push_back(command);
				}
			}
		}
	}
}

void MountTest:: mountFullCommands(){
	int out_cont = 0;
	for (int h = 0; h < encoder_path.size(); h++){
		for (int i = 0; i < cfgs.size(); i++){
			for (int j = 0; j < qps.size(); j++){
				for (int k = 0; k < videos.size(); k++){
					string command = " ./"  	+ this->encoder_path[h]
									+ " -f "  	+ this->total_frames
									+ " -fr "  	+ this->frame_rate
									+ " -c "  	+ this->cfgs[i] 
									+ " -q "  	+ this->qps[j] 
									+ " -wdt "	+ this->videos[k].getVideoWdt()
									+ " -hgt "	+ this->videos[k].getVideoHgt()
								    + " -i "  	+ this->videos[k].getVideoPaht()
									+ " -o " 	+ this->out_video 
												+ this->out_files[out_cont] + ".yuv" 
									+ " >> "	+ this->out_log
                                    + this->out_files[out_cont] + ".txt";
					out_cont++;
                    full_commands.push_back(command);
				}
			}
		}
	}
}
