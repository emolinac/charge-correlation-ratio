#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"
#include "../include/utils-visual.h"

void macro_print_rc_z_stringbreakingfrac()
{
    TFile* fin = new TFile((output_folder+namef_rc_z_data_d).c_str());

    // Get the histograms to create one in top of each other
    TH1F* h_rc_z_data        = (TH1F*) fin->Get("rc_z");
    TH1F* h_rc_z_data_decays = (TH1F*) fin->Get("rc_z_decays");

    // Customize plots
    set_histogram_style(h_rc_z_data       , kCyan  , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_rc_z_data_decays, kCyan+3, std_line_width, std_marker_style, std_marker_size);

    // Create stack
    THStack* s = new THStack("s","");
    s->SetMaximum(0.6);
    s->SetMinimum(-0.600);
    s->Add(h_rc_z_data);
    s->Add(h_rc_z_data_decays);
    s->Draw("NOSTACK E1");

    s->SetTitle(";k_{t}(GeV);r_{c}");
    s->GetYaxis()->SetRangeUser(-1,1);

    //Set TLegend
    TLegend* legend = new TLegend(0.7,0.75,0.9,0.9);
    legend->AddEntry(h_rc_z_data,"data");
    legend->AddEntry(h_rc_z_data_decays,"data+stringbreakingfrac");

    legend->Draw();
}