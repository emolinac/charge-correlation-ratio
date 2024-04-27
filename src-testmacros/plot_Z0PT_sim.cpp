#include <iostream>
#include "../include/TZJets.h"
#include "../include/TZJets.C"

void plot_Z0PT_sim()
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

        //if(tree->Z0_TRUEID!=23) continue;

        h->Fill(tree->Z0_PT);
        htrue->Fill(tree->Z0_TRUEPT);
    }

    THStack* hs = new THStack("hs","");
    hs->Add(h);
    hs->Add(htrue);

    hs->Draw("NOSTACK");
    hs->SetTitle(Form("NoTRUE=%.1f , TRUE=%.1f;PT;",h->Integral(),htrue->Integral()));
}