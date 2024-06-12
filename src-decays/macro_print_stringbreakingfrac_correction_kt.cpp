#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"
#include "../include/utils-visual.h"

void macro_print_stringbreakingfrac_correction_kt()
{
    // Open the file with the decay TNtuple
    TFile* f = new TFile((output_folder+namef_ntuple_decays).c_str());

    // Get the TNtuple
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_decays.c_str());

    // Declare and fill different type of histos
    TH1F* h_all             = new TH1F("h_all"            ,"",Nbin_kt,kt_limits);
    TH1F* h_eqcharge        = new TH1F("h_eqcharge"       ,"",Nbin_kt,kt_limits);
    TH1F* h_neqcharge       = new TH1F("h_neqcharge"      ,"",Nbin_kt,kt_limits);
    TH1F* h_eqcharge_ratio  = new TH1F("h_eqcharge_ratio" ,"",Nbin_kt,kt_limits);
    TH1F* h_neqcharge_ratio = new TH1F("h_neqcharge_ratio","",Nbin_kt,kt_limits);
    

    h_all->Sumw2();
    h_eqcharge->Sumw2();
    h_neqcharge->Sumw2();
    
    ntuple->Project("h_all"      ,"dh_kt","");    
    ntuple->Project("h_eqcharge" ,"dh_kt","lh_motherid<22&&lh_motherid>-10&&nlh_motherid<22&&nlh_motherid>-10&&eq_charge==1");    
    ntuple->Project("h_neqcharge","dh_kt","lh_motherid<22&&lh_motherid>-10&&nlh_motherid<22&&nlh_motherid>-10&&eq_charge==0");    
    
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

    hs->SetTitle(";k_{t}(GeV);string breaking frac.");

    gPad->SetLogy(1);
}
