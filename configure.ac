#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
#
# Copyright 2020-2023 Fabian Groffen <grobian@gentoo.org>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License in the file COPYING for more details.

AC_PREREQ([2.71])
AC_INIT([html2text], [2.1.1.9999_pre], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE
AM_ICONV
#AC_CONFIG_SRCDIR([html.h])
#AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_YACC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LN_S

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h libintl.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memmove strerror strncasecmp])

AC_CONFIG_FILES([Makefile po/Makefile.in])
AC_OUTPUT
