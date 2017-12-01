#ifndef Parse_H
#define Parse_H

#include "common.h"
#include "../include/LogFile.h"


using namespace std;

class Parse{

	public:

		static LogFile parseLog(string file_log);
	private:
		Parse(){}
		string file_path;

};
#endif