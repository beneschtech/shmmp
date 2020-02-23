AC_PREREQ([2.69])
AC_INIT([shmmp],[1.0.0],[chris@beneschtech.com])
AM_INIT_AUTOMAKE([-Wall])
AC_CONFIG_HEADERS([include/config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_LANG([C++])
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LEX
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_PROG_YACC
AM_PROG_AR
AX_CXX_COMPILE_STDCXX(11,[],[mandatory])

# Autoscan checks go here
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T
# End autoscan checks

AC_CONFIG_FILES([
Makefile
src/Makefile
src/lib/Makefile
src/examples/interthread/Makefile
])
AC_OUTPUT
