#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"
#include "../include/utils-visual.h"

void macro_print_diffmothers_z()
{
    // Open the file with the decay TNtuple
    TFile* f = new TFile((output_folder+namef_ntuple_decays).c_str());

    // Get the TNtuple
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_decays.c_str());

    // Declare and fill different type of histos
    TH1F* h_all    = new TH1F("h_all"   ,"",Nbin_z,z_limits);
    TH1F* h_lh     = new TH1F("h_lh"    ,"",Nbin_z,z_limits);
    TH1F* h_nlh    = new TH1F("h_nlh"   ,"",Nbin_z,z_limits);
    TH1F* h_lh_nlh = new TH1F("h_lh_nlh","",Nbin_z,z_limits);

    h_all->Sumw2();
    h_lh->Sumw2();
    h_nlh->Sumw2();
    h_lh_nlh->Sumw2();
    
    ntuple->Project("h_all"   ,"nlh_pz/(nlh_pz+lh_pz)","");    
    ntuple->Project("h_lh"    ,"nlh_pz/(nlh_pz+lh_pz)","lh_motherid<10&&lh_motherid>-10&&nlh_motherid<10&&nlh_motherid>-10&&eq_charge==1");    
    ntuple->Project("h_nlh"   ,"nlh_pz/(nlh_pz+lh_pz)","lh_motherid<10&&lh_motherid>-10&&nlh_motherid<10&&nlh_motherid>-10&&eq_charge==0");    
    ntuple->Project("h_lh_nlh","nlh_pz/(nlh_pz+lh_pz)","lh_motherid<10&&lh_motherid>-10&&nlh_motherid<10&&nlh_motherid>-10");    

    // Add some color and draw the histograms
    set_histogram_style(h_all   , kViolet  , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_lh    , kViolet+2, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_nlh   , kViolet-5, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_lh_nlh, kCyan    , std_line_width, std_marker_style, std_marker_size);
    
    THStack* hs = new THStack("","");
    hs->Add(h_all);
    hs->Add(h_lh);
    hs->Add(h_nlh);
    hs->Add(h_lh_nlh);

    hs->Draw("NOSTACK");

    gPad->SetLogy(1);
}