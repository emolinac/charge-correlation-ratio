#include <iostream>
#include "../include/TZJets.h"
#include "../include/TZJets.C"
#include "../include/analysis-constants.h"
#include "../include/names.h"

void plot_purity()
{
    // Declare the output TFile
    TFile* f = new TFile((output_folder+namef_ntuple_purity).c_str());
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_purity.c_str());

    //TH1F* hrecgen = new TH1F("hrecgen","",Nbin_jet_pt,jet_pt_min,jet_pt_max);
    //TH1F* hrec    = new TH1F("hrec"   ,"",Nbin_jet_pt,jet_pt_min,jet_pt_max);
    //TH1F* hpurity = new TH1F("hpurity","",Nbin_jet_pt,jet_pt_min,jet_pt_max);

    TH1F* hrecgen = new TH1F("hrecgen","",8,2,4.5);
    TH1F* hrec    = new TH1F("hrec"   ,"",8,2,4.5);
    TH1F* hpurity = new TH1F("hpurity","",8,2,4.5);
    //TH1F* hrecgen = new TH1F("hrecgen","",8,-3.14,3.14);
    //TH1F* hrec    = new TH1F("hrec"   ,"",8,-3.14,3.14);
    //TH1F* hpurity = new TH1F("hpurity","",8,-3.14,3.14);

    ntuple->Project("hrec"   ,"jet_eta",topological_cuts&&jet_cuts&&track_cuts&&Zboson_cuts);
    ntuple->Project("hrecgen","jet_eta","signal==1"&&topological_cuts&&jet_cuts&&track_cuts&&Zboson_cuts);

    hpurity->Divide(hrecgen,hrec,1,1,"B");
    hpurity->Draw();
    
}