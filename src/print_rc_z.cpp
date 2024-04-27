#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"

void print_rc_z()
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
    h_rc_z_mc->SetLineColor(kRed);
    h_rc_z_mc->SetLineWidth(2);
    h_rc_z_mc->SetMarkerStyle(20);
    h_rc_z_mc->SetMarkerColor(kRed);
    h_rc_z_mcreco->SetLineColor(kBlue);
    h_rc_z_mcreco->SetLineWidth(2);
    h_rc_z_mcreco->SetMarkerStyle(20);
    h_rc_z_mcreco->SetMarkerColor(kBlue);
    h_rc_z_data->SetLineColor(kGreen);
    h_rc_z_data->SetLineWidth(2);
    h_rc_z_data->SetMarkerStyle(20);
    h_rc_z_data->SetMarkerColor(kGreen);

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