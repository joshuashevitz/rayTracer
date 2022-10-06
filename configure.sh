#! /bin/bash

cd build/

cmake ../src/ -B build -G "Visual Studio 17 2022"

cmake --build build/