#include "../include/analysis-constants.h"
#include "../include/directories.h"
#include "../include/names.h"
#include "../include/utils-algorithms.h"
#include "../include/utils-visual.h"

void macro_print_jet_pt_resolution()
{
    // Open the file with the resolution TNtuple
    TFile* f = new TFile((output_folder+namef_ntuple_resolution).c_str());

    // Get the TNtuple
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_resolution.c_str());

    // Declare histograms and fill it
    TH1F* h = new TH1F("h","",50,-20,20);
    h->Sumw2();
    ntuple->Project("h","jet_pt_mcreco-jet_pt_mc",Form("jet_pt_mcreco>%f&&jet_pt_mc!=-999",jet_pt_min)+jet_eta_cut+track_cuts+topological_cuts+Zboson_cuts);

    set_histogram_style(h, kViolet+2, std_line_width, std_marker_style, std_marker_size);
    h->Draw();

    h->SetTitle(";#Delta Jet p_{T}(mcreco-mc)(GeV);");

    gPad->SetLogy(1);
}