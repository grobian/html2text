#! /usr/bin/env bash

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
VERSION=$(sed -n '/^VERSION=/s/^.*=\([0-9.]\+\)_pre/\1/p' Makefile.in)
[[ -z ${VERSION} ]] && die "VERSION unset or invalid in Makefile.in"

# split out first 3 components, throw away the rest (should not be there)
MAJOR=${VERSION%%.*}
MINOR=${VERSION#${MAJOR}.} ; MINOR=${MINOR%%.*}
BUGFIX=${VERSION#${MAJOR}.${MINOR}.} ; BUGFIX=${BUGFIX%%.*}

# compute new version
case "${MODE}" in
	major)
		NEWVERSION=$((MAJOR + 1)).0.0
		;;
	minor)
		NEWVERSION=${MAJOR}.$((MINOR + 1)).0
		;;
	bugfix)
		NEWVERSION=${MAJOR}.${MINOR}.$((BUGFIX + 1))
		;;
esac

# version we store after the release
RECVERSION=${NEWVERSION}.9999_pre

# create official version
sed -i.release -e '/^VERSION=/s/=.*$/='"${NEWVERSION}"'/' Makefile.in || die
git diff | cat
read -p "OK to commit and create tag v${NEWVERSION}? [yN] " ans
case "${ans}" in
	Y|y|YES|Yes|yes)
		: # ok
		;;
	*)
		mv Makefile.in.release Makefile.in
		die "aborting"
		;;
esac
rm -f Makefile.in.release
git commit --signoff -m "release ${NEWVERSION}" Makefile.in || die
git tag v${NEWVERSION}

# flag the repo being beyond the release
sed -i -e '/^VERSION=/s/=.*$/='"${RECVERSION}"'/' Makefile.in || die
git commit --signoff -m "post release update" Makefile.in || die
