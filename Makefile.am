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
					Area.h \
					auto_aptr.h \
					auto_ptr.h \
					cmp_nocase.cpp \
					cmp_nocase.h \
					format.cpp \
					format.h \
					html2text.cpp \
					HTMLControl.cpp \
					HTMLControl.h \
					html.cpp \
					HTMLDriver.cpp \
					HTMLDriver.h \
					html.h \
					HTMLParser.yy \
					iconvstream.cpp \
					iconvstream.h \
					istr.h \
					Properties.cpp \
					Properties.h \
					sgml.cpp \
					sgml.h \
					table.cpp \
					$(NULL)
html2text_LDADD = \
				  $(LIBICONV) \
				  $(NULL)

BUILT_SOURCES = HTMLParser.hh
man1_MANS = html2text.1
man5_MANS = html2textrc.5

EXTRA_DIST = \
			 tests \
			 COPYING \
			 CREDITS \
			 html2text.1 \
			 html2textrc.5 \
			 INSTALL \
			 KNOWN_BUGS \
			 README.md \
			 $(NULL)

check-local: html2text
	@$(MAKE) $(AM_MAKEFLAGS) -C tests
