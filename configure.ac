#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script

AC_PROCEQ([2.63])
AC_INIT([webDemo],[0.0.1],[18271649397@163.com])
AC_CONFIG_SRCDIR([user_op.cpp])
AC_CONFIG_HEADERS([config.h])


AM_INIT_AUTOMAKE([-Wall -Werror foreign])
#Check for programs.
AC_PROG_CXX([g++])
AC_PROG_CC([gcc])

#checks for libraries.

#checks for header files.
AC_LANG_PUSH([C++])
#this is to check you need to install libraries
AC_CHECK_HEADERS([/usr/local/include/tbsys/tbsys.h],[AC_MSG_ERROR([Unable to find tb-common-util,please install from https://github.com/basketballCzm/tb-common-utils.git. if you want to install it you should read README])])
AC_CHECK_HEADERS([fcgi_config.h],[],[AC_MSG_ERROR([Unable to find fcgi, please install fcgi])])
AC_CHECK_HEADERS([uriparser/Uri.h],[],[AC_MSG_ERROR([Unable to find uriparser, please install uriparser])])
AC_CHECK_HEADERS([jsoncpp/json/json.h],[],[AC_MSG_ERROR([Unable to find jsoncpp, please install jsoncpp])])
AC_LANG_POP([C++])

#checks for typedefs, structures, and complier characteristics.

#checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT