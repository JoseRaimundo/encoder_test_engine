#ifndef ComputerMetrics_H
#define Parse_H

#include "common.h"
#include "../include/LogFile.h"


using namespace std;

class Parse{

	public:
		Parse();
		~Parse();
		LogFile parseLog(string file_log);
	private:

		string file_path;

};
#endif