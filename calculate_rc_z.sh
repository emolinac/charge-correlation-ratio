#!/bin/bash

mother_dir=$(pwd)

cd ./bin
./calculate_rc_z
./calculate_rc_z_purity
./calculate_rc_z_stringbreakingfrac

cd ${mother_dir}/src
root macro_print_rc_z.cpp

