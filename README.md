# charge-correlation-ratio
This software is a w.i.p. It has basic features and codes to perform a preliminary analysis of the *charge correlation ratio* observable. \
Note : The software is designed to be used with the *typical* LHCb structure of TTrees.

## How to use?
1. Get some data and simulation files and put them in the **input-files** folder.
2. In the code *names.h*, change the variable *mother_folder* with the output of the command pwd in this directory (the directory in which the **README** file is located).
3. In the code *analysis-constants.h*, change the number of bins and hadrons to use to your liking.
4. Execute the bash script **step_1.sh** to get the classes to be used.
5. Execute the bash script **step_2.sh** to compile the software and get the TNtuples to be use. Also, you will get the binning to be used according to the number of bins you specified in *analysis-constants.h*.
    - If you change the binning remember to recompile the code.
6. To get the result execute the *calculate* scripts in the mother foldes. It will output a preliminary plot of the observable.