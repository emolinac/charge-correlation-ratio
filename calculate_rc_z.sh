#!/bin/bash

mother_dir=$(pwd)

cd ./bin
./calculate_rc_z
./calculate_rc_z_purity

cd ${mother_dir}/src
root macro_print_rc_z.cpp

