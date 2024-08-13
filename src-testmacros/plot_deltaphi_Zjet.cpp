#include <iostream>
#include "../include/THFJetsData.h"
#include "../include/THFJetsData.C"

void plot_deltaphi_Zjet()
{
    // Declare the TTrees to be used to build the ntuples
    THFJetsData* datatree = new THFJetsData();
    
    // Declare 1d histo
    TH1F* h = new TH1F("","",150,-2*TMath::Pi(),2*TMath::Pi());
    
    // Fille the data TNtuple
    for(int evt = 0 ; evt < datatree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        datatree->GetEntry(evt);

        // Get the Z boson phi
        double D_px = datatree->D_PX;
        double D_py = datatree->D_PY;
        double D_pz = datatree->D_PZ;
        TVector3 Zvector(D_px,D_py,D_pz);

        double delta_phi = Zvector.Phi() - datatree->Jet_Phi;

        if(TMath::Abs(delta_phi) < TMath::Pi()*7./8.) continue;

        h->Fill(delta_phi);
    }

    h->Draw();
    h->SetTitle(";#Delta#phi (Z-Jet);");
}