#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"

void print_rc_jet_pt_purity()
{
    TFile* fin = new TFile((output_folder+namef_rc_jet_pt_data_p).c_str());

    // Get the histograms to create one in top of each other
    TH1F* h_rc_jet_pt_data        = (TH1F*) fin->Get("rc_jet_pt");
    TH1F* h_rc_jet_pt_data_purity = (TH1F*) fin->Get("rc_jet_pt_purity");

    // Customize plots
    h_rc_jet_pt_data->SetLineColor(kCyan);
    h_rc_jet_pt_data->SetLineWidth(2);
    h_rc_jet_pt_data->SetMarkerStyle(20);
    h_rc_jet_pt_data->SetMarkerColor(kCyan);
    h_rc_jet_pt_data_purity->SetLineColor(kCyan+3);
    h_rc_jet_pt_data_purity->SetLineWidth(2);
    h_rc_jet_pt_data_purity->SetMarkerStyle(20);
    h_rc_jet_pt_data_purity->SetMarkerColor(kCyan+3);

    // Create stack
    THStack* s = new THStack("s","");
    s->SetMaximum(-0.001);
    s->SetMinimum(-0.600);
    s->Add(h_rc_jet_pt_data);
    s->Add(h_rc_jet_pt_data_purity);
    s->Draw("NOSTACK E1");

    s->SetTitle(";jet p_{T}(GeV);r_{c}");
    s->GetYaxis()->SetRangeUser(-1,1);

    //Set TLegend
    TLegend* legend = new TLegend(0.7,0.75,0.9,0.9);
    legend->AddEntry(h_rc_jet_pt_data,"data");
    legend->AddEntry(h_rc_jet_pt_data_purity,"data+purity");

    legend->Draw();
}