#ifndef Parse_H
#define Parse_H

#include "common.h"
#include "../include/LogFile.h"


using namespace std;

class Parse{

	public:
		Parse();
		~Parse();
		LogFile* getFile();

	private:

		LogFile *log_file;

		string file_path;
				
		int 			total_frames;
		int 			findInFile(string file_log);
};
#endif