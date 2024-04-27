#!/bin/bash

# Go to src, execute code, and move the respective files
cd ./src
root -q makeclasses.cpp
mv *.C *.h ../include
