#include "../include/TMCJets.h"
#include "../include/TMCJets.C"

void plot_Z_mass_MC()
{
    TMCJets* tree = new TMCJets();
    TH1F* h = new TH1F("","",100,50E3,150E3);

    for(int evt = 0 ; evt < tree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        tree->GetEntry(evt);

        // Calculate relevant stuff
        double mum_mass   = tree->MCJet_truth_mum_M;
        double mum_energy = tree->MCJet_truth_mum_PE;
        double mum_px     = tree->MCJet_truth_mum_PX;
        double mum_py     = tree->MCJet_truth_mum_PY;
        double mum_pz     = tree->MCJet_truth_mum_PZ;
        
        double mup_mass   = tree->MCJet_truth_mup_M;
        double mup_energy = tree->MCJet_truth_mup_PE;
        double mup_px     = tree->MCJet_truth_mup_PX;
        double mup_py     = tree->MCJet_truth_mup_PY;
        double mup_pz     = tree->MCJet_truth_mup_PZ;

        if(mum_mass==-999||mum_energy==-999||mum_px==-999||mum_py==-999||mum_pz==-999) continue;
        if(mup_mass==-999||mup_energy==-999||mup_px==-999||mup_py==-999||mup_pz==-999) continue;

        double Z_mass2 = pow(mum_mass,2)+pow(mup_mass,2) + 2*(mum_energy*mup_energy - mum_px*mup_px - mum_py*mup_py - mum_pz*mup_pz); 

        h->Fill(sqrt(Z_mass2));
    }

    h->Draw();
}