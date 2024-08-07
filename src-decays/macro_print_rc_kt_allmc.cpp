#include <iostream>
#include "../include/analysis-constants.h"
#include "../include/directories.h"
#include "../include/names.h"
#include "../include/utils-algorithms.h"
#include "../include/utils-visual.h"

void macro_print_rc_kt_allmc()
{
    // Open the file with the ntuples
    TFile* fdecay = new TFile((output_folder+namef_ntuple_decays).c_str());

    // Get the dihadron and decay ntuples
    TNtuple* ntuple_decay = (TNtuple*) fdecay->Get((name_ntuple_decays).c_str());
    
    

    // Create parton as mothers plots
    TH1F* hparton_diffsign = new TH1F("hparton_diffsign","",Nbin_kt,kt_limits);
    TH1F* hparton_samesign = new TH1F("hparton_samesign","",Nbin_kt,kt_limits);
    TH1F* hparton_sum      = new TH1F("hparton_sum"     ,"",Nbin_kt,kt_limits);
    TH1F* hparton_sub      = new TH1F("hparton_sub"     ,"",Nbin_kt,kt_limits);
    TH1F* hrc_parton       = new TH1F("hrc_parton"      ,"",Nbin_kt,kt_limits);

    // Create dsame partons as mothers plots
    TH1F* heqparton_diffsign = new TH1F("heqparton_diffsign","",Nbin_kt,kt_limits);
    TH1F* heqparton_samesign = new TH1F("heqparton_samesign","",Nbin_kt,kt_limits);
    TH1F* heqparton_sum      = new TH1F("heqparton_sum"     ,"",Nbin_kt,kt_limits);
    TH1F* heqparton_sub      = new TH1F("heqparton_sub"     ,"",Nbin_kt,kt_limits);
    TH1F* hrc_eqparton       = new TH1F("hrc_eqparton"      ,"",Nbin_kt,kt_limits);

    // Create decay plots
    TH1F* hdecay_samesign  = new TH1F("hdecay_samesign" ,"",Nbin_kt,kt_limits);
    TH1F* hdecay_diffsign  = new TH1F("hdecay_diffsign" ,"",Nbin_kt,kt_limits);
    TH1F* hdecay_sum       = new TH1F("hdecay_sum"      ,"",Nbin_kt,kt_limits);
    TH1F* hdecay_sub       = new TH1F("hdecay_sub"      ,"",Nbin_kt,kt_limits);
    TH1F* hrc_decay        = new TH1F("hrc_decay"       ,"",Nbin_kt,kt_limits);

    // Get the string breaking fraction
    TCut parton_motherid_cut   = "(lh_motherid==21||(lh_motherid<10&&lh_motherid>-10))&&(nlh_motherid==21||(nlh_motherid<10&&nlh_motherid>-10))";
    TCut eqparton_motherid_cut = "(lh_motherid==nlh_motherid)&&(lh_motherid==21||(lh_motherid<10&&lh_motherid>-10))&&(nlh_motherid==21||(nlh_motherid<10&&nlh_motherid>-10))";
    TCut decay_motherid_cut    = "(lh_motherid>99||lh_motherid<-99)&&(nlh_motherid>99||nlh_motherid<-99)";

    ntuple_decay->Project("hdecay_diffsign"    ,"dh_kt",jet_cuts+trackmc_cuts+"eq_charge==0"+decay_motherid_cut);
    ntuple_decay->Project("hparton_diffsign"   ,"dh_kt",jet_cuts+trackmc_cuts+"eq_charge==0"+parton_motherid_cut);
    ntuple_decay->Project("heqparton_diffsign" ,"dh_kt",jet_cuts+trackmc_cuts+"eq_charge==0"+eqparton_motherid_cut);
    ntuple_decay->Project("hdecay_samesign"    ,"dh_kt",jet_cuts+trackmc_cuts+"eq_charge==1"+decay_motherid_cut);
    ntuple_decay->Project("hparton_samesign"   ,"dh_kt",jet_cuts+trackmc_cuts+"eq_charge==1"+parton_motherid_cut);
    ntuple_decay->Project("heqparton_samesign" ,"dh_kt",jet_cuts+trackmc_cuts+"eq_charge==1"+eqparton_motherid_cut);

    hparton_sub->Add(hparton_samesign, hparton_diffsign,1,-1);
    hparton_sum->Add(hparton_diffsign, hparton_samesign,1,1);
    hrc_parton->Divide(hparton_sub,hparton_sum,1,1,"B");
    
    heqparton_sub->Add(heqparton_samesign, heqparton_diffsign,1,-1);
    heqparton_sum->Add(heqparton_diffsign, heqparton_samesign,1,1);
    hrc_eqparton->Divide(heqparton_sub,heqparton_sum,1,1,"B");
    
    hdecay_sub->Add(hdecay_samesign, hdecay_diffsign,1,-1);
    hdecay_sum->Add(hdecay_diffsign, hdecay_samesign,1,1);
    hrc_decay->Divide(hdecay_sub,hdecay_sum,1,1,"B");

    // Add some color and draw the histograms
    set_histogram_style(hrc_parton   , kCyan+3, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(hrc_eqparton , kViolet-3 , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(hrc_decay    , kCyan-3, std_line_width, std_marker_style, std_marker_size);
    
    THStack* hs = new THStack("","");
    hs->Add(hrc_parton);
    hs->Add(hrc_eqparton);
    hs->Add(hrc_decay);
    
    hs->Draw("NOSTACK");

    hs->SetTitle(";Jet p_{t}(GeV);r_{c}");

    hs->SetMaximum(-0.001);
    hs->SetMinimum(-0.900);
    

    TLegend* l = new TLegend();
    l->AddEntry(hrc_parton   ,"From q/g mothers","lp");
    l->AddEntry(hrc_eqparton ,"From same q/g mothers","lp");
    l->AddEntry(hrc_decay    ,"From decay","lp");
    l->Draw("SAME");
}