#include <iostream>
#include "../include/analysis-constants.h"
#include "../include/directories.h"
#include "../include/names.h"
#include "../include/utils-algorithms.h"
#include "../include/utils-visual.h"

void macro_print_rc_z_allmc()
{
    // Open the file with the ntuples
    TFile* fdecay = new TFile((output_folder+namef_ntuple_decays).c_str());

    // Get the dihadron and decay ntuples
    TNtuple* ntuple_decay = (TNtuple*) fdecay->Get((name_ntuple_decays).c_str());
    
    // Create parton as mothers plots
    TH1F* hparton_diffsign = new TH1F("hparton_diffsign","",Nbin_z,z_limits);
    TH1F* hparton_samesign = new TH1F("hparton_samesign","",Nbin_z,z_limits);
    TH1F* hparton_sum      = new TH1F("hparton_sum"     ,"",Nbin_z,z_limits);
    TH1F* hparton_sub      = new TH1F("hparton_sub"     ,"",Nbin_z,z_limits);
    TH1F* hrc_parton       = new TH1F("hrc_parton"      ,"",Nbin_z,z_limits);

    // Create parton as mothers plots
    TH1F* hu_diffsign = new TH1F("hu_diffsign","",Nbin_z,z_limits);
    TH1F* hu_samesign = new TH1F("hu_samesign","",Nbin_z,z_limits);
    TH1F* hu_sum      = new TH1F("hu_sum"     ,"",Nbin_z,z_limits);
    TH1F* hu_sub      = new TH1F("hu_sub"     ,"",Nbin_z,z_limits);
    TH1F* hrc_u       = new TH1F("hrc_u"      ,"",Nbin_z,z_limits);

    // Create parton as mothers plots
    TH1F* hd_diffsign = new TH1F("hd_diffsign","",Nbin_z,z_limits);
    TH1F* hd_samesign = new TH1F("hd_samesign","",Nbin_z,z_limits);
    TH1F* hd_sum      = new TH1F("hd_sum"     ,"",Nbin_z,z_limits);
    TH1F* hd_sub      = new TH1F("hd_sub"     ,"",Nbin_z,z_limits);
    TH1F* hrc_d       = new TH1F("hrc_d"      ,"",Nbin_z,z_limits);

    // Create dsame partons as mothers plots
    TH1F* heqparton_diffsign = new TH1F("heqparton_diffsign","",Nbin_z,z_limits);
    TH1F* heqparton_samesign = new TH1F("heqparton_samesign","",Nbin_z,z_limits);
    TH1F* heqparton_sum      = new TH1F("heqparton_sum"     ,"",Nbin_z,z_limits);
    TH1F* heqparton_sub      = new TH1F("heqparton_sub"     ,"",Nbin_z,z_limits);
    TH1F* hrc_eqparton       = new TH1F("hrc_eqparton"      ,"",Nbin_z,z_limits);

    // Create decay plots
    TH1F* hdecay_samesign  = new TH1F("hdecay_samesign" ,"",Nbin_z,z_limits);
    TH1F* hdecay_diffsign  = new TH1F("hdecay_diffsign" ,"",Nbin_z,z_limits);
    TH1F* hdecay_sum       = new TH1F("hdecay_sum"      ,"",Nbin_z,z_limits);
    TH1F* hdecay_sub       = new TH1F("hdecay_sub"      ,"",Nbin_z,z_limits);
    TH1F* hrc_decay        = new TH1F("hrc_decay"       ,"",Nbin_z,z_limits);

    // Get the string breaking fraction NOTE: Most event with parton mothers have the same mother tey are not complementary
    TCut parton_motherid_cut   = "(lh_motherid==21||(lh_motherid<10&&lh_motherid>-10))&&(nlh_motherid==21||(nlh_motherid<10&&nlh_motherid>-10))";
    TCut eqparton_motherid_cut = "(lh_motherid==nlh_motherid)&&(lh_motherid==21||(lh_motherid<10&&lh_motherid>-10))&&(nlh_motherid==21||(nlh_motherid<10&&nlh_motherid>-10))";
    TCut u_motherid_cut        = "(lh_motherid==2&&nlh_motherid==1)||(lh_motherid==2&&nlh_motherid==1)";
    TCut d_motherid_cut        = "(lh_motherid==1&&nlh_motherid==2)||(lh_motherid==1&&nlh_motherid==2)";
    TCut decay_motherid_cut    = "(lh_motherid>99||lh_motherid<-99)&&(nlh_motherid>99||nlh_motherid<-99)";

    ntuple_decay->Project("hdecay_diffsign"    ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==0"+decay_motherid_cut);
    ntuple_decay->Project("hparton_diffsign"   ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==0"+parton_motherid_cut);
    ntuple_decay->Project("heqparton_diffsign" ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==0"+eqparton_motherid_cut);
    ntuple_decay->Project("hu_diffsign"        ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==0"+u_motherid_cut);
    ntuple_decay->Project("hd_diffsign"        ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==0"+d_motherid_cut);
    ntuple_decay->Project("hdecay_samesign"    ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==1"+decay_motherid_cut);
    ntuple_decay->Project("hparton_samesign"   ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==1"+parton_motherid_cut);
    ntuple_decay->Project("heqparton_samesign" ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==1"+eqparton_motherid_cut);
    ntuple_decay->Project("hu_samesign"        ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==1"+u_motherid_cut);
    ntuple_decay->Project("hd_samesign"        ,"nlh_z",jet_cuts+trackmc_cuts+"eq_charge==1"+d_motherid_cut);

    hparton_sub->Add(hparton_samesign, hparton_diffsign,1,-1);
    hparton_sum->Add(hparton_diffsign, hparton_samesign,1,1);
    hrc_parton->Divide(hparton_sub,hparton_sum,1,1,"B");
    
    heqparton_sub->Add(heqparton_samesign, heqparton_diffsign,1,-1);
    heqparton_sum->Add(heqparton_diffsign, heqparton_samesign,1,1);
    hrc_eqparton->Divide(heqparton_sub,heqparton_sum,1,1,"B");
    
    hdecay_sub->Add(hdecay_samesign, hdecay_diffsign,1,-1);
    hdecay_sum->Add(hdecay_diffsign, hdecay_samesign,1,1);
    hrc_decay->Divide(hdecay_sub,hdecay_sum,1,1,"B");

    hu_sub->Add(hu_samesign, hu_diffsign,1,-1);
    hu_sum->Add(hu_diffsign, hu_samesign,1,1);
    hrc_u->Divide(hu_sub,hu_sum,1,1,"B");

    hd_sub->Add(hd_samesign, hd_diffsign,1,-1);
    hd_sum->Add(hd_diffsign, hd_samesign,1,1);
    hrc_d->Divide(hd_sub,hd_sum,1,1,"B");

    // Add some color and draw the histograms
    set_histogram_style(hrc_parton   , kCyan+3, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(hrc_eqparton , kViolet-3 , std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(hrc_decay    , kCyan-3, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(hrc_u        , kRed, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(hrc_d        , kBlue, std_line_width, std_marker_style, std_marker_size);
    
    THStack* hs = new THStack("","");
    //hs->Add(hrc_parton);
    //hs->Add(hrc_eqparton);
    //hs->Add(hrc_decay);
    hs->Add(hrc_u);
    hs->Add(hrc_d);
    
    hs->Draw("NOSTACK");

    hs->SetTitle(";z;r_{c}");

    //hs->SetMaximum(-0.001);
    //hs->SetMinimum(-0.900);
    hs->SetMaximum(1);
    hs->SetMinimum(-1);
    

    TLegend* l = new TLegend();
    l->AddEntry(hrc_parton   ,"From q/g mothers","lp");
    l->AddEntry(hrc_eqparton ,"From same q/g mothers","lp");
    l->AddEntry(hrc_decay    ,"From decay","lp");
    l->AddEntry(hrc_u        ,"From u ubar","lp");
    l->AddEntry(hrc_d        ,"From d dbar","lp");

    l->Draw("SAME");
}