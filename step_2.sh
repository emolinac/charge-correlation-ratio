#!/bin/bash

# clean and compile code
make clean
make

# Create necessary ntuples
cd ./bin
./create_ntuples
./create_purity_ntuple
./create_decays_ntuple
./create_datadecays_ntuple
./create_invmass_ntuple
./create_resolution_ntuple

cd ../src

# Determine binning
root -q macro_determine_binning.cpp

echo "NOTE : Copy the binning into the analysis-constants.h file and recompile code"
