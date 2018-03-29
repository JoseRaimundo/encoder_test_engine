
#include "common.h"
#include "Parse.h"


#include "ManagerTest.h"

#include "ManagerMetrics.h"
#include "MountManagerTest.h"


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

	ManagerTest *input_test;
	ManagerMetrics *manager_metrics;

	if (argc < 3){
		usage();
		return 0;
	}

	vector<string> command_input;
    for (int i = 0; i < argc; i++){
        command_input.push_back(argv[i]);
    }


    struct timeval start, end;
    gettimeofday(&start, NULL);

	MountManagerTest mount_input_test = MountManagerTest(command_input);
 	input_test = mount_input_test.getTest();

	input_test->executeEncodes();
	cout << "\033[1;32m Full Coding test completed!\033[0m\n";
	 manager_metrics = new ManagerMetrics(input_test->getUnitTests());

	 manager_metrics->computerMetrics();





	//REGISTER TIME
	gettimeofday(&end, NULL);
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
             end.tv_usec - start.tv_usec) / 1.e6;

    ofstream result("Result_test.txt", ios::app);
    if (!result){
        cout << "File couldn't open" << endl;
    }else{
        result << "Total time: " + FormatTime::formatTime(delta) << endl;
        result.close();
    } 

	return 0;
}