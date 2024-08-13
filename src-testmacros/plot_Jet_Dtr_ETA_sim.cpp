#include <iostream>
#include "../include/THFJets.h"
#include "../include/THFJets.C"

void plot_Jet_Dtr_ETA_sim()
{
    // Declare the TTrees to be used to build the ntuples
    THFJets* tree = new THFJets();
    
    // Declare 2d histogram
    // x : jet phi
    // y : Z phi
    TH1F* h     = new TH1F("","",100,2,4.5);
    TH1F* htrue = new TH1F("","",100,2,4.5);
    htrue->SetLineColor(kRed);
    htrue->SetMarkerColor(kRed);

    h->SetLineWidth(2);
    htrue->SetLineWidth(2);

    // Fille the data TNtuple
    for(int evt = 0 ; evt < tree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        tree->GetEntry(evt);

        //if(tree->D_TRUEID!=23) continue;
        for(int i = 0 ; i < tree->Jet_NDtr ; i++){
        h->Fill(tree->Jet_Dtr_ETA[i]);
        htrue->Fill(tree->Jet_Dtr_TRUE_ETA[i]);}
    }

    THStack* hs = new THStack("hs","");
    hs->Add(h);
    hs->Add(htrue);

    hs->Draw("NOSTACK");
    hs->SetTitle(Form("NoTRUE=%.1f , TRUE=%.1f;PT;",h->Integral(),htrue->Integral()));
}