#include "../include/analysis-constants.h"
#include "../include/directories.h"
#include "../include/names.h"
#include "../include/utils-algorithms.h"
#include "../include/utils-visual.h"

void macro_print_rc_z()
{
    // Open the rc(z) files
    TFile* fin1 = new TFile((output_folder+"rc_z_mc.root").c_str());
    TFile* fin2 = new TFile((output_folder+"rc_z_mcreco.root").c_str());
    TFile* fin3 = new TFile((output_folder+"rc_z_data.root").c_str());

    // Get the histograms to create one in top of each other
    TH1F* h_rc_z_mc     = (TH1F*) fin1->Get("rc_z");
    TH1F* h_rc_z_mcreco = (TH1F*) fin2->Get("rc_z");
    TH1F* h_rc_z_data   = (TH1F*) fin3->Get("rc_z");

    // Customize plots
    set_histogram_style(h_rc_z_mc    , kRed  , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_rc_z_mcreco, kBlue , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_rc_z_data  , kGreen, std_line_width, std_marker_style, std_marker_size);

    // Create stack
    THStack* s = new THStack("s","");
    s->SetMinimum(-1.0);
    s->SetMaximum(0.1);
    s->Add(h_rc_z_mc);
    s->Add(h_rc_z_mcreco);
    s->Add(h_rc_z_data);
    s->Draw("NOSTACK");

    s->SetTitle(";z;r_{c}");

    //Set TLegend
    TLegend* legend = new TLegend(0.7,0.75,0.9,0.9);
    legend->AddEntry(h_rc_z_mc,"mc");
    legend->AddEntry(h_rc_z_mcreco,"mcreco");
    legend->AddEntry(h_rc_z_data,"data");
    legend->Draw();

}