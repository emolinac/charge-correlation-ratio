#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"
#include "../include/utils-visual.h"

void macro_print_lh_m_resolution()
{
    // Open the file with the resolution TNtuple
    TFile* f = new TFile((output_folder+namef_ntuple_resolution).c_str());

    // Get the TNtuple
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_resolution.c_str());

    // Declare histograms and fill it
    TH1F* h = new TH1F("h","",50,-0.05,0.05);
    h->Sumw2();
    ntuple->Project("h","lh_m_mcreco-lh_m_mc",Form("jet_pt_mcreco>%f&&jet_pt_mc!=-999",jet_pt_min)+jet_eta_cut+track_cuts+topological_cuts+Zboson_cuts);

    set_histogram_style(h, kViolet+2, std_line_width, std_marker_style, std_marker_size);
    h->Draw();

    h->SetTitle(";#Delta lh_m(mcreco-mc);");

    gPad->SetLogy(1);
}