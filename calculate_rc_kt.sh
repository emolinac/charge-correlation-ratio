#!/bin/bash

mother_dir=$(pwd)

cd ./bin
./calculate_rc_kt
./calculate_rc_kt_purity

cd ${mother_dir}/src
root macro_print_rc_kt.cpp

