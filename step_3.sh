#!/bin/bash

# clean and compile code
make clean
make

# Change the directory
cd ./bin

# Execute all calculations
./calculate_rc_z_datadecays
./calculate_rc_z_purity
./calculate_rc_z
./calculate_rc_kt_datadecays
./calculate_rc_kt_purity
./calculate_rc_kt
./calculate_rc_jet_pt_datadecays
./calculate_rc_jet_pt_purity
./calculate_rc_jet_pt