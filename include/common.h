#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream> 
#include <fstream>
#include <math.h> 
#include <float.h>
#include <unistd.h>
#include <string.h> 
#include <vector> 
#include <sys/time.h>
#include <sys/types.h>
#include <strings.h>
#include <string>
#include "InputTest.h"
#include "UnitTest.h"
#include "Video.h"
#include "LogFile.h"
#include "ComputerMetric.h"
#include "FormatTime.h"

//maximum QP per test (considere Bjontegaard metric)
#define MAX_QP 4


//status of test units
#define IN_QUEUE 0
#define COMPLETE 1