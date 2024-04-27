#!/bin/bash

mother_dir=$(pwd)

cd ./bin
./calculate_rc_jt

cd ${mother_dir}/src
root print_rc_jt.cpp

