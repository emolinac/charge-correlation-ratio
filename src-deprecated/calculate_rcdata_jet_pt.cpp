#include <iostream>
#include "analysis-constants.h"
#include "names.h"
#include "utils.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TCut.h"

int main()
{
    // Open the output file
    TFile* fout = new TFile((output_folder+namef_rc_jet_pt_data).c_str(),"RECREATE");
    gROOT->cd();

    // Open the file with the TNtuples
    TFile* fin = new TFile((output_folder+namef_ntuple_dihadron).c_str());
    
    // Get the dihadron TNtuple
    TNtuple* ntuple = (TNtuple*) fin->Get(name_ntuple_data.c_str());
    
    // Create the histograms
    TH1F* hcs_samesign = new TH1F("hcs_samesign","",Nbin_jet_pt,jet_pt_min,jet_pt_max);
    TH1F* hcs_diffsign = new TH1F("hcs_diffsign","",Nbin_jet_pt,jet_pt_min,jet_pt_max);
    TH1F* hcs_sum      = new TH1F("hcs_sum"     ,"",Nbin_jet_pt,jet_pt_min,jet_pt_max);
    TH1F* hcs_sub      = new TH1F("hcs_sub"     ,"",Nbin_jet_pt,jet_pt_min,jet_pt_max);
    TH1F* rc           = new TH1F("rc"          ,"",Nbin_jet_pt,jet_pt_min,jet_pt_max);

    hcs_samesign->Sumw2();
    hcs_diffsign->Sumw2();

    // Calculate rc for the data
    ntuple->Project("hcs_diffsign","jet_pt",diffsign_cut_data);
    ntuple->Project("hcs_samesign","jet_pt",samesign_cut_data);
    hcs_sub->Add(hcs_samesign,hcs_diffsign,1,-1);
    hcs_sum->Add(hcs_samesign,hcs_diffsign,1, 1);
    rc->Divide(hcs_sub,hcs_sum,1,1);

    // Calculate uncertainties
    set_uncertainties(hcs_samesign, hcs_diffsign, rc);

    // Write it
    fout->cd();
    hcs_sub->Write();
    hcs_sum->Write();
    rc->Write("rc_jet_pt");
    gROOT->cd();

    fout->Close();

    return 0;
}