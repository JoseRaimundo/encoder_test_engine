
include Makefile.top


MODULE     = CodecTest

CFLAGS = -I$(INCDIR)/ \
        -I/usr/local/include/\
        -I/usr/include/\
	-Iinclude/\
        #-I../../common/xml/include/\
        #-I../common/include/\

CFLAGS += -g -ggdb -fPIC

LDFLAGS = \
	-L/usr/local/lib\

SOURCES = \
	Bjontegaard.cpp\
	Parse.cpp\
	Thread.cpp\
	CodecExecutor.cpp\
	Controller.cpp\
    main.cpp


.SUFFIXES: .cpp .o .h

include Makefile.build

default: all 