#include "../include/MountInputTest.h"


MountInputTest::MountInputTest(vector<string> command_line){
	this->command_line = command_line;
    //setar valores default
    mountInputTest(this->command_line);
}

MountInputTest::~MountInputTest(){
}


void MountInputTest::mountInputTest(vector<string> command_line){
    mountBaseTest(command_line);
    mountCfgFile(command_line);
    mountVideos(command_line);
    mountQp(command_line);
    mountFile();
    mountFullCommands();


    this->input_test = new InputTest(
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

InputTest* MountInputTest::getTest(){
    return this->input_test;
}


void MountInputTest::mountBaseTest(vector<string> command_line){
    //test values
    this->frame_rate    = "30";
    this->total_frames  = "130";
    this->mode = "1";
    this->enc_eva = "test/codec/eva/TAppEncoderStatic";
    this->enc_ref = "test/codec/ref/TAppEncoderStatic";
    this->out_video = "test/videosout/";
    this->threads = "1";

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


void MountInputTest::mountCfgFile(vector<string> command_line){
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
    //test value
    if (this->cfgs.size() == 0) {
        this->cfgs.push_back("test/cfg/config.cfg");
    }
}


void MountInputTest:: mountVideos(vector<string> command_line){
    //test values
	string 	width              = "352",
			height             = "288",
			video_subsampling  = "4:2:0",
			frames             = "300",
			bit_depth          = "8";

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
    if (this->videos.size() == 0) {
        this->videos.push_back(Video("video_test", "test/videos/video.yuv", width, height, video_subsampling, frames, bit_depth));
    }
}

void MountInputTest:: mountQp(vector<string> command_line){
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
    //test values
	if (this->qps.size() ==0){
         this->qps.push_back("22");
         this->qps.push_back("27");
         this->qps.push_back("32");
         this->qps.push_back("37");
    }
}


int MountInputTest::conversorStrToInt(string str){
    stringstream convert(str); 
    int temp_nuber;
    if(!(convert >> temp_nuber))
        return 1;
    return temp_nuber;
}


string MountInputTest::removeInvalidChar(string text){
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

void MountInputTest:: mountFile(){
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

void MountInputTest:: mountFullCommands(){
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
