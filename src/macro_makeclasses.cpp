#include <iostream>
#include "../include/analysis-constants.h"
#include "../include/directories.h"
#include "../include/names.h"

void macro_makeclasses()
{
    // Add the files located in the input folder
    TChain* chain1 = new TChain("mcjettuple/MCJetTree");  
    TChain* chain2 = new TChain("Jets/DecayTree");
    TChain* chain3 = new TChain("Jets/DecayTree");    // Used for data

    chain1->Add((input_folder+"D2KKPi_MC_Sim10c_2018_MD_05042024_full.root").c_str());
    chain1->Add((input_folder+"D2KKPi_MC_Sim10c_2018_MU_05042024_full.root").c_str());
    
    chain2->Add((input_folder+"D2KKPi_MC_Sim10c_2018_MD_05042024_full.root").c_str());
    chain2->Add((input_folder+"D2KKPi_MC_Sim10c_2018_MU_05042024_full.root").c_str());
    
    chain3->Add((input_folder+"D2KKPi_Data_2016_MD_02252024.root").c_str());
    chain3->Add((input_folder+"D2KKPi_Data_2016_MD_04202024.root").c_str());
    chain3->Add((input_folder+"D2KKPi_Data_2016_MD_06222024.root").c_str());
    chain3->Add((input_folder+"D2KKPi_Data_2016_MU_02252024.root").c_str());
    chain3->Add((input_folder+"D2KKPi_Data_2016_MU_04202024.root").c_str());
    chain3->Add((input_folder+"D2KKPi_Data_2016_MU_06222024.root").c_str());
    
    
    chain1->MakeClass("TMCJets");
    chain2->MakeClass("THFJets");
    chain3->MakeClass("THFJetsData");
}

