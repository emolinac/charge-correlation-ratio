#include <iostream>
#include "../include/THFJetsData.h"
#include "../include/THFJetsData.C"

void plot_deltaphi_mujet()
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

        // Get the mu phi
        double Kp_px = datatree->Kp_PX;
        double Kp_py = datatree->Kp_PY;
        double Kp_pz = datatree->Kp_PZ;
        TVector3 Kpvector(Kp_px,Kp_py,Kp_pz);

        double Km_px = datatree->Km_PX;
        double Km_py = datatree->Km_PY;
        double Km_pz = datatree->Km_PZ;
        TVector3 Kmvector(Km_px,Km_py,Km_pz);


        double delta_phi_Kp = Kpvector.Phi() - datatree->Jet_Phi;
        double delta_phi_Km = Kmvector.Phi() - datatree->Jet_Phi;

        if(TMath::Abs(delta_phi_Kp) < 0.4) continue;
        if(TMath::Abs(delta_phi_Km) < 0.4) continue;

        h->Fill(delta_phi_Kp);
        h->Fill(delta_phi_Km);
    }

    h->Draw();
    h->SetTitle(";#Delta#phi (#mu-Jet);");
}