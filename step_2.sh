#!/bin/bash

# clean and compile code
make clean
make

# Create necessary ntuples
cd ./bin 
./create_ntuples
./create_purity_ntuple
./create_decays_ntuples

cd ../src

# Determine binning
root -q macro_determine_binning.cpp

echo "NOTE : Copy the binning into the analysis-constants.h file and recompile code"
