#!/bin/bash

mother_dir=$(pwd)

cd ./bin
./calculate_rc_z

cd ${mother_dir}/src
root print_rc_z.cpp

