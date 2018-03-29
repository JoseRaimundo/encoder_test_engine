#include "MountManagerTest.h"
#include "iostream"

using namespace std;

MountManagerTest::MountManagerTest(vector<string> command_line){
	this->command_line = command_line;
    //setar valores default
    mountManagerTest(this->command_line);
}

MountManagerTest::~MountManagerTest(){
}


void MountManagerTest::mountManagerTest(vector<string> command_line){
    mountBaseTest(command_line);
    mountCfgFile(command_line);
    mountVideos(command_line);
    mountQp(command_line);
    mountFile();
    mountUnitTests();

    //SAVE THE TEST CONFIGURATIONS, 
    //CONSETAR, COLOCAR PARA GERAR ARQUIVOS DIFERENTES
    for (int h = 0; h < cfgs.size(); h++){
        for (int i = 0; i < videos.size(); i++){
            ofstream result("Result_test.txt", ios::app);
            if (!result){
                cout << "File couldn't open" << endl;
            }else{
                result << "ENCODER TEST LOG: " << endl;
                result << "CONFIG ...............: " << cfgs[h] << endl;
                result << "VIDEO ................: " << videos[i].getVideoPaht() << endl;
                result << "Chroma format ........: " << videos[i].getVideoSubsampling() << endl;
                result << "Color depth ..........: " << videos[i].getBitDepth() << endl;
                result << "Width ................: " << videos[i].getVideoWdt() << endl;
                result << "Hight ................: " << videos[i].getVideoHgt() << endl;
                result << "Frames ...............: " << videos[i].getFrames() << endl;
                result << "Frame rate ...........: " << "130 (modificar)" << endl;
                result << "--------------------------------------" << endl;
                result.close();
            }
        }
    }
}

ManagerTest* MountManagerTest::getTest(){
    return new ManagerTest( mode, 
                            threads, 
                            unit_tests,
                            videos
                            );
}


void MountManagerTest::mountBaseTest(vector<string> command_line){
    //test values
    this->frame_rate    = "30";
    this->total_frames  = "130";
    this->mode = "1";
    this->enc_eva = "test/encoder/eva";
    this->enc_ref = "test/encoder/ref";
    this->out_video = "test/vout/";
    this->out_log   = "test/log/";

    this->threads = "1";

    for (int i = 1; i < command_line.size(); i++) {
        string temp_string = command_line[i-1];
        if(temp_string.compare("-mod") == 0){
            this->mode = command_line[i];
        }else if (temp_string.compare("-thr") == 0){
            this->threads = command_line[i];
        }else if (temp_string.compare("-eva") == 0){
            this->enc_eva = command_line[i];
        }else if (temp_string.compare("-ref") == 0){
            this->enc_ref = command_line[i];
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
    this->encoder_path.push_back(enc_ref);
    this->encoder_path.push_back(enc_eva);
}


void MountManagerTest::mountCfgFile(vector<string> command_line){
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


void MountManagerTest:: mountVideos(vector<string> command_line){
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
                this->videos.push_back(InputVideo("", command_line[i++], width, height, video_subsampling, frames, bit_depth));
            }
            break;
        }
    }
    if (this->videos.size() == 0) {
        this->videos.push_back(InputVideo("video_test", "test/vin/video.yuv", width, height, video_subsampling, frames, bit_depth));
    }
}

void MountManagerTest:: mountQp(vector<string> command_line){
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


int MountManagerTest::conversorStrToInt(string str){
    stringstream convert(str); 
    int temp_nuber;
    if(!(convert >> temp_nuber))
        return 1;
    return temp_nuber;
}


string MountManagerTest::removeInvalidChar(string text){
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

void MountManagerTest:: mountFile(){
	for (int h = 0; h < cfgs.size(); h++){
		for (int i = 0; i < videos.size(); i++){
			for (int j = 0; j < encoder_path.size(); j++){
				for (int k = 0; k < qps.size(); k++){
					string command 	= 	removeInvalidChar(encoder_path[j])
									+	removeInvalidChar(cfgs[h])
									+	removeInvalidChar(videos[i].getVideoPaht())
									+	removeInvalidChar(qps[k]);
					this->out_files.push_back( this->out_log   + command + ".txt");
                    this->out_videos.push_back(this->out_video + command + ".yuv");
 				}
			}
		}
	}
}

void MountManagerTest:: mountUnitTests(){
	int out_cont = 0;
	for (int h = 0; h < cfgs.size() ; h++){
		for (int i = 0; i < videos.size(); i++){
			for (int j = 0; j < encoder_path.size(); j++){
				for (int k = 0; k < qps.size(); k++){
					string command = " ./"  	+ this->encoder_path[j]
									+ " -f "  	+ this->total_frames
									+ " -fr "  	+ this->frame_rate
									+ " -c "  	+ this->cfgs[h] 
									+ " -q "  	+ this->qps[k] 
									+ " -wdt "	+ this->videos[i].getVideoWdt()
									+ " -hgt "	+ this->videos[i].getVideoHgt()
								    + " -i "  	+ this->videos[i].getVideoPaht()
									+ " -o " 	+ this->out_videos[out_cont]
									+ " >> "	+ this->out_files[out_cont];
                    this->unit_tests.push_back(   UnitTest( out_cont,
                                                            command, 
                                                            this->out_files[out_cont],
                                                            this->videos[i].getVideoPaht() ,
                                                            this->out_videos[out_cont], 
                                                            this->encoder_path[j],
                                                            this->qps[k]));
                    out_cont++;
				}
			}
		}
	}
}