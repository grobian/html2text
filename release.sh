#! /usr/bin/env bash

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

die() {
	echo "$*" > /dev/stderr
	exit 1
}

usage() {
	die "usage: $0 <--major | --minor | --bugfix>"
}

MODE=
while [[ $# -ge 1 ]] ; do
	case $1 in
		--bugfix)  MODE=bugfix  ;;
		--minor)   MODE=minor   ;;
		--major)   MODE=major   ;;
		*)         usage        ;;
	esac
	shift
done
[[ -z ${MODE} ]] && usage

# grab current version
# AC_INIT([html2text], [2.1.1.9999_pre], [BUG-REPORT-ADDRESS])
VERSION=$(sed -n \
	-e '/^AC_INIT/s/^.*\[html2text\],\s*\[\([0-9.]\+\)_pre\].*$/\1/p' \
	configure.ac)
[[ -z ${VERSION} ]] && die "VERSION unset or invalid in configure.ac"

# split out first 3 components, throw away the rest (should not be there)
MAJOR=${VERSION%%.*}
MINOR=${VERSION#${MAJOR}.} ; MINOR=${MINOR%%.*}
BUGFIX=${VERSION#${MAJOR}.${MINOR}.} ; BUGFIX=${BUGFIX%%.*}

# compute new version
case "${MODE}" in
	major)
		NEWVERSION=$((MAJOR + 1)).0.0
		FUTUREVERSION=$((MAJOR + 1)).1.0
		;;
	minor)
		NEWVERSION=${MAJOR}.$((MINOR + 1)).0
		FUTUREVERSION=${MAJOR}.$((MINOR + 2)).0
		;;
	bugfix)
		NEWVERSION=${MAJOR}.${MINOR}.$((BUGFIX + 1))
		FUTUREVERSION=${MAJOR}.$((MINOR + 1)).0
		;;
esac

TODAY=$(date +%F)
EUTODAY=$(date +%d-%m-%Y)

# version we store after the release
RECVERSION=${NEWVERSION}.9999_pre

# create official version
# AC_INIT([html2text], [2.1.1.9999_pre], [BUG-REPORT-ADDRESS])
sed -i.release \
	-e '/^AC_INIT/s/\['"${VERSION}"'_pre\]/['"${NEWVERSION}"']/' \
	-e "/^AM_MAINTAINER_MODE/s:\[enable\]:[disable]:" \
	configure.ac || die
mv ChangeLog.md ChangeLog.md.release
{
	echo "# ${FUTUREVERSION} (unreleased master branch)"
	echo
	echo "### New Features"
	echo
	echo "### Bugfixes"
	echo
	echo
	echo "# ${NEWVERSION} (${EUTODAY})"
	sed -e "1d" ChangeLog.md.release
} > ChangeLog.md
git diff | cat
read -p "OK to commit and create tag v${NEWVERSION}? [yN] " ans
case "${ans}" in
	Y|y|YES|Yes|yes)
		: # ok
		;;
	*)
		mv configure.ac.release configure.ac
		mv ChangeLog.md.release ChangeLog.md
		die "aborting"
		;;
esac
rm -f configure.ac.release ChangeLog.md.release
git commit -a --signoff -m "release ${NEWVERSION}" || die
git tag v${NEWVERSION}

echo "building release tar"
SRCDIR=${PWD}
CHANGES=.make-release-tmp.$$
mkdir "${CHANGES}"
trap "rm -Rf ${CHANGES}" EXIT

mkdir "${CHANGES}"/build || die
pushd "${CHANGES}"/build || die
git clone "${SRCDIR}" html2text
pushd html2text
git checkout "v${NEWVERSION}" || die
autoreconf -f -i
./configure
make dist
mv html2text-${NEWVERSION}.tar.* "${SRCDIR}"/ || die
popd || die
popd || die

# flag the repo being beyond the release
sed -i \
	-e '/^AC_INIT/s/\['"${NEWVERSION}"'\]/['"${RECVERSION}"']/' \
	-e "/^AM_MAINTAINER_MODE/s:\[disable\]:[enable]:" \
	configure.ac || die
autoreconf -f -i
git commit -a --signoff -m "post release update" || die
