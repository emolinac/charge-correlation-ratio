#include <iostream>
#include "../include/analysis-constants.h"
#include "../include/directories.h"
#include "../include/names.h"
#include "../include/utils-algorithms.h"
#include "../include/utils-visual.h"

void macro_print_rc_kt_decaystringandalg()
{
    // Open the file with the ntuples
    TFile* fin     = new TFile((output_folder+namef_ntuple_dihadron).c_str());
    TFile* fdecay = new TFile((output_folder+namef_ntuple_decays).c_str());

    // Get the dihadron and decay ntuples
    TNtuple* ntuple_decay = (TNtuple*) fdecay->Get((name_ntuple_decays).c_str());
    
    // Create decay plots
    TH1F* hstrbrk_diffsign = new TH1F("hstrbrk_diffsign","",Nbin_kt,kt_limits);
    TH1F* hstrbrk_samesign = new TH1F("hstrbrk_samesign","",Nbin_kt,kt_limits);
    TH1F* hstrbrk_sum      = new TH1F("hstrbrk_sum"     ,"",Nbin_kt,kt_limits);
    TH1F* hstrbrk_sub      = new TH1F("hstrbrk_sub"     ,"",Nbin_kt,kt_limits);

    TH1F* hstrbrkalg_diffsign = new TH1F("hstrbrkalg_diffsign","",Nbin_kt,kt_limits);
    TH1F* hstrbrkalg_samesign = new TH1F("hstrbrkalg_samesign","",Nbin_kt,kt_limits);
    TH1F* hstrbrkalg_sum      = new TH1F("hstrbrkalg_sum"     ,"",Nbin_kt,kt_limits);
    TH1F* hstrbrkalg_sub      = new TH1F("hstrbrkalg_sub"     ,"",Nbin_kt,kt_limits);

    TH1F* hdecay_samesign  = new TH1F("hdecay_samesign" ,"",Nbin_kt,kt_limits);
    TH1F* hdecay_diffsign  = new TH1F("hdecay_diffsign" ,"",Nbin_kt,kt_limits);
    TH1F* hdecay_sum       = new TH1F("hdecay_sum"      ,"",Nbin_kt,kt_limits);
    TH1F* hdecay_sub       = new TH1F("hdecay_sub"      ,"",Nbin_kt,kt_limits);
    
    TH1F* hrc_strbrk    = new TH1F("hrc_strbrk"   ,"",Nbin_kt,kt_limits);
    TH1F* hrc_strbrkalg = new TH1F("hrc_strbrkalg","",Nbin_kt,kt_limits);
    TH1F* hrc_decay     = new TH1F("hrc_decay"    ,"",Nbin_kt,kt_limits);

    // Get the string breaking fraction
    TCut lh_motherid_cut  = "(lh_motherid!=113&&lh_motherid!=213&&lh_motherid!=-213&&lh_motherid!=221&&lh_motherid!=310&&lh_motherid!=321&&lh_motherid!=-321&&lh_motherid!=223)";
    TCut nlh_motherid_cut = "(nlh_motherid!=113&&nlh_motherid!=213&&nlh_motherid!=-213&&nlh_motherid!=221&&nlh_motherid!=310&&nlh_motherid!=321&&nlh_motherid!=-321&&nlh_motherid!=223)";
    TCut nlh_z_cut        = "nlh_z<0.5&&nlh_z>0.295225";//"nlh_z<0.5&&nlh_z>0.25875";
    TCut local_jet_pt_cut = "jet_pt>20&&jet_pt<100";//"jet_pt>20&&jet_pt<44.38";

    ntuple_decay->Project("hdecay_diffsign"    ,"dh_kt",local_jet_pt_cut/*+nlh_z_cut*/+jet_cuts+trackmc_cuts+"eq_charge==0&&(lh_motherid>99||lh_motherid<-99)&&(nlh_motherid>99||nlh_motherid<-99)");
    ntuple_decay->Project("hstrbrk_diffsign"   ,"dh_kt",local_jet_pt_cut/*+nlh_z_cut*/+jet_cuts+trackmc_cuts+"eq_charge==0"+lh_motherid_cut+nlh_motherid_cut);
    ntuple_decay->Project("hstrbrkalg_diffsign","dh_kt",local_jet_pt_cut/*+nlh_z_cut*/+jet_cuts+trackmc_cuts+"eq_charge==0&&prob==1");
    ntuple_decay->Project("hdecay_samesign"    ,"dh_kt",local_jet_pt_cut/*+nlh_z_cut*/+jet_cuts+trackmc_cuts+"eq_charge==1&&(lh_motherid>99||lh_motherid<-99)&&(nlh_motherid>99||nlh_motherid<-99)");
    ntuple_decay->Project("hstrbrk_samesign"   ,"dh_kt",local_jet_pt_cut/*+nlh_z_cut*/+jet_cuts+trackmc_cuts+"eq_charge==1"+lh_motherid_cut+nlh_motherid_cut);
    ntuple_decay->Project("hstrbrkalg_samesign","dh_kt",local_jet_pt_cut/*+nlh_z_cut*/+jet_cuts+trackmc_cuts+"eq_charge==1&&prob==1");

    hstrbrk_sub->Add(hstrbrk_samesign, hstrbrk_diffsign,1,-1);
    hstrbrk_sum->Add(hstrbrk_diffsign, hstrbrk_samesign,1,1);
    hrc_strbrk->Divide(hstrbrk_sub,hstrbrk_sum,1,1,"B");
    
    hstrbrkalg_sub->Add(hstrbrkalg_samesign, hstrbrkalg_diffsign,1,-1);
    hstrbrkalg_sum->Add(hstrbrkalg_diffsign, hstrbrkalg_samesign,1,1);
    hrc_strbrkalg->Divide(hstrbrkalg_sub,hstrbrkalg_sum,1,1,"B");
    
    hdecay_sub->Add(hdecay_samesign, hdecay_diffsign,1,-1);
    hdecay_sum->Add(hdecay_diffsign, hdecay_samesign,1,1);
    hrc_decay->Divide(hdecay_sub,hdecay_sum,1,1,"B");

    // Add some color and draw the histograms
    set_histogram_style(hrc_strbrk   , kCyan+3, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(hrc_strbrkalg, kViolet-3 , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(hrc_decay    , kCyan-3, std_line_width, std_marker_style, std_marker_size);
    
    THStack* hs = new THStack("","");
    hs->Add(hrc_strbrk);
    hs->Add(hrc_strbrkalg);
    hs->Add(hrc_decay);
    
    hs->Draw("NOSTACK");

    hs->SetTitle(";k_{t}(GeV);r_{c}");

    hs->SetMaximum(-0.001);
    hs->SetMinimum(-0.900);
    

    TLegend* l = new TLegend();
    l->AddEntry(hrc_strbrk   ,"From q/g mothers","lp");
    l->AddEntry(hrc_strbrkalg,"BG treated","lp");
    l->AddEntry(hrc_decay    ,"From decay","lp");
    l->Draw("SAME");
}