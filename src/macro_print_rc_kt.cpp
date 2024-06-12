#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"
#include "../include/utils-visual.h"

void macro_print_rc_kt()
{
    TFile* fin1 = new TFile((output_folder+"rc_kt_mc.root").c_str());
    TFile* fin2 = new TFile((output_folder+"rc_kt_mcreco.root").c_str());
    TFile* fin3 = new TFile((output_folder+"rc_kt_data.root").c_str());

    // Get the histograms to create one in top of each other
    TH1F* h_rc_kt_mc     = (TH1F*) fin1->Get("rc_kt");
    TH1F* h_rc_kt_mcreco = (TH1F*) fin2->Get("rc_kt");
    TH1F* h_rc_kt_data   = (TH1F*) fin3->Get("rc_kt");

    // Customize plots
    set_histogram_style(h_rc_kt_mc    , kRed  , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_rc_kt_mcreco, kBlue , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_rc_kt_data  , kGreen, std_line_width, std_marker_style, std_marker_size);

    // Create stack
    THStack* s = new THStack("s","");
    s->SetMaximum(-0.001);
    s->SetMinimum(-0.600);
    s->Add(h_rc_kt_mc);
    s->Add(h_rc_kt_mcreco);
    s->Add(h_rc_kt_data);
    s->Draw("NOSTACK");

    s->SetTitle(";k_{#perp}(GeV);r_{c}");
    s->GetYaxis()->SetRangeUser(-1,1);

    //Set TLegend
    TLegend* legend = new TLegend(0.7,0.75,0.9,0.9);
    legend->AddEntry(h_rc_kt_mc,"mc");
    legend->AddEntry(h_rc_kt_mcreco,"mcreco");
    legend->AddEntry(h_rc_kt_data,"data");

    legend->Draw();

}