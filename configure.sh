#!/usr/bash
cd build
make clean
cmake .. && make -j8
exec ../output/prog
