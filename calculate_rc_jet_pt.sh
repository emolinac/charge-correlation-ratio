#!/bin/bash

mother_dir=$(pwd)

cd ./bin
./calculate_rc_jet_pt
./calculate_rc_jet_pt_purity
./calculate_rc_jet_pt_datadecays

cd ${mother_dir}/src
root macro_print_rc_jet_pt.cpp

