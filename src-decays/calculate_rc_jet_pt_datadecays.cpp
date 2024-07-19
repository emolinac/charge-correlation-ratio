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
    TFile* fout = new TFile((output_folder+namef_rc_jet_pt_data_dd).c_str(),"RECREATE");
    gROOT->cd();

    // Open the file with the ntuples
    TFile* fin         = new TFile((output_folder+namef_ntuple_dihadron).c_str());
    TFile* fdatadecays = new TFile((output_folder+namef_ntuple_datadecays).c_str());

    // Get the dihadron and datadecays ntuples
    TNtuple* ntuple_data       = (TNtuple*) fin->Get((name_ntuple_data).c_str());
    TNtuple* ntuple_datadecays = (TNtuple*) fdatadecays->Get((name_ntuple_datadecays).c_str());
    
    // Create the data histograms
    TH1F* hcs_samesign = new TH1F("hcs_samesign","",Nbin_jet_pt,jet_pt_limits);
    TH1F* hcs_diffsign = new TH1F("hcs_diffsign","",Nbin_jet_pt,jet_pt_limits);
    TH1F* hcs_sum      = new TH1F("hcs_sum"     ,"",Nbin_jet_pt,jet_pt_limits);
    TH1F* hcs_sub      = new TH1F("hcs_sub"     ,"",Nbin_jet_pt,jet_pt_limits);
    TH1F* rc           = new TH1F("rc"          ,"",Nbin_jet_pt,jet_pt_limits);

    hcs_samesign->Sumw2();
    hcs_diffsign->Sumw2();

    // Calculate rc for the data
    ntuple_data->Project("hcs_diffsign","jet_pt",diffsign_cut_data);
    ntuple_data->Project("hcs_samesign","jet_pt",samesign_cut_data);
    hcs_sub->Add(hcs_samesign,hcs_diffsign,1,-1);
    hcs_sum->Add(hcs_samesign,hcs_diffsign,1, 1);
    rc->Divide(hcs_sub,hcs_sum,1,1);

    // Calculate uncertainties
    set_uncertainties(hcs_samesign, hcs_diffsign, rc);

    // Write uncorrected rc
    fout->cd();
    hcs_sub->Write();
    hcs_sum->Write();
    rc->Write("rc_jet_pt");
    gROOT->cd();

    // Create datadecays plots
    TH1F* hddecays_diffsign    = new TH1F("hddecays_diffsign"   ,"",Nbin_jet_pt,jet_pt_limits);
    TH1F* hall_diffsign        = new TH1F("hall_diffsign"       ,"",Nbin_jet_pt,jet_pt_limits);
    TH1F* hdatadecays_diffsign = new TH1F("hdatadecays_diffsign","",Nbin_jet_pt,jet_pt_limits);
    TH1F* hddecays_samesign    = new TH1F("hddecays_samesign"   ,"",Nbin_jet_pt,jet_pt_limits);
    TH1F* hall_samesign        = new TH1F("hall_samesign"       ,"",Nbin_jet_pt,jet_pt_limits);
    TH1F* hdatadecays_samesign = new TH1F("hdatadecays_samesign","",Nbin_jet_pt,jet_pt_limits);

    // Get the string breaking fraction
    ntuple_datadecays->Project("hall_diffsign"    ,"jet_pt",diffsign_cut_data);
    ntuple_datadecays->Project("hddecays_diffsign","jet_pt",diffsign_cut_data_decay);
    ntuple_datadecays->Project("hall_samesign"    ,"jet_pt",samesign_cut_data);
    ntuple_datadecays->Project("hddecays_samesign","jet_pt",samesign_cut_data_decay);
    hdatadecays_diffsign->Divide(hddecays_diffsign,hall_diffsign,1,1,"B");
    hdatadecays_samesign->Divide(hddecays_samesign,hall_samesign,1,1,"B");
    
    // Apply string breaking fraction
    TH1F* hcs_samesign_d = new TH1F("hcs_samesign_d","",Nbin_jet_pt,jet_pt_limits);
    TH1F* hcs_diffsign_d = new TH1F("hcs_diffsign_d","",Nbin_jet_pt,jet_pt_limits);
    hcs_samesign_d->Sumw2();
    hcs_diffsign_d->Sumw2();
    ntuple_data->Project("hcs_diffsign_d","jet_pt",diffsign_cut_data);
    ntuple_data->Project("hcs_samesign_d","jet_pt",samesign_cut_data);
    
    hcs_diffsign_d->Multiply(hdatadecays_diffsign);
    hcs_samesign_d->Multiply(hdatadecays_samesign);

    // Set uncertainties due to string breaking fraction
    set_uncertainties_purity(hcs_diffsign, hdatadecays_diffsign, hcs_diffsign_d);
    set_uncertainties_purity(hcs_samesign, hdatadecays_samesign, hcs_samesign_d);

    // Calculate rc again
    hcs_sub->Add(hcs_samesign_d,hcs_diffsign_d,1,-1);
    hcs_sum->Add(hcs_samesign_d,hcs_diffsign_d,1, 1);
    rc->Divide(hcs_sub,hcs_sum,1,1);

    // Calculate uncertainties
    set_uncertainties(hcs_samesign_d, hcs_diffsign_d, rc);

    // Write datadecays corrected rc
    fout->cd();
    rc->Write("rc_jet_pt_datadecays");
    gROOT->cd();

    // Close the file
    fout->Close();
 
    return 0;
}