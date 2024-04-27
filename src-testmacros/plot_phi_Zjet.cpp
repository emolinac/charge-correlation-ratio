#include <iostream>
#include "../include/TZJetsData.h"
#include "../include/TZJetsData.C"

void plot_phi_Zjet()
{
    // Declare the TTrees to be used to build the ntuples
    TZJetsData* datatree = new TZJetsData();
    
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
        double Z0_px = datatree->Z0_PX;
        double Z0_py = datatree->Z0_PY;
        double Z0_pz = datatree->Z0_PZ;
        TVector3 Zvector(Z0_px,Z0_py,Z0_pz);

        double delta_phi = Zvector.Phi() - datatree->Jet_Phi;

        if(TMath::Abs(delta_phi) < TMath::Pi()*7./8.) continue;

        h->Fill(datatree->Jet_Phi,Zvector.Phi());
    }

    h->Draw("colz");
    h->SetTitle(";Jet #phi;Z #phi");
}