#include <iostream>
#include "../include/TZJets.h"
#include "../include/TZJets.C"

void plot_Jet_PT_sim()
{
    // Declare the TTrees to be used to build the ntuples
    TZJets* tree = new TZJets();
    
    // Declare 2d histogram
    // x : jet phi
    // y : Z phi
    TH1F* h     = new TH1F("","",100,0,300E3);
    TH1F* htrue = new TH1F("","",100,0,300E3);
    htrue->SetLineColor(kRed);
    htrue->SetMarkerColor(kRed);

    h->SetLineWidth(2);
    htrue->SetLineWidth(2);


    // Fille the data TNtuple
    for(int evt = 0 ; evt < tree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        tree->GetEntry(evt);

        h->Fill(tree->Jet_PT);
        htrue->Fill(tree->Jet_mcjet_PT);
    }
    THStack* hs = new THStack("hs","");
    hs->Add(h);
    hs->Add(htrue);

    hs->Draw("NOSTACK");
    hs->SetTitle(Form("NoTRUE=%.1f , TRUE=%.1f;PT;",h->Integral(),htrue->Integral()));
}