AUTOMAKE_OPTIONS = foreign
TBLIB_ROOT = /usr/local
AM_CPPFLAGS = -std=c++11 -I/${TBLIB_ROOT}/include/tbsys -I/${TBLIB_ROOT}/include/tbnet

bin_PROGRAMS=webDemo

webDemo_SOURCES=user_op.cpp
webDemo_LDADD=-luriparser -ljsoncpp -lpthread -lfcgi -lfcgi++ $(TBLIB_ROOT)/lib/libtbsys.a