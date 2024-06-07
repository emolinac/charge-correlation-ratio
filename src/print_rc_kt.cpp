#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"

void print_rc_kt()
{
    TFile* fin1 = new TFile((output_folder+"rc_kt_mc.root").c_str());
    TFile* fin2 = new TFile((output_folder+"rc_kt_mcreco.root").c_str());
    TFile* fin3 = new TFile((output_folder+"rc_kt_data.root").c_str());

    // Get the histograms to create one in top of each other
    TH1F* h_rc_kt_mc     = (TH1F*) fin1->Get("rc_kt");
    TH1F* h_rc_kt_mcreco = (TH1F*) fin2->Get("rc_kt");
    TH1F* h_rc_kt_data   = (TH1F*) fin3->Get("rc_kt");

    // Customize plots
    h_rc_kt_mc->SetLineColor(kRed);
    h_rc_kt_mc->SetLineWidth(2);
    h_rc_kt_mc->SetMarkerStyle(20);
    h_rc_kt_mc->SetMarkerColor(kRed);
    h_rc_kt_mcreco->SetLineColor(kBlue);
    h_rc_kt_mcreco->SetLineWidth(2);
    h_rc_kt_mcreco->SetMarkerStyle(20);
    h_rc_kt_mcreco->SetMarkerColor(kBlue);
    h_rc_kt_data->SetLineColor(kGreen);
    h_rc_kt_data->SetLineWidth(2);
    h_rc_kt_data->SetMarkerStyle(20);
    h_rc_kt_data->SetMarkerColor(kGreen);

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