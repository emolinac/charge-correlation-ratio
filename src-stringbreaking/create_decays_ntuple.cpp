#include <iostream>
#include "analysis-constants.h"
#include "names.h"
#include "utils.h"
#include "TLorentzVector.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TROOT.h"
#include "TZJets.h"
#include "TZJets.C"

int main()
{
    // Declare the output TFile
    TFile* fout = new TFile((output_folder+namef_ntuple_decays).c_str(),"RECREATE");
    gROOT->cd();

    // Declare the TNtuples
    TNtuple* ntuple_decays = new TNtuple(name_ntuple_decays.c_str(),"",ntuple_decays_vars);
    
    // Declare the TTrees to be used to build the ntuples
    TZJets* mcrecotree   = new TZJets();
    
    // Fill the mcreco TNtuple
    for(int evt = 0 ; evt < mcrecotree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        mcrecotree->GetEntry(evt);

        // Check if there is desired dihadron
        if(!dh_comp_exist_decays(mcrecotree, pid_ha, pid_hb)) continue; //OK

        // Determine location leading hadron
        int h1_location  = 0;
        double h1_energy = 0;
        loc_lh_decays(mcrecotree, pid_ha, pid_hb, h1_location, h1_energy); //OK

        // Check of leading hadron
        if(h1_location == -999) continue;

        // Determine location of next-to-leading hadron
        int h2_location  = 0;
        double h2_energy = 0;
        loc_nlh_decays(mcrecotree, pid_ha, pid_hb, h1_location, h1_energy, h2_location, h2_energy); //OK

        // Check of next to leading hadron
        if(h2_location == -999) continue;

        // Get the charges!
        float h1_charge = mcrecotree->Jet_mcjet_dtrThreeCharge[h1_location];
        float h2_charge = mcrecotree->Jet_mcjet_dtrThreeCharge[h2_location];
        float eq_charge = (h1_charge*h2_charge<0) ? 0 : 1;

        // Define array carrying the variables
        float vars[Nvars_decays];
        vars[0]  = eq_charge;
        vars[1]  = mcrecotree->Jet_mcjet_dtrID[h1_location];
        vars[2]  = mcrecotree->Jet_mcjet_dtrID[h2_location];
        vars[3]  = mcrecotree->Jet_mcjet_MotherID[h1_location];
        vars[4]  = mcrecotree->Jet_mcjet_MotherID[h2_location];
        vars[5]  = mcrecotree->Jet_mcjet_TopMotherID[h1_location];
        vars[6]  = mcrecotree->Jet_mcjet_TopMotherID[h2_location];
        vars[7]  = mcrecotree->Jet_mcjet_dtrP[h1_location]/1000.;
        vars[8]  = mcrecotree->Jet_mcjet_dtrP[h2_location]/1000.;
        vars[9]  = mcrecotree->Jet_mcjet_dtrPT[h1_location]/1000.;
        vars[10] = mcrecotree->Jet_mcjet_dtrPT[h2_location]/1000.;
        vars[11] = mcrecotree->Jet_mcjet_dtrZ[h1_location];
        vars[12] = mcrecotree->Jet_mcjet_dtrZ[h2_location];
        double h1minh2_px = mcrecotree->Jet_Dtr_PX[h1_location] - mcrecotree->Jet_Dtr_PX[h2_location];
        double h1minh2_py = mcrecotree->Jet_Dtr_PY[h1_location] - mcrecotree->Jet_Dtr_PY[h2_location];
        double h1minh2_pz = mcrecotree->Jet_Dtr_PZ[h1_location] - mcrecotree->Jet_Dtr_PZ[h2_location];
        double h1minh2_pe = mcrecotree->Jet_Dtr_E[h1_location]  - mcrecotree->Jet_Dtr_E[h2_location];
        TLorentzVector dihadronreco_relative_4vector(h1minh2_px/1000., h1minh2_py/1000., h1minh2_pz/1000., h1minh2_pe/1000.);
        vars[13] = dihadronreco_relative_4vector.Pt();
        vars[14] = mcrecotree->Jet_mcjet_dtrPZ[h1_location]/1000.;
        vars[15] = mcrecotree->Jet_mcjet_dtrPZ[h2_location]/1000.;
        vars[16] = mcrecotree->Jet_mcjet_PT/1000.;
        vars[17] = mcrecotree->Jet_mcjet_ETA;
        vars[18] = mcrecotree->Jet_mcjet_PHI;

        // Fill the TNtuple
        ntuple_decays->Fill(vars);
    }

    std::cout<<"Decays TNtuple done!"<<std::endl; //OK

    // Write the TNtuple in the output file
    fout->cd();
    ntuple_decays->Write();
    fout->Close();

    return 0;
}