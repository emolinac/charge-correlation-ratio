#include <iostream>
#include "../include/TZJets.h"
#include "../include/TZJets.C"

void plot_phi_ZjetSIM()
{
    // Declare the TTrees to be used to build the ntuples
    TZJets* tree = new TZJets();
    
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
        double Z0_px = tree->Z0_PX;
        double Z0_py = tree->Z0_PY;
        double Z0_pz = tree->Z0_PZ;
        TVector3 Zvector(Z0_px,Z0_py,Z0_pz);

        double delta_phi = Zvector.Phi() - tree->Jet_Phi;

        if(TMath::Abs(delta_phi) < TMath::Pi()*7./8.) continue;

        h->Fill(tree->Jet_Phi,Zvector.Phi());
    }

    h->Draw("colz");
    h->SetTitle(";Jet #phi;Z #phi");
}