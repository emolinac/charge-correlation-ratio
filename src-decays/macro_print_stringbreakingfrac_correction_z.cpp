#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"
#include "../include/utils-visual.h"

void macro_print_stringbreakingfrac_correction_z()
{
    // Open the file with the decay TNtuple
    TFile* f = new TFile((output_folder+namef_ntuple_decays).c_str());

    // Get the TNtuple
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_decays.c_str());

    // Declare and fill different type of histos
    TH1F* h_all             = new TH1F("h_all"            ,"",Nbin_z,z_limits);
    TH1F* h_eqcharge        = new TH1F("h_eqcharge"       ,"",Nbin_z,z_limits);
    TH1F* h_neqcharge       = new TH1F("h_neqcharge"      ,"",Nbin_z,z_limits);
    TH1F* h_eqcharge_ratio  = new TH1F("h_eqcharge_ratio" ,"",Nbin_z,z_limits);
    TH1F* h_neqcharge_ratio = new TH1F("h_neqcharge_ratio","",Nbin_z,z_limits);
    

    h_all->Sumw2();
    h_eqcharge->Sumw2();
    h_neqcharge->Sumw2();
    
    ntuple->Project("h_all"      ,"nlh_pz/(lh_pz+nlh_pz)","");    
    ntuple->Project("h_eqcharge" ,"nlh_pz/(lh_pz+nlh_pz)","lh_motherid<22&&lh_motherid>-10&&nlh_motherid<22&&nlh_motherid>-10&&eq_charge==1");    
    ntuple->Project("h_neqcharge","nlh_pz/(lh_pz+nlh_pz)","lh_motherid<22&&lh_motherid>-10&&nlh_motherid<22&&nlh_motherid>-10&&eq_charge==0");    
    
    // Calculate ratios
    h_eqcharge_ratio->Divide(h_eqcharge,h_all,1,1,"B");
    h_neqcharge_ratio->Divide(h_neqcharge,h_all,1,1,"B");

    // Add some color and draw the histograms
    set_histogram_style(h_eqcharge_ratio , kViolet+2, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_neqcharge_ratio, kViolet-5, std_line_width, std_marker_style, std_marker_size);
    
    THStack* hs = new THStack("","");
    hs->Add(h_eqcharge_ratio);
    hs->Add(h_neqcharge_ratio);
    
    hs->Draw("NOSTACK");

    hs->SetTitle(";z;string breaking frac.");

    gPad->SetLogy(1);
}
