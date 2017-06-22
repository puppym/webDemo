AUTOMAKE_OPTIONS = foreign
TBLIB_ROOT = /usr/local
AM_CPPFLAGS = -std=c++11 -I/${TBLIB_ROOT}/include/tbsys -I/${TBLIB_ROOT}/include/tbnet -I/usr/include/jsoncpp

bin_PROGRAMS=jsonExample jsonExample1

jsonExample_SOURCES=jsonExample.cpp
jsonExample_LDADD=-luriparser -ljsoncpp -lpthread -lfcgi -lfcgi++ $(TBLIB_ROOT)/lib/libtbsys.a

jsonExample1_SOURCES=jsonExample1.cpp
jsonExample1_LDADD=-luriparser -ljsoncpp -lpthread -lfcgi -lfcgi++ $(TBLIB_ROOT)/lib/libtbsys.a
