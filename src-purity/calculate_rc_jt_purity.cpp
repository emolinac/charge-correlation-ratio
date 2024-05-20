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
    // Open the output files
    TFile* fout = new TFile((output_folder+namef_rc_jt_data_p).c_str(),"RECREATE");
    gROOT->cd();

    // Open the file with the ntuples
    TFile* fin     = new TFile((output_folder+namef_ntuple_dihadron).c_str());
    TFile* fpurity = new TFile((output_folder+namef_ntuple_purity).c_str());

    // Get the dihadron and purity ntuples
    TNtuple* ntuple_data   = (TNtuple*) fin->Get((name_ntuple_data).c_str());
    TNtuple* ntuple_purity = (TNtuple*) fpurity->Get((name_ntuple_purity).c_str());
    
    // Create the data histograms
    TH1F* hcs_samesign = new TH1F("hcs_samesign","",Nbin_jt,jt_min,jt_max);
    TH1F* hcs_diffsign = new TH1F("hcs_diffsign","",Nbin_jt,jt_min,jt_max);
    TH1F* hcs_sum      = new TH1F("hcs_sum"     ,"",Nbin_jt,jt_min,jt_max);
    TH1F* hcs_sub      = new TH1F("hcs_sub"     ,"",Nbin_jt,jt_min,jt_max);
    TH1F* rc           = new TH1F("rc"          ,"",Nbin_jt,jt_min,jt_max);

    hcs_samesign->Sumw2();
    hcs_diffsign->Sumw2();

    // Calculate rc for the data
    ntuple_data->Project("hcs_diffsign","nlh_jt",diffsign_cut_data);
    ntuple_data->Project("hcs_samesign","nlh_jt",samesign_cut_data);
    hcs_sub->Add(hcs_samesign,hcs_diffsign,1,-1);
    hcs_sum->Add(hcs_samesign,hcs_diffsign,1, 1);
    rc->Divide(hcs_sub,hcs_sum,1,1);

    // Calculate uncertainties
    set_uncertainties(hcs_samesign, hcs_diffsign, rc);

    // Write uncorrected rc
    fout->cd();
    hcs_sub->Write();
    hcs_sum->Write();
    rc->Write("rc_jt");
    gROOT->cd();

    // Create purity plots
    TH1F* hrecgen_diffsign = new TH1F("hrecgen_diffsign","",Nbin_jt,jt_min,jt_max);
    TH1F* hrec_diffsign    = new TH1F("hrec_diffsign"   ,"",Nbin_jt,jt_min,jt_max);
    TH1F* hpurity_diffsign = new TH1F("hpurity_diffsign","",Nbin_jt,jt_min,jt_max);
    TH1F* hrecgen_samesign = new TH1F("hrecgen_samesign","",Nbin_jt,jt_min,jt_max);
    TH1F* hrec_samesign    = new TH1F("hrec_samesign"   ,"",Nbin_jt,jt_min,jt_max);
    TH1F* hpurity_samesign = new TH1F("hpurity_samesign","",Nbin_jt,jt_min,jt_max);

    // Get the purities
    ntuple_purity->Project("hrec_diffsign"   ,"nlh_jt",diffsign_cut_data);
    ntuple_purity->Project("hrecgen_diffsign","nlh_jt","signal==1"&&diffsign_cut_data);
    ntuple_purity->Project("hrec_samesign"   ,"nlh_jt",samesign_cut_data);
    ntuple_purity->Project("hrecgen_samesign","nlh_jt","signal==1"&&samesign_cut_data);
    hpurity_diffsign->Divide(hrecgen_diffsign,hrec_diffsign,1,1,"B");
    hpurity_samesign->Divide(hrecgen_samesign,hrec_samesign,1,1,"B");
    
    // Apply purities
    TH1F* hcs_samesign_p = new TH1F("hcs_samesign_p","",Nbin_jt,jt_min,jt_max);
    TH1F* hcs_diffsign_p = new TH1F("hcs_diffsign_p","",Nbin_jt,jt_min,jt_max);
    hcs_samesign_p->Sumw2();
    hcs_diffsign_p->Sumw2();
    ntuple_data->Project("hcs_diffsign_p","nlh_jt",diffsign_cut_data);
    ntuple_data->Project("hcs_samesign_p","nlh_jt",samesign_cut_data);
    
    hcs_diffsign_p->Multiply(hpurity_diffsign);
    hcs_samesign_p->Multiply(hpurity_samesign);

    // Set uncertainties due to purities
    set_uncertainties_purity(hcs_diffsign, hpurity_diffsign, hcs_diffsign_p);
    set_uncertainties_purity(hcs_samesign, hpurity_samesign, hcs_samesign_p);

    // Calculate rc again
    hcs_sub->Add(hcs_samesign_p,hcs_diffsign_p,1,-1);
    hcs_sum->Add(hcs_samesign_p,hcs_diffsign_p,1, 1);
    rc->Divide(hcs_sub,hcs_sum,1,1);

    // Calculate uncertainties
    set_uncertainties(hcs_samesign_p, hcs_diffsign_p, rc);

    // Write purity corrected rc
    fout->cd();
    rc->Write("rc_jt_purity");
    gROOT->cd();

    // Close the file
    fout->Close();
 
    return 0;
}