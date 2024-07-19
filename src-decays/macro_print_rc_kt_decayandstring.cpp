#include <iostream>
#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"
#include "../include/utils-visual.h"

void macro_print_rc_kt_decayandstring()
{
    // Open the file with the ntuples
    TFile* fin    = new TFile((output_folder+namef_ntuple_dihadron).c_str());
    TFile* fdecay = new TFile((output_folder+namef_ntuple_decays).c_str());

    // Get the dihadron and decay ntuples
    TNtuple* ntuple_decay = (TNtuple*) fdecay->Get((name_ntuple_decays).c_str());
    
    // Create decay plots
    TH1F* hstrbrk_diffsign = new TH1F("hstrbrk_diffsign","",Nbin_kt,kt_limits);
    TH1F* hstrbrk_samesign = new TH1F("hstrbrk_samesign","",Nbin_kt,kt_limits);
    TH1F* hstrbrk_sum      = new TH1F("hstrbrk_sum"     ,"",Nbin_kt,kt_limits);
    TH1F* hstrbrk_sub      = new TH1F("hstrbrk_sub"     ,"",Nbin_kt,kt_limits);

    TH1F* hdecay_samesign  = new TH1F("hdecay_samesign" ,"",Nbin_kt,kt_limits);
    TH1F* hdecay_diffsign  = new TH1F("hdecay_diffsign" ,"",Nbin_kt,kt_limits);
    TH1F* hdecay_sum       = new TH1F("hdecay_sum"      ,"",Nbin_kt,kt_limits);
    TH1F* hdecay_sub       = new TH1F("hdecay_sub"      ,"",Nbin_kt,kt_limits);
    
    TH1F* hrc_strbrk = new TH1F("hrc_strbrk","",Nbin_kt,kt_limits);
    TH1F* hrc_decay  = new TH1F("hrc_decay" ,"",Nbin_kt,kt_limits);

    // Get the string breaking fraction
    ntuple_decay->Project("hdecay_diffsign" ,"dh_kt",jet_cuts+trackmc_cuts+"eq_charge==0&&(lh_motherid>22||lh_motherid<-10)&&(nlh_motherid>22||nlh_motherid<-10)");
    ntuple_decay->Project("hstrbrk_diffsign","dh_kt",jet_cuts+trackmc_cuts+"eq_charge==0&&lh_motherid<22&&lh_motherid>-10&&nlh_motherid<22&&nlh_motherid>-10");
    ntuple_decay->Project("hdecay_samesign" ,"dh_kt",jet_cuts+trackmc_cuts+"eq_charge==1&&(lh_motherid>22||lh_motherid<-10)&&(nlh_motherid>22||nlh_motherid<-10)");
    ntuple_decay->Project("hstrbrk_samesign","dh_kt",jet_cuts+trackmc_cuts+"eq_charge==1&&lh_motherid<22&&lh_motherid>-10&&nlh_motherid<22&&nlh_motherid>-10");
    
    hstrbrk_sub->Add(hstrbrk_samesign, hstrbrk_diffsign,1,-1);
    hstrbrk_sum->Add(hstrbrk_diffsign, hstrbrk_samesign,1,1);
    hrc_strbrk->Divide(hstrbrk_sub,hstrbrk_sum,1,1,"B");
    
    hdecay_sub->Add(hdecay_samesign, hdecay_diffsign,1,-1);
    hdecay_sum->Add(hdecay_diffsign, hdecay_samesign,1,1);
    hrc_decay->Divide(hdecay_sub,hdecay_sum,1,1,"B");

    // Add some color and draw the histograms
    set_histogram_style(hrc_strbrk, kCyan+3, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(hrc_decay,  kCyan-3, std_line_width, std_marker_style, std_marker_size);
    
    THStack* hs = new THStack("","");
    hs->Add(hrc_strbrk);
    hs->Add(hrc_decay);
    
    hs->Draw("NOSTACK");

    hs->SetTitle(";k_{t}(GeV);r_{c}");

    hs->SetMaximum(-0.001);
    hs->SetMinimum(-0.900);
    

    TLegend* l = new TLegend();
    l->AddEntry(hrc_strbrk,"From str brk","lp");
    l->AddEntry(hrc_decay,"From decay","lp");
    l->Draw("SAME");
}