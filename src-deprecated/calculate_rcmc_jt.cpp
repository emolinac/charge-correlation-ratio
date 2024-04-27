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
    TFile* fout = new TFile((output_folder+name_rc_jt_mc).c_str(),"RECREATE");
    gROOT->cd();

    // Open the file with the TNtuples
    TFile* fin = new TFile((output_folder+name_ntuple_dihadron).c_str());
    
    // Get the dihadron TNtuple
    TNtuple* ntuple = (TNtuple*) fin->Get(name_ntuple_mc.c_str());
    
    // Create the histograms
    TH1F* hcs_samesign = new TH1F("hcs_samesign","",Nbin_jt,jt_min,jt_max);
    TH1F* hcs_diffsign = new TH1F("hcs_diffsign","",Nbin_jt,jt_min,jt_max);
    TH1F* hcs_sum      = new TH1F("hcs_sum"     ,"",Nbin_jt,jt_min,jt_max);
    TH1F* hcs_sub      = new TH1F("hcs_sub"     ,"",Nbin_jt,jt_min,jt_max);
    TH1F* rc           = new TH1F("rc"          ,"",Nbin_jt,jt_min,jt_max);

    hcs_samesign->Sumw2();
    hcs_diffsign->Sumw2();

    // Calculate rc for the mc
    ntuple->Project("hcs_diffsign","nlh_jt",diffsign_cut_mc);
    ntuple->Project("hcs_samesign","nlh_jt",samesign_cut_mc);
    hcs_sub->Add(hcs_samesign,hcs_diffsign,1,-1);
    hcs_sum->Add(hcs_samesign,hcs_diffsign,1, 1);
    rc->Divide(hcs_sub,hcs_sum,1,1);

    // Calculate uncertainties
    set_uncertainties(hcs_samesign, hcs_diffsign, rc);

    // Write it
    fout->cd();
    hcs_sub->Write();
    hcs_sum->Write();
    rc->Write("rc_jt");
    gROOT->cd();

    fout->Close();

    return 0;
}