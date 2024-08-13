#include <iostream>
#include "../include/THFJets.h"
#include "../include/THFJets.C"

void plot_phi_ZjetSIM()
{
    // Declare the TTrees to be used to build the ntuples
    THFJets* tree = new THFJets();
    
    // Declare 2d histogram
    // x : jet phi
    // y : Z phi
    TH2F* h = new TH2F("","",150,-TMath::Pi(),TMath::Pi(),150,-TMath::Pi(),TMath::Pi());
    
    // Fille the data TNtuple
    for(int evt = 0 ; evt < tree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        tree->GetEntry(evt);

        // Get the Z boson phi
        double D_px = tree->D_PX;
        double D_py = tree->D_PY;
        double D_pz = tree->D_PZ;
        TVector3 Zvector(D_px,D_py,D_pz);

        double delta_phi = Zvector.Phi() - tree->Jet_Phi;

        if(TMath::Abs(delta_phi) < TMath::Pi()*7./8.) continue;

        h->Fill(tree->Jet_Phi,Zvector.Phi());
    }

    h->Draw("colz");
    h->SetTitle(";Jet #phi;Z #phi");
}