#!/bin/bash

mother_dir=$(pwd)

cd ./bin
./calculate_rc_kt

cd ${mother_dir}/src
root print_rc_kt.cpp

