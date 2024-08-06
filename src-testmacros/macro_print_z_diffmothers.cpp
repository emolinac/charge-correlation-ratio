#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"
#include "../include/utils-visual.h"

void macro_print_z_diffmothers()
{
    auto c1 = new TCanvas("c1", "");
    
    // Open the file with the ntuples
    TFile* fin     = new TFile((output_folder+namef_ntuple_dihadron).c_str());
    TFile* fdecay = new TFile((output_folder+namef_ntuple_decays).c_str());

    // Get the dihadron and decay ntuples
    TNtuple* ntuple_decay = (TNtuple*) fdecay->Get((name_ntuple_decays).c_str());
    
    // Create decay plots
    TH1F* hstrbrk_diffsign    = new TH1F("hstrbrk_diffsign"   ,"",15,z_min,z_max);
    TH1F* hstrbrk_samesign    = new TH1F("hstrbrk_samesign"   ,"",15,z_min,z_max);
    TH1F* hstrbrkalg_diffsign = new TH1F("hstrbrkalg_diffsign","",15,z_min,z_max);
    TH1F* hstrbrkalg_samesign = new TH1F("hstrbrkalg_samesign","",15,z_min,z_max);
    TH1F* hdecay_samesign     = new TH1F("hdecay_samesign"    ,"",15,z_min,z_max);
    TH1F* hdecay_diffsign     = new TH1F("hdecay_diffsign"    ,"",15,z_min,z_max);

    hstrbrk_diffsign->Sumw2();
    hstrbrk_samesign->Sumw2();
    hstrbrkalg_diffsign->Sumw2();
    hstrbrkalg_samesign->Sumw2();
    hdecay_samesign->Sumw2();
    hdecay_diffsign->Sumw2();
    
    // Get the string breaking fraction
    TCut lh_motherid_cut  = "(lh_motherid!=113&&lh_motherid!=213&&lh_motherid!=-213&&lh_motherid!=221&&lh_motherid!=310&&lh_motherid!=321&&lh_motherid!=-321&&lh_motherid!=223)";
    TCut nlh_motherid_cut = "(nlh_motherid!=113&&nlh_motherid!=213&&nlh_motherid!=-213&&nlh_motherid!=221&&nlh_motherid!=310&&nlh_motherid!=321&&nlh_motherid!=-321&&nlh_motherid!=223)";
    TCut nlh_z_cut        = "nlh_z<0.5&&nlh_z>0.295225";//"nlh_z<0.5&&nlh_z>0.25875";
    TCut local_jet_pt_cut = "jet_pt>20&&jet_pt<100";

    ntuple_decay->Project("hdecay_diffsign"    ,"nlh_z",local_jet_pt_cut+jet_cuts+trackmc_cuts+"eq_charge==0&&(lh_motherid>99||lh_motherid<-99)&&(nlh_motherid>99||nlh_motherid<-99)");
    ntuple_decay->Project("hstrbrk_diffsign"   ,"nlh_z",local_jet_pt_cut+jet_cuts+trackmc_cuts+"eq_charge==0"+lh_motherid_cut+nlh_motherid_cut);
    ntuple_decay->Project("hstrbrkalg_diffsign","nlh_z",local_jet_pt_cut+jet_cuts+trackmc_cuts+"eq_charge==0&&prob==1");
    ntuple_decay->Project("hdecay_samesign"    ,"nlh_z",local_jet_pt_cut+jet_cuts+trackmc_cuts+"eq_charge==1&&(lh_motherid>99||lh_motherid<-99)&&(nlh_motherid>99||nlh_motherid<-99)");
    ntuple_decay->Project("hstrbrk_samesign"   ,"nlh_z",local_jet_pt_cut+jet_cuts+trackmc_cuts+"eq_charge==1"+lh_motherid_cut+nlh_motherid_cut);
    ntuple_decay->Project("hstrbrkalg_samesign","nlh_z",local_jet_pt_cut+jet_cuts+trackmc_cuts+"eq_charge==1&&prob==1");

    set_histogram_style(hstrbrk_diffsign   , kCyan+3   , std_line_width, std_marker_style ,3);
    set_histogram_style(hdecay_diffsign    , kViolet-3 , std_line_width, std_marker_style ,3);
    set_histogram_style(hstrbrkalg_diffsign, kCyan-3   , std_line_width, std_marker_style ,3);
    set_histogram_style(hstrbrk_samesign   , kCyan+3   , std_line_width, 22               ,3);
    set_histogram_style(hdecay_samesign    , kViolet-3 , std_line_width, 22               ,3);
    set_histogram_style(hstrbrkalg_samesign, kCyan-3   , std_line_width, 22               ,3);
    

    // Create stack
    THStack* s = new THStack("s","");
    s->Add(hstrbrk_diffsign   );
    s->Add(hstrbrk_samesign   );
    s->Add(hstrbrkalg_diffsign);
    s->Add(hstrbrkalg_samesign);
    s->Add(hdecay_samesign    );
    s->Add(hdecay_diffsign    );

    s->Draw("NOSTACK");

    s->SetTitle(";z;Events");
    
    //Set TLegend
    TLegend* legend = new TLegend(0.7,0.65,0.9,0.9);
    legend->AddEntry(hstrbrk_diffsign   ,"neq_charge no meson mothers");
    legend->AddEntry(hdecay_diffsign    ,"neq_charge from decay");
    legend->AddEntry(hstrbrkalg_diffsign,"neq_charge algorithm applied");
    legend->AddEntry(hstrbrk_samesign   ,"eq_charge no meson mothers");
    legend->AddEntry(hdecay_samesign    ,"eq_charge from decay");
    legend->AddEntry(hstrbrkalg_samesign,"eq_charge algorithm applied");
    

    legend->Draw();

    gPad->SetLogy(1);


}