#include <iostream>
#include "../include/TZJets.h"
#include "../include/TZJets.C"

void plot_mum_mup_mass()
{
    TZJets* tree = new TZJets();
    TH1F* h = new TH1F("","",100,50E3,150E3);

    for(int evt = 0 ; evt < tree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        tree->GetEntry(evt);

        // Calculate relevant stuff
        double mum_mass   = tree->mum_M;
        double mum_energy = tree->mum_PE;
        double mum_px     = tree->mum_PX;
        double mum_py     = tree->mum_PY;
        double mum_pz     = tree->mum_PZ;
        
        double mup_mass   = tree->mup_M;
        double mup_energy = tree->mup_PE;
        double mup_px     = tree->mup_PX;
        double mup_py     = tree->mup_PY;
        double mup_pz     = tree->mup_PZ;

        if(mum_mass==-999||mum_energy==-999||mum_px==-999||mum_py==-999||mum_pz==-999) continue;
        if(mup_mass==-999||mup_energy==-999||mup_px==-999||mup_py==-999||mup_pz==-999) continue;

        double Z_mass2 = pow(mum_mass,2)+pow(mup_mass,2) + 2*(mum_energy*mup_energy - mum_px*mup_px - mum_py*mup_py - mum_pz*mup_pz); 

        h->Fill(sqrt(Z_mass2));
    }

    h->Draw();
}