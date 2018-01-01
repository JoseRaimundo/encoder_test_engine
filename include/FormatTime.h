#ifndef FormatTime_H
#define FormatTime_H

#include "common.h"

using namespace std;

class FormatTime{

	public:

		static string formatTime(double time);
	private:
		FormatTime(){}
		double time;
};
#endif