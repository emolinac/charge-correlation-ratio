#include "../include/analysis-constants.h"
#include "../include/directories.h"
#include "../include/names.h"
#include "../include/utils-algorithms.h"
#include "../include/utils-visual.h"

void macro_print_datadecays_jet_pt()
{
    // Open the file with the decay TNtuple
    TFile* f = new TFile((output_folder+namef_ntuple_datadecays).c_str());

    // Get the TNtuple
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_datadecays.c_str());

    // Declare and fill different type of histos
    TH1F* h_eqcharge        = new TH1F("h_eqcharge"       ,"",Nbin_jet_pt,jet_pt_limits);
    TH1F* h_neqcharge       = new TH1F("h_neqcharge"      ,"",Nbin_jet_pt,jet_pt_limits);
    TH1F* h_eqcharge_all    = new TH1F("h_eqcharge_all"   ,"",Nbin_jet_pt,jet_pt_limits);
    TH1F* h_neqcharge_all   = new TH1F("h_neqcharge_all"  ,"",Nbin_jet_pt,jet_pt_limits);
    TH1F* h_eqcharge_ratio  = new TH1F("h_eqcharge_ratio" ,"",Nbin_jet_pt,jet_pt_limits);
    TH1F* h_neqcharge_ratio = new TH1F("h_neqcharge_ratio","",Nbin_jet_pt,jet_pt_limits);
    
    h_eqcharge->Sumw2();
    h_neqcharge->Sumw2();
    h_eqcharge_all->Sumw2();
    h_neqcharge_all->Sumw2();
    
    ntuple->Project("h_eqcharge_all" ,"jet_pt",samesign_cut_data);    
    ntuple->Project("h_neqcharge_all","jet_pt",diffsign_cut_data);    
    ntuple->Project("h_eqcharge"     ,"jet_pt",samesign_cut_data_decay);    
    ntuple->Project("h_neqcharge"    ,"jet_pt",diffsign_cut_data_decay);    
    
    // Calculate ratios
    h_eqcharge_ratio->Divide(h_eqcharge,h_eqcharge_all,1,1,"B");
    h_neqcharge_ratio->Divide(h_neqcharge,h_neqcharge_all,1,1,"B");

    // Add some color and draw the histograms
    set_histogram_style(h_eqcharge_ratio , kViolet+2, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_neqcharge_ratio, kViolet-5, std_line_width, std_marker_style, std_marker_size);
    
    THStack* hs = new THStack("","");
    hs->Add(h_eqcharge_ratio);
    hs->Add(h_neqcharge_ratio);
    
    hs->Draw("NOSTACK");

    hs->SetTitle(";Jet pt(GeV);Fraction String Dihadrons");

    TLegend* l = new TLegend();
    l->AddEntry(h_neqcharge_ratio,"Different sign hadrons","lp");
    l->AddEntry(h_eqcharge_ratio ,"Same sign hadrons","lp");
    l->Draw("SAME");
}
