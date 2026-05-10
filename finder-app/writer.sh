#!/bin/sh
# Wirter script
# h4nr1s3ld0n

if [ $# -lt 2 ]; then
	echo "Please provide a file to write and a string" >&2
	exit 1
fi

WRITEFILE=$1
WRITESTR=$2

echo "Writing ${WRITESTR} to ${WRITEFILE}..."

rm -rf "${WRITEFILE}"

mkdir -p "$(dirname "$WRITEFILE")" && printf "%s" "$WRITESTR" > "$WRITEFILE"

check=$(cat "$WRITEFILE")

if [ $check != ${WRITESTR} ]; then
	echo "Writing failed" >&2
	exit 1
fi

