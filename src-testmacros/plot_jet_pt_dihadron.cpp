#include "../include/analysis-constants.h"

void plot_jet_pt_dihadron()
{
    TFile* f = new TFile("../output-files/ntuple_dihadron.root");
    TNtuple* ntuple = (TNtuple*) f->Get("ntuple_data");

    TH1F* h = new TH1F("h","",Nbin_jet_pt,jet_pt_limits);
    ntuple->Project("h","jet_pt","");

    TH1F* hcumul = (TH1F*) h->GetCumulative();

    h->Draw();
}