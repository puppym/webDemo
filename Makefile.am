AUTOMAKE_OPTIONS = foreign
TBLIB_ROOT = /usr/local
AM_CPPFLAGS = -std=c++11 -I/${TBLIB_ROOT}/include/tbsys -I/${TBLIB_ROOT}/include/tbnet

bin_PROGRAMS=penv_op jsonParser_op

penv_op_SOURCES=penv_op.cpp
penv_op_LDADD=-luriparser -ljsoncpp -lpthread -lfcgi -lfcgi++ $(TBLIB_ROOT)/lib/libtbsys.a

jsonParser_op_SOURCES=jsonParser_op.cpp
jsonParser_op_LDADD=-luriparser -ljsoncpp -lpthread -lfcgi -lfcgi++ $(TBLIB_ROOT)/lib/libtbsys.a