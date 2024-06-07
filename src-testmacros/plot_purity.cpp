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

    // JET PT
    //TH1F* hrecgen_diffsign = new TH1F("hrecgen_diffsign","",Nbin_jet_pt,jet_pt_limits);
    //TH1F* hrec_diffsign    = new TH1F("hrec_diffsign"   ,"",Nbin_jet_pt,jet_pt_limits);
    //TH1F* hpurity_diffsign = new TH1F("hpurity_diffsign","",Nbin_jet_pt,jet_pt_limits);
    //TH1F* hrecgen_samesign = new TH1F("hrecgen_samesign","",Nbin_jet_pt,jet_pt_limits);
    //TH1F* hrec_samesign    = new TH1F("hrec_samesign"   ,"",Nbin_jet_pt,jet_pt_limits);
    //TH1F* hpurity_samesign = new TH1F("hpurity_samesign","",Nbin_jet_pt,jet_pt_limits);

    // ETA
    //TH1F* hrecgen_diffsign = new TH1F("hrecgen_diffsign","",8,2,4.5);
    //TH1F* hrec_diffsign    = new TH1F("hrec_diffsign"   ,"",8,2,4.5);
    //TH1F* hpurity_diffsign = new TH1F("hpurity_diffsign","",8,2,4.5);
    //TH1F* hrecgen_samesign = new TH1F("hrecgen_samesign","",8,2,4.5);
    //TH1F* hrec_samesign    = new TH1F("hrec_samesign"   ,"",8,2,4.5);
    //TH1F* hpurity_samesign = new TH1F("hpurity_samesign","",8,2,4.5);
    
    // Z
    TH1F* hrecgen_diffsign = new TH1F("hrecgen_diffsign","",Nbin_z,z_min,z_max);
    TH1F* hrec_diffsign    = new TH1F("hrec_diffsign"   ,"",Nbin_z,z_min,z_max);
    TH1F* hpurity_diffsign = new TH1F("hpurity_diffsign","",Nbin_z,z_min,z_max);
    TH1F* hrecgen_samesign = new TH1F("hrecgen_samesign","",Nbin_z,z_min,z_max);
    TH1F* hrec_samesign    = new TH1F("hrec_samesign"   ,"",Nbin_z,z_min,z_max);
    TH1F* hpurity_samesign = new TH1F("hpurity_samesign","",Nbin_z,z_min,z_max);
    
    // PHI
    //TH1F* hrecgen_diffsign = new TH1F("hrecgen_diffsign","",8,-3.14,3.14);
    //TH1F* hrec_diffsign    = new TH1F("hrec_diffsign"   ,"",8,-3.14,3.14);
    //TH1F* hpurity_diffsign = new TH1F("hpurity_diffsign","",8,-3.14,3.14);    
    //TH1F* hrecgen_samesign = new TH1F("hrecgen_samesign","",8,-3.14,3.14);
    //TH1F* hrec_samesign    = new TH1F("hrec_samesign"   ,"",8,-3.14,3.14);
    //TH1F* hpurity_samesign = new TH1F("hpurity_samesign","",8,-3.14,3.14);

    ntuple->Project("hrec_diffsign"   ,"nlh_pz/(lh_pz+nlh_pz)","eq_charge==0"&&topological_cuts&&jet_cuts&&track_cuts&&Zboson_cuts);
    ntuple->Project("hrecgen_diffsign","nlh_pz/(lh_pz+nlh_pz)","eq_charge==0&&signal==1"&&topological_cuts&&jet_cuts&&track_cuts&&Zboson_cuts);
    ntuple->Project("hrec_samesign"   ,"nlh_pz/(lh_pz+nlh_pz)","eq_charge==1"&&topological_cuts&&jet_cuts&&track_cuts&&Zboson_cuts);
    ntuple->Project("hrecgen_samesign","nlh_pz/(lh_pz+nlh_pz)","eq_charge==1&&signal==1"&&topological_cuts&&jet_cuts&&track_cuts&&Zboson_cuts);

    hpurity_diffsign->Divide(hrecgen_diffsign,hrec_diffsign,1,1,"B");
    hpurity_samesign->Divide(hrecgen_samesign,hrec_samesign,1,1,"B");
    hpurity_diffsign->SetLineColor(kBlue);
    hpurity_diffsign->SetLineWidth(2);
    hpurity_diffsign->SetMarkerColor(kBlue);
    hpurity_samesign->SetLineColor(kGreen);
    hpurity_samesign->SetLineWidth(2);
    hpurity_samesign->SetMarkerColor(kGreen);
    
    THStack* h = new THStack("h","");
    h->Add(hpurity_diffsign);
    h->Add(hpurity_samesign);

    h->Draw("NOSTACK");

    h->SetTitle(";z;Purity");

    TLegend* l = new TLegend();
    l->AddEntry(hpurity_diffsign,"Different sign hadrons","lp");
    l->AddEntry(hpurity_samesign,"Same sign hadrons","lp");
    l->Draw("SAME");
}