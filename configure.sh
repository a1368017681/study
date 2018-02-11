#!/usr/bash
cd build
rm -rf *
cmake .. && make -j8
