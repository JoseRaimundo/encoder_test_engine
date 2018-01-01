
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
	metrics/Image.cpp\
	metrics/Sobel.cpp\
	metrics/Video.cpp\
	metrics/PSNR.cpp\
	metrics/SSIM.cpp\
	metrics/PWSSIM.cpp\
	metrics/Bjontegaard.cpp\
	Thread.cpp\
	InputVideo.cpp\
	UnitTest.cpp\
	LogFile.cpp\
	ManagerTest.cpp\
	MountManagerTest.cpp\
	Parse.cpp\
	FormatTime.cpp\
	EncoderExec.cpp\
	Controller.cpp\
	ManagerMetrics.cpp\
    main.cpp


.SUFFIXES: .cpp .o .h

include Makefile.build

default: all