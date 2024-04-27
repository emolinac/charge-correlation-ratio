#!/bin/bash

mother_dir=$(pwd)

cd ./bin
./calculate_rc_jet_pt

cd ${mother_dir}/src
root print_rc_jet_pt.cpp

