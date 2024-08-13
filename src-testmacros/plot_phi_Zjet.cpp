#include <iostream>
#include "../include/THFJetsData.h"
#include "../include/THFJetsData.C"

void plot_phi_Zjet()
{
    // Declare the TTrees to be used to build the ntuples
    THFJetsData* datatree = new THFJetsData();
    
    // Declare 2d histogram
    // x : jet phi
    // y : Z phi
    TH2F* h = new TH2F("","",150,-TMath::Pi(),TMath::Pi(),150,-TMath::Pi(),TMath::Pi());
    
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

        h->Fill(datatree->Jet_Phi,Zvector.Phi());
    }

    h->Draw("colz");
    h->SetTitle(";Jet #phi;Z #phi");
}