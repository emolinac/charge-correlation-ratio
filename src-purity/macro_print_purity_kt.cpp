#include <iostream>
#include "../include/TZJets.h"
#include "../include/TZJets.C"
#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils-visual.h"

void macro_print_purity_kt()
{
    // Declare the output TFile
    TFile* f = new TFile((output_folder+namef_ntuple_purity).c_str());
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_purity.c_str());

    // KT
    TH1F* hrecgen_diffsign = new TH1F("hrecgen_diffsign","",Nbin_kt,kt_limits);
    TH1F* hrec_diffsign    = new TH1F("hrec_diffsign"   ,"",Nbin_kt,kt_limits);
    TH1F* hpurity_diffsign = new TH1F("hpurity_diffsign","",Nbin_kt,kt_limits);
    TH1F* hrecgen_samesign = new TH1F("hrecgen_samesign","",Nbin_kt,kt_limits);
    TH1F* hrec_samesign    = new TH1F("hrec_samesign"   ,"",Nbin_kt,kt_limits);
    TH1F* hpurity_samesign = new TH1F("hpurity_samesign","",Nbin_kt,kt_limits);
    
    ntuple->Project("hrec_diffsign"   ,"dh_kt","eq_charge==0"&&topological_cuts&&jet_cuts&&track_cuts&&Zboson_cuts);
    ntuple->Project("hrecgen_diffsign","dh_kt","eq_charge==0&&signal==1"&&topological_cuts&&jet_cuts&&track_cuts&&Zboson_cuts);
    ntuple->Project("hrec_samesign"   ,"dh_kt","eq_charge==1"&&topological_cuts&&jet_cuts&&track_cuts&&Zboson_cuts);
    ntuple->Project("hrecgen_samesign","dh_kt","eq_charge==1&&signal==1"&&topological_cuts&&jet_cuts&&track_cuts&&Zboson_cuts);

    hpurity_diffsign->Divide(hrecgen_diffsign,hrec_diffsign,1,1,"B");
    hpurity_samesign->Divide(hrecgen_samesign,hrec_samesign,1,1,"B");

    set_histogram_style(hpurity_diffsign, kViolet-5, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(hpurity_samesign, kViolet+2, std_line_width, std_marker_style, std_marker_size);
    
    THStack* h = new THStack("h","");
    h->Add(hpurity_diffsign);
    h->Add(hpurity_samesign);

    h->Draw("NOSTACK");

    h->SetTitle(";k_{t}(GeV);Purity");

    TLegend* l = new TLegend();
    l->AddEntry(hpurity_diffsign,"Different sign hadrons","lp");
    l->AddEntry(hpurity_samesign,"Same sign hadrons","lp");
    l->Draw("SAME");
}