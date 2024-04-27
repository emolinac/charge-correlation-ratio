#include "../include/TMCJets.h"
#include "../include/analysis-constants.h"

void test_eff()
{
    TFile* fin = new TFile("../input-files/Zhadron_MCReco_Sim09j_MD_2016_08162023.root");

    TH1F* hrec = new TH1F("hrec","",Nbin_jet_pt,jet_pt_min,jet_pt_max);
    TH1F* hthr = new TH1F("hthr","",Nbin_jet_pt,jet_pt_min,jet_pt_max);

    TTree* t = (TTree*) fin->Get("/mcjettuple/MCJetTree");

}