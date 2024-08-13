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
        double Km_mass   = tree->MCJet_truth_Km_M;
        double Km_energy = tree->MCJet_truth_Km_PE;
        double Km_px     = tree->MCJet_truth_Km_PX;
        double Km_py     = tree->MCJet_truth_Km_PY;
        double Km_pz     = tree->MCJet_truth_Km_PZ;
        
        double Kp_mass   = tree->MCJet_truth_Kp_M;
        double Kp_energy = tree->MCJet_truth_Kp_PE;
        double Kp_px     = tree->MCJet_truth_Kp_PX;
        double Kp_py     = tree->MCJet_truth_Kp_PY;
        double Kp_pz     = tree->MCJet_truth_Kp_PZ;

        if(Km_mass==-999||Km_energy==-999||Km_px==-999||Km_py==-999||Km_pz==-999) continue;
        if(Kp_mass==-999||Kp_energy==-999||Kp_px==-999||Kp_py==-999||Kp_pz==-999) continue;

        double Z_mass2 = pow(Km_mass,2)+pow(Kp_mass,2) + 2*(Km_energy*Kp_energy - Km_px*Kp_px - Km_py*Kp_py - Km_pz*Kp_pz); 

        h->Fill(sqrt(Z_mass2));
    }

    h->Draw();
}