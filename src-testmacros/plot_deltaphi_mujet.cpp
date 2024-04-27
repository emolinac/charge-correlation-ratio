#include <iostream>
#include "../include/TZJetsData.h"
#include "../include/TZJetsData.C"

void plot_deltaphi_mujet()
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

        // Get the mu phi
        double mup_px = datatree->mup_PX;
        double mup_py = datatree->mup_PY;
        double mup_pz = datatree->mup_PZ;
        TVector3 mupvector(mup_px,mup_py,mup_pz);

        double mum_px = datatree->mum_PX;
        double mum_py = datatree->mum_PY;
        double mum_pz = datatree->mum_PZ;
        TVector3 mumvector(mum_px,mum_py,mum_pz);


        double delta_phi_mup = mupvector.Phi() - datatree->Jet_Phi;
        double delta_phi_mum = mumvector.Phi() - datatree->Jet_Phi;

        if(TMath::Abs(delta_phi_mup) < 0.4) continue;
        if(TMath::Abs(delta_phi_mum) < 0.4) continue;

        h->Fill(delta_phi_mup);
        h->Fill(delta_phi_mum);
    }

    h->Draw();
    h->SetTitle(";#Delta#phi (#mu-Jet);");
}