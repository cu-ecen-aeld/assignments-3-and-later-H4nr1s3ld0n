#!/bin/sh

if [ $# -lt 2 ]; then
	echo "Usage : finder.sh {path} {string}"
	exit 1
fi

FILESDIR=$1
SEARCHSTR=$2

if [ ! -d "$FILESDIR" ]; then
	echo "Path $FILESDIR is not a directory"
	exit 1
fi

NUMBERFILES=$(find "$FILESDIR" -type f | wc -l)
MATCHINGLINES=$(grep -r "$SEARCHSTR" "$FILESDIR" | wc -l)


echo "The number of files are ${NUMBERFILES} and the number of matching lines are ${MATCHINGLINES}"
