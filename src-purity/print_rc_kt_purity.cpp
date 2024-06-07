#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"

void print_rc_kt_purity()
{
    TFile* fin = new TFile((output_folder+namef_rc_kt_data_p).c_str());

    // Get the histograms to create one in top of each other
    TH1F* h_rc_kt_data        = (TH1F*) fin->Get("rc_kt");
    TH1F* h_rc_kt_data_purity = (TH1F*) fin->Get("rc_kt_purity");

    // Customize plots
    h_rc_kt_data->SetLineColor(kCyan);
    h_rc_kt_data->SetLineWidth(2);
    h_rc_kt_data->SetMarkerStyle(20);
    h_rc_kt_data->SetMarkerColor(kCyan);
    h_rc_kt_data_purity->SetLineColor(kCyan+3);
    h_rc_kt_data_purity->SetLineWidth(2);
    h_rc_kt_data_purity->SetMarkerStyle(20);
    h_rc_kt_data_purity->SetMarkerColor(kCyan+3);

    // Create stack
    THStack* s = new THStack("s","");
    s->SetMaximum(0.6);
    s->SetMinimum(-0.600);
    s->Add(h_rc_kt_data);
    s->Add(h_rc_kt_data_purity);
    s->Draw("NOSTACK E1");

    s->SetTitle(";k_{#perp}(GeV);r_{c}");
    s->GetYaxis()->SetRangeUser(-1,1);

    //Set TLegend
    TLegend* legend = new TLegend(0.7,0.75,0.9,0.9);
    legend->AddEntry(h_rc_kt_data,"data");
    legend->AddEntry(h_rc_kt_data_purity,"data+purity");

    legend->Draw();
}