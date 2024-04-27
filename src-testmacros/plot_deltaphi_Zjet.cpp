#include <iostream>
#include "../include/TZJetsData.h"
#include "../include/TZJetsData.C"

void plot_deltaphi_Zjet()
{
    // Declare the TTrees to be used to build the ntuples
    TZJetsData* datatree = new TZJetsData();
    
    // Declare 1d histo
    TH1F* h = new TH1F("","",150,-2*TMath::Pi(),2*TMath::Pi());
    
    // Fille the data TNtuple
    for(int evt = 0 ; evt < datatree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        datatree->GetEntry(evt);

        // Get the Z boson phi
        double Z0_px = datatree->Z0_PX;
        double Z0_py = datatree->Z0_PY;
        double Z0_pz = datatree->Z0_PZ;
        TVector3 Zvector(Z0_px,Z0_py,Z0_pz);

        double delta_phi = Zvector.Phi() - datatree->Jet_Phi;

        if(TMath::Abs(delta_phi) < TMath::Pi()*7./8.) continue;

        h->Fill(delta_phi);
    }

    h->Draw();
    h->SetTitle(";#Delta#phi (Z-Jet);");
}