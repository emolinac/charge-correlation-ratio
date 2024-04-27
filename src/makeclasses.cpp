#include <iostream>
#include "../include/analysis-constants.h"
#include "../include/names.h"

void makeclasses()
{
    // Add the files located in the input folder
    TChain* chain1 = new TChain("mcjettuple/MCJetTree");  
    TChain* chain2 = new TChain("StdHltZJets/DecayTree");
    TChain* chain3 = new TChain("StdHltZJets/DecayTree");    // Used for data

    chain1->Add((input_folder+"Zhadron_MCReco_Sim10a_MU_2016_08162023.root").c_str());
    chain1->Add((input_folder+"Zhadron_MCReco_Sim10a_MD_2016_08162023.root").c_str());
    chain1->Add((input_folder+"Zhadron_MCReco_Sim09j_MU_2016_08162023.root").c_str());
    chain1->Add((input_folder+"Zhadron_MCReco_Sim09j_MD_2016_08162023.root").c_str());
    chain1->Add((input_folder+"Zhadron_MCReco_Sim09l_MU_2016_08162023.root").c_str());
    chain1->Add((input_folder+"Zhadron_MCReco_Sim09l_MD_2016_08162023.root").c_str());

    chain2->Add((input_folder+"Zhadron_MCReco_Sim10a_MU_2016_08162023.root").c_str());
    chain2->Add((input_folder+"Zhadron_MCReco_Sim10a_MD_2016_08162023.root").c_str());
    chain2->Add((input_folder+"Zhadron_MCReco_Sim09j_MU_2016_08162023.root").c_str());
    chain2->Add((input_folder+"Zhadron_MCReco_Sim09j_MD_2016_08162023.root").c_str());
    chain2->Add((input_folder+"Zhadron_MCReco_Sim09l_MU_2016_08162023.root").c_str());
    chain2->Add((input_folder+"Zhadron_MCReco_Sim09l_MD_2016_08162023.root").c_str());

    chain3->Add((input_folder+"Zjet_Data_2016_MU_04062024.root").c_str());
    chain3->Add((input_folder+"Zjet_Data_2016_MD_04062024.root").c_str());
    //chain3->Add((input_folder+"Zhadron_2016_MD_08312022_url313_0_800.root").c_str());
    //chain3->Add((input_folder+"Zhadron_2016_MD_08312022_url313_1600_1699.root").c_str());
    //chain3->Add((input_folder+"Zhadron_2016_MD_08312022_url313_800_1600.root").c_str());
    //chain3->Add((input_folder+"Zhadron_2016_MU_08312022_url314_0_800.root").c_str());
    //chain3->Add((input_folder+"Zhadron_2016_MU_08312022_url314_1600_1616.root").c_str());
    //chain3->Add((input_folder+"Zhadron_2016_MU_08312022_url314_800_1600.root").c_str());
    
    chain1->MakeClass("TMCJets");
    chain2->MakeClass("TZJets");
    chain3->MakeClass("TZJetsData");
}

