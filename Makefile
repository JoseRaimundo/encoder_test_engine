
include Makefile.top


MODULE     = EncoderTest

CFLAGS = -I$(INCDIR)/ \
        -I/usr/local/include/\
        -I/usr/include/\
	-Iinclude/\
        #-I../../common/xml/include/\
        #-I../common/include/\

CFLAGS += -g -ggdb -fPIC

## -lboost_iostreams 
###-lboost_system -lboost_filesystem

LDFLAGS = \
	-L/usr/local/lib\

SOURCES = \
	Thread.cpp\
	Video.cpp\
	UnitTest.cpp\
	LogFile.cpp\
	InputTest.cpp\
	MountInputTest.cpp\
	Bjontegaard.cpp\
	Parse.cpp\
	FormatTime.cpp\
	ComputerMetric.cpp\
	EncoderExec.cpp\
	Controller.cpp\
    main.cpp


.SUFFIXES: .cpp .o .h

include Makefile.build

default: all