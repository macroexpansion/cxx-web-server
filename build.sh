#!/bin/sh

if [ ! -d "bin" ] 
then
    mkdir bin
fi

if [ -d "dist" ] 
then
    cd dist
else
    mkdir dist && cd dist
fi

cmake -DCMAKE_CXX_COMPILER=g++ ..
cmake --build . --config Debug
