#! /bin/bash
if test -f "build/"; then
	cd build/
else 
	mkdir build
	cd build
fi

cmake ../src/

