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
    TFile* fout = new TFile((output_folder+namef_rc_z_data_d).c_str(),"RECREATE");
    gROOT->cd();

    // Open the file with the ntuples
    TFile* fin     = new TFile((output_folder+namef_ntuple_dihadron).c_str());
    TFile* fdecays = new TFile((output_folder+namef_ntuple_decays).c_str());

    // Get the dihadron and decays ntuples
    TNtuple* ntuple_data   = (TNtuple*) fin->Get((name_ntuple_data).c_str());
    TNtuple* ntuple_decays = (TNtuple*) fdecays->Get((name_ntuple_decays).c_str());
    
    // Create the data histograms
    TH1F* hcs_samesign = new TH1F("hcs_samesign","",Nbin_z,z_limits);
    TH1F* hcs_diffsign = new TH1F("hcs_diffsign","",Nbin_z,z_limits);
    TH1F* hcs_sum      = new TH1F("hcs_sum"     ,"",Nbin_z,z_limits);
    TH1F* hcs_sub      = new TH1F("hcs_sub"     ,"",Nbin_z,z_limits);
    TH1F* rc           = new TH1F("rc"          ,"",Nbin_z,z_limits);

    hcs_samesign->Sumw2();
    hcs_diffsign->Sumw2();

    // Calculate rc for the data
    ntuple_data->Project("hcs_diffsign","nlh_z",diffsign_cut_data);
    ntuple_data->Project("hcs_samesign","nlh_z",samesign_cut_data);
    hcs_sub->Add(hcs_samesign,hcs_diffsign,1,-1);
    hcs_sum->Add(hcs_samesign,hcs_diffsign,1, 1);
    rc->Divide(hcs_sub,hcs_sum,1,1);

    // Calculate uncertainties
    set_uncertainties(hcs_samesign, hcs_diffsign, rc);

    // Write uncorrected rc
    fout->cd();
    hcs_sub->Write();
    hcs_sum->Write();
    rc->Write("rc_z");
    gROOT->cd();

    // Create decays plots
    TH1F* hstrbrk_diffsign = new TH1F("hstrbrk_diffsign","",Nbin_z,z_limits);
    TH1F* hall_diffsign    = new TH1F("hall_diffsign"   ,"",Nbin_z,z_limits);
    TH1F* hdecays_diffsign = new TH1F("hdecays_diffsign","",Nbin_z,z_limits);
    TH1F* hstrbrk_samesign = new TH1F("hstrbrk_samesign","",Nbin_z,z_limits);
    TH1F* hall_samesign    = new TH1F("hall_samesign"   ,"",Nbin_z,z_limits);
    TH1F* hdecays_samesign = new TH1F("hdecays_samesign","",Nbin_z,z_limits);

    // Get the string breaking fraction
    ntuple_decays->Project("hall_diffsign"   ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==0");
    ntuple_decays->Project("hstrbrk_diffsign","nlh_z",jet_cuts+trackmc_cuts+"eq_charge==0&&lh_motherid<22&&lh_motherid>-10&&nlh_motherid<22&&nlh_motherid>-10");
    ntuple_decays->Project("hall_samesign"   ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==1");
    ntuple_decays->Project("hstrbrk_samesign","nlh_z",jet_cuts+trackmc_cuts+"eq_charge==1&&lh_motherid<22&&lh_motherid>-10&&nlh_motherid<22&&nlh_motherid>-10");
    hdecays_diffsign->Divide(hstrbrk_diffsign,hall_diffsign,1,1,"B");
    hdecays_samesign->Divide(hstrbrk_samesign,hall_samesign,1,1,"B");
    
    // Apply string breaking fraction
    TH1F* hcs_samesign_d = new TH1F("hcs_samesign_d","",Nbin_z,z_limits);
    TH1F* hcs_diffsign_d = new TH1F("hcs_diffsign_d","",Nbin_z,z_limits);
    hcs_samesign_d->Sumw2();
    hcs_diffsign_d->Sumw2();
    ntuple_data->Project("hcs_diffsign_d","nlh_z",diffsign_cut_data);
    ntuple_data->Project("hcs_samesign_d","nlh_z",samesign_cut_data);
    
    hcs_diffsign_d->Multiply(hdecays_diffsign);
    hcs_samesign_d->Multiply(hdecays_samesign);

    // Set uncertainties due to string breaking fraction
    set_uncertainties_purity(hcs_diffsign, hdecays_diffsign, hcs_diffsign_d);
    set_uncertainties_purity(hcs_samesign, hdecays_samesign, hcs_samesign_d);

    // Calculate rc again
    hcs_sub->Add(hcs_samesign_d,hcs_diffsign_d,1,-1);
    hcs_sum->Add(hcs_samesign_d,hcs_diffsign_d,1, 1);
    rc->Divide(hcs_sub,hcs_sum,1,1);

    // Calculate uncertainties
    set_uncertainties(hcs_samesign_d, hcs_diffsign_d, rc);

    // Write decays corrected rc
    fout->cd();
    rc->Write("rc_z_decays");
    gROOT->cd();

    // Close the file
    fout->Close();
 
    return 0;
}