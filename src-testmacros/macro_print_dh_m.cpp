#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"
#include "../include/utils-visual.h"

void macro_print_dh_m()
{
    // Open file and Ntuple
    TFile* f = new TFile((output_folder+namef_ntuple_dihadron).c_str());
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_data.c_str());

    TH1F* h_eq  = new TH1F("h_eq" ,"",100,0.1,1);
    TH1F* h_neq = new TH1F("h_neq","",100,0.1,1);

    h_eq->Sumw2();
    h_neq->Sumw2();

    ntuple->Project("h_eq" ,"dh_m",samesign_cut_data);
    ntuple->Project("h_neq","dh_m",diffsign_cut_data);

    // Customize plots
    set_histogram_style(h_eq , kCyan  , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(h_neq, kCyan+3, std_line_width, std_marker_style, std_marker_size);

    // Create stack
    THStack* s = new THStack("s","");
    s->Add(h_eq);
    s->Add(h_neq);
    s->Draw("NOSTACK");

    s->SetTitle(";Dihadron mass(GeV);Events");
    
    //Set TLegend
    TLegend* legend = new TLegend(0.7,0.75,0.9,0.9);
    legend->AddEntry(h_eq ,"Equally charged hadrons");
    legend->AddEntry(h_neq,"Opposite charged hadrons");

    legend->Draw();

    gPad->SetLogy(1);
}