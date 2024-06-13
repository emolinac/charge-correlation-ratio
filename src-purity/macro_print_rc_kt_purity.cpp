#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"
#include "../include/utils-visual.h"

void macro_print_rc_kt_purity()
{
    TFile* fin = new TFile((output_folder+namef_rc_kt_data_p).c_str());

    // Get the histograms to create one in top of each other
    TH1F* h_rc_kt_data        = (TH1F*) fin->Get("rc_kt");
    TH1F* h_rc_kt_data_purity = (TH1F*) fin->Get("rc_kt_purity");

    // Customize plots
    set_histogram_style(h_rc_kt_data       , kCyan  , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_rc_kt_data_purity, kCyan+3, std_line_width, std_marker_style, std_marker_size);

    // Create stack
    THStack* s = new THStack("s","");
    s->SetMaximum(0.6);
    s->SetMinimum(-0.600);
    s->Add(h_rc_kt_data);
    s->Add(h_rc_kt_data_purity);
    s->Draw("NOSTACK");

    s->SetTitle(";k_{t}(GeV);r_{c}");
    s->GetYaxis()->SetRangeUser(-1,1);

    //Set TLegend
    TLegend* legend = new TLegend(0.7,0.75,0.9,0.9);
    legend->AddEntry(h_rc_kt_data,"data");
    legend->AddEntry(h_rc_kt_data_purity,"data+purity");

    legend->Draw();
}