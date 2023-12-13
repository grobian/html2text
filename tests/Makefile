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

TESTS= \
	   ascii=ordered-list \
	   ascii=unterminated-table \
	   ascii=whitespace-tags \
	   ascii=corrupt-attributes.html \
	   iso-8859-1=dot-in-tag-name \
	   iso-8859-1=hex-entities \
	   iso-8859-1=large-table-gt-no-html-end-tag \
	   utf-8=blockquote-reply \
	   utf-8=bold-utf-8-chars-and-zwnj \
	   utf-8=linked-links-and-email-addresses \
	   utf-8=meta-in-blockquote \
	   utf-8=table-with-border \
	   utf-8=tag-with-colon-attribute \
	   utf-8=unicode-hex-references \
	   utf-8=cid-image-link \
	   utf-8=ifendif \
	   auto=html4meta \
	   auto=html5meta \
	   auto=html4entities \
	   $(NULL)
check:
	@./runtest.sh $(TESTS)
