#!/bin/sh

make clean
CFLAGS='-g -Wall -std=gnu99' make test
for name in *_test; do
	$name || {
		echo "$name: FAIL"
		exit 1
	}
done
