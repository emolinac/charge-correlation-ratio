#include <iostream>
#include "../include/TZJets.h"
#include "../include/TZJets.C"
#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils-visual.h"

void macro_print_effmuon_z()
{
    // Declare the output TFile
    TFile* f = new TFile((output_folder+namef_ntuple_effmuons).c_str());
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_muons.c_str());

    // Z
    TH1F* htag_diffsign   = new TH1F("htag_diffsign"  ,"",Nbin_z,z_limits);
    TH1F* hprobe_diffsign = new TH1F("hprobe_diffsign","",Nbin_z,z_limits);
    TH1F* heff_diffsign   = new TH1F("heff_diffsign"  ,"",Nbin_z,z_limits);
    TH1F* htag_samesign   = new TH1F("htag_samesign"  ,"",Nbin_z,z_limits);
    TH1F* hprobe_samesign = new TH1F("hprobe_samesign","",Nbin_z,z_limits);
    TH1F* heff_samesign   = new TH1F("heff_samesign"  ,"",Nbin_z,z_limits);
    
    ntuple->Project("hprobe_diffsign","nlh_z","eq_charge==0&&mum_probchi2>0.1&&mup_probchi2>0.1");
    ntuple->Project("htag_diffsign"  ,"nlh_z","eq_charge==0&&mum_probchi2>0.1&&mup_probchi2>0.1&&mum_ipchi2<1&&mum_probnnmuon>0.68&&mup_ipchi2<1&&mup_probnnmuon>0.68");
    ntuple->Project("hprobe_samesign","nlh_z","eq_charge==1&&mum_probchi2>0.1&&mup_probchi2>0.1");
    ntuple->Project("htag_samesign"  ,"nlh_z","eq_charge==1&&mum_probchi2>0.1&&mup_probchi2>0.1&&mum_ipchi2<1&&mum_probnnmuon>0.68&&mup_ipchi2<1&&mup_probnnmuon>0.68");

    heff_diffsign->Divide(htag_diffsign,hprobe_diffsign,1,1,"B");
    heff_samesign->Divide(htag_samesign,hprobe_samesign,1,1,"B");

    set_histogram_style(heff_diffsign, kViolet-5, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(heff_samesign, kViolet+2, std_line_width, std_marker_style, std_marker_size);
    
    THStack* h = new THStack("h","");
    h->Add(heff_diffsign);
    h->Add(heff_samesign);

    h->Draw("NOSTACK");

    h->SetTitle(";z;Efficiency");
    
    TLegend* l = new TLegend();
    l->AddEntry(heff_diffsign,"Different sign hadrons","lp");
    l->AddEntry(heff_samesign,"Same sign hadrons","lp");
    l->Draw("SAME");
}