#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"

void macro_print_rc_jet_pt()
{
    TFile* fin1 = new TFile((output_folder+"rc_jet_pt_mc.root").c_str());
    TFile* fin2 = new TFile((output_folder+"rc_jet_pt_mcreco.root").c_str());
    TFile* fin3 = new TFile((output_folder+"rc_jet_pt_data.root").c_str());

    // Get the histograms to create one in top of each other
    TH1F* h_rc_jet_pt_mc     = (TH1F*) fin1->Get("rc_jet_pt");
    TH1F* h_rc_jet_pt_mcreco = (TH1F*) fin2->Get("rc_jet_pt");
    TH1F* h_rc_jet_pt_data   = (TH1F*) fin3->Get("rc_jet_pt");

    // Customize plots
    h_rc_jet_pt_mc->SetLineColor(kRed);
    h_rc_jet_pt_mc->SetLineWidth(2);
    h_rc_jet_pt_mc->SetMarkerStyle(20);
    h_rc_jet_pt_mc->SetMarkerColor(kRed);
    h_rc_jet_pt_mcreco->SetLineColor(kBlue);
    h_rc_jet_pt_mcreco->SetLineWidth(2);
    h_rc_jet_pt_mcreco->SetMarkerStyle(20);
    h_rc_jet_pt_mcreco->SetMarkerColor(kBlue);
    h_rc_jet_pt_data->SetLineColor(kGreen);
    h_rc_jet_pt_data->SetLineWidth(2);
    h_rc_jet_pt_data->SetMarkerStyle(20);
    h_rc_jet_pt_data->SetMarkerColor(kGreen);

    // Create stack
    THStack* s = new THStack("s","");
    s->SetMaximum(-0.001);
    s->SetMinimum(-0.600);
    s->Add(h_rc_jet_pt_mc);
    s->Add(h_rc_jet_pt_mcreco);
    s->Add(h_rc_jet_pt_data);
    s->Draw("NOSTACK");

    s->SetTitle(";jet p_{T}(GeV);r_{c}");
    s->GetYaxis()->SetRangeUser(-1,1);

    //Set TLegend
    TLegend* legend = new TLegend(0.7,0.75,0.9,0.9);
    legend->AddEntry(h_rc_jet_pt_mc,"mc");
    legend->AddEntry(h_rc_jet_pt_mcreco,"mcreco");
    legend->AddEntry(h_rc_jet_pt_data,"data");

    legend->Draw();
}