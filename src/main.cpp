
#include "../include/common.h"
#include "../include/Parse.h"

#include "../include/Controller.h"


using namespace std;

void usage(){
	cout 	<< "Use: \n"
			<< "|Command:......... |Type ....|Description				|\n"
			<< "./bin/CodecTest .. (string).. Execute codec evaluate tool.\n" 
		 	<< "-mod ............. (int) .... Mode: 1 Network or 2 Local Desk or 3 Configure NetworkManager.\n"
		 	<< "-thr ............. (int) .... Maximum number of threads per host. \n"
		 	<< "-vin ............. (int) .... Number of input videos, followed by -vins paths\n"
		 	<< "-cfg ............. (int) .... Number of configuration files, followed by -cfg paths\n"
		 	<< "-outl ............ (string) . Path to save log files.\n"
		 	<< "-outv ............ (string) . Path to output video.\n"
		 	<< "-eva ............. (string) . Command model to run the evaluating codec.\n"
		 	<< "-ref ............. (string) . Command model to run the reference codec.\n"
		 	<< "-fr .............. (int) .... Frame rate per seconds.\n"
		 	<< "-f ............... (int) .... Total frames to be encoded.\n"
		 	<< "-wdt ............. (int) .... Videos width.\n"
		 	<< "-hgt ............. (int) .... Videos height.\n"
			<< "Full command example:\n"
			<< "./bin/CodecTest -mod 1 -thr 2 -vin 1 test/videos/video3.yuv -cfg 1 test/cfg/config1.cfg -outl test/log/ -outv test/videosout/ -eva ./test/codec/eva/TAppEncoderStatic -ref ./test/codec/ref/TAppEncoderStatic"

			<< endl;
}

int main(int argc, char const *argv[]){
	if (argc < 5){
		usage();
		return 0;
	}
	Controller *control = new Controller(argv, argc);
	control->Execute();
	return 0;
}