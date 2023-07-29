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

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4

AM_YFLAGS = -d -Wno-yacc

bin_PROGRAMS = html2text
html2text_SOURCES = \
					Area.cpp \
					cmp_nocase.cpp \
					format.cpp \
					html2text.cpp \
					HTMLControl.cpp \
					HTMLParser.yy \
					html.cpp \
					HTMLDriver.cpp \
					iconvstream.cpp \
					Properties.cpp \
					sgml.cpp \
					table.cpp
BUILT_SOURCES = HTMLParser.hh

check-local: html2text
	@$(MAKE) $(AM_MAKEFLAGS) -C tests
