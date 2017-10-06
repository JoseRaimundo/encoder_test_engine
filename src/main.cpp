
#include "../include/common.h"
#include "../include/Parse.h"

#include "../include/Controller.h"


using namespace std;

void usage(){
	cout 	<< "Use: \n"
			<< "|Command:......... |Type ....|Description				|\n"
			<< "./bin/CodecTest .. (string).. Execute codec evaluate tool.\n" 
		 	<< "-mod ............. (int) .... Mode: 1 Local.\n"
		 	<< "-thr ............. (int) .... Maximum number of threads per host. \n"
		 	<< "-vin ............. (int) .... Number of input videos, followed by -vins paths\n"
		 	<< "-cfg ............. (int) .... Number of configuration files, followed by -cfg paths\n"
		 	<< "-outl ............ (string) . Path to save log files.\n"
		 	<< "-outv ............ (string) . Path to output video.\n"
		 	<< "-eva ............. (string) . Binary of the evaluating codec.\n"
		 	<< "-ref ............. (string) . Binary of the reference codec.\n"
		 	<< "-fr .............. (int) .... Frame rate per seconds.\n"
		 	<< "-f ............... (int) .... Total frames to be encoded.\n"
		 	<< "-wdt ............. (int) .... Videos width.\n"
		 	<< "-hgt ............. (int) .... Videos height.\n"
			<< "Full command example (the command contain the default values):\n"
			<< "./bin/CodecTest  -mod 1 -thr 1 -wdt 352 -hgt 288 -fr 30 -f 120 -eva test/codec/eva/TAppEncoderStatic -ref test/codec/ref/TAppEncoderStatic -outv test/videosout/ -outl test/log/ -vin 1 test/videos/video.yuv -cfg 1 test/cfg/config.cfg -q 4 22 27 32 37"
			<< "Retorn a execution:\n"
			<< "./bin/CodecTest -bkp"

			<< endl;
}

int main(int argc, char const *argv[]){
	if (argc < 3){
		usage();
		return 0;
	}
	Controller *control = new Controller(argv, argc);
	control->Execute();
	return 0;
}