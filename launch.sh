#!/usr/bin/env bash

make
cd visualizer
install cmake
mkdir build
cd build
cmake ..
make
cp ../../push_swap .
./bin/visualizer