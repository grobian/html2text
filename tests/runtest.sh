#!/usr/bin/env bash

# Copyright 2020 Fabian Groffen
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

H2T="../html2text -rcfile .html2textrc"
MODE=cat
TESTS=( "$@" )
VARIANTS=(
	default:""
	links:"-links"
)

[[ ${TEST_APPROVE} -ge 1 ]] && MODE=patch

fails=0
sucs=0
tsts=0
for t in "${TESTS[@]}" ; do
	t=${t%.html}  # allow easy globbing
	if [[ ! -e ${t}.html ]] ; then
		echo "skipping non-existent test: ${t}"
		continue
	fi

	inpenc=${t%=*}
	firstvariant=
	for variant in "${VARIANTS[@]}" ; do
		vname=${variant%:*}
		vargs=${variant#*:}
		[[ -n ${TEST_VERBOSE} ]] && \
			echo ${H2T} -from_encoding ${inpenc} ${vargs} ${t}.html
		${H2T} -from_encoding ${inpenc} ${vargs} ${t}.html \
			| diff -Nu ${t}.${vname}.out - | ${MODE}
		if [[ $? -ne 0 ]] ; then
			echo "test ${t} variant ${vname}: FAIL"
			: $((fails++))
		else
			: $((sucs++))
		fi

		if [[ ${TEST_APPROVE} -ge 1 && -n ${firstvariant} ]] ; then
			# combine outputs if they are the same linking to the first
			# variant only
			[[ -n ${TEST_VERBOSE} ]] && \
				echo cmp -s ${t}.${firstvariant}.out ${t}.${vname}.out
			if cmp -s ${t}.${firstvariant}.out ${t}.${vname}.out ; then
				rm ${TEST_VERBOSE+-v} -f ${t}.${vname}.out
				ln ${TEST_VERBOSE+-v} -s \
					${t}.${firstvariant}.out ${t}.${vname}.out
			fi
		fi
		[[ -z ${firstvariant} ]] && firstvariant=${vname}

		: $((tsts++))
	done
done

echo "${tsts} tests, ${sucs} success, ${fails} failures"

[[ ${fails} -ne 0 ]] && exit 1

exit 0
