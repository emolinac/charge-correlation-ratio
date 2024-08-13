#include <iostream>
#include "analysis-constants.h"
#include "kinematical-functions.h"
#include "directories.h"
#include "names.h"
#include "utils-algorithms.h"
#include "TLorentzVector.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TROOT.h"
#include "TMCJets.h"
#include "TMCJets.C"
#include "THFJets.h"
#include "THFJets.C"
#include "THFJetsData.h"
#include "THFJetsData.C"

int main()
{
    // Declare the output TFile
    TFile* fout = new TFile((output_folder+namef_ntuple_purity).c_str(),"RECREATE");
    gROOT->cd();

    // Declare the TNtuples
    TNtuple* ntuple_purity = new TNtuple(name_ntuple_purity.c_str(),"",ntuple_purity_vars);

    // Declare the TTrees to be used to build the ntuples
    THFJets* mcrecotree   = new THFJets();
    
    for(int evt = 0 ; evt < mcrecotree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        mcrecotree->GetEntry(evt);

        // Variables of reconstructed dihadron
        int h1_location  = 0;
        int h2_location  = 0;
        double h1_energy = 0;
        double h2_energy = 0;
        
        // Variables of matched dihadron
        int matched_h1_location  = 0;
        int matched_h2_location  = 0;
        double matched_h1_energy = 0;
        double matched_h2_energy = 0;
        
        // Check if there is desired reconstructed dihadron
        if(!dh_comp_exist_mcreco(mcrecotree, pid_ha, pid_hb)) continue; //OK
        
        // Determine locations of dihadron components
        loc_lh_mcreco(mcrecotree, pid_ha, pid_hb, h1_location, h1_energy); //OK
        if(h1_location == -999) continue;

        loc_nlh_mcreco(mcrecotree, pid_ha, pid_hb, h1_location, h1_energy, h2_location, h2_energy); //OK
        if(h2_location == -999) continue;

        // Check nature of the dihadron in the case where the two should be from different species
        if(!validate_dihadron(mcrecotree->Jet_Dtr_ID[h1_location],mcrecotree->Jet_Dtr_ID[h2_location]))
        {
            //std::cout<<"Rejected pair of "<<mcrecotree->Jet_Dtr_ID[h1_location]<<","<<mcrecotree->Jet_Dtr_ID[h2_location]<<std::endl;
            continue;
        }

//        // Check if there is a truth level dihadron in a matched jet
//        loc_lh_mcmatchedjet(mcrecotree, pid_ha, pid_hb, matched_h1_location, matched_h1_energy);
//        loc_nlh_mcmatchedjet(mcrecotree, pid_ha, pid_hb, matched_h1_location, matched_h1_energy, matched_h2_location, matched_h2_energy);
//
//        // Get the signal
//        int signal = ((matched_h1_location!=-999&&matched_h2_location!=-999)&&\
//                      (mcrecotree->Jet_Dtr_ID[h1_location]==mcrecotree->Jet_mcjet_dtrID[matched_h1_location]&&\
//                       mcrecotree->Jet_Dtr_ID[h2_location]==mcrecotree->Jet_mcjet_dtrID[matched_h2_location])) ? 1 : 0 ;

        // Check if there is a truth level matched dihadron
        loc_lh_mcmatcheddtr(mcrecotree, pid_ha, pid_hb, matched_h1_location, matched_h1_energy);
        loc_nlh_mcmatcheddtr(mcrecotree, pid_ha, pid_hb, matched_h1_location, matched_h1_energy, matched_h2_location, matched_h2_energy);

        // Now check if the matched particles are in the matched jet
        int match_counter = 0;
        for(int jet_entry = 0 ; jet_entry < mcrecotree->Jet_MatchedNDtr ; jet_entry++)
        {
            // Exit if there is no matched jet
            if(mcrecotree->Jet_MatchedNDtr==50) break;

            // Look at the energy of the particles
            if(mcrecotree->Jet_mcjet_dtrE[jet_entry]==matched_h1_energy||mcrecotree->Jet_mcjet_dtrE[jet_entry]==matched_h2_energy) match_counter++;
        }
        //if(match_counter==2)std::cout<<"There are two particle with energies "<<matched_h1_energy<<" and "<<matched_h2_energy<<std::endl; 

        // Get the signal
        int signal = ((matched_h1_location!=-999&&matched_h2_location!=-999)&&\
                      (mcrecotree->Jet_Dtr_ID[h1_location]==mcrecotree->Jet_Dtr_TRUE_ID[matched_h1_location]&&\
                       mcrecotree->Jet_Dtr_ID[h2_location]==mcrecotree->Jet_Dtr_TRUE_ID[matched_h2_location])&&\
                       h1_location==matched_h1_location&&h2_location==matched_h2_location&&\
                       match_counter==2) ? 1 : 0 ;

        // Get the charges!
        float h1_charge = mcrecotree->Jet_Dtr_ThreeCharge[h1_location];
        float h2_charge = mcrecotree->Jet_Dtr_ThreeCharge[h2_location];
        float eq_charge = (h1_charge*h2_charge<0) ? 0 : 1;

        // Get the momentum of the hadrons
        TVector3 h1_momentum(mcrecotree->Jet_Dtr_PX[h1_location], mcrecotree->Jet_Dtr_PY[h1_location], mcrecotree->Jet_Dtr_PZ[h1_location]);
        TVector3 h2_momentum(mcrecotree->Jet_Dtr_PX[h2_location], mcrecotree->Jet_Dtr_PY[h2_location], mcrecotree->Jet_Dtr_PZ[h2_location]);

        // Define array carrying the variables
        float vars[Nvars_purity];
        vars[0] = eq_charge;
        vars[1] = signal;
        vars[2] = mcrecotree->Jet_Dtr_TrackChi2[h1_location];
        vars[3] = mcrecotree->Jet_Dtr_TrackChi2[h2_location];
        vars[4] = mcrecotree->Jet_Dtr_TrackNDF[h1_location];
        vars[5] = mcrecotree->Jet_Dtr_TrackNDF[h2_location];
        vars[6] = mcrecotree->Jet_Dtr_ProbNNghost[h1_location];
        vars[7] = mcrecotree->Jet_Dtr_ProbNNghost[h2_location];
        vars[8] = mcrecotree->Jet_Dtr_P[h1_location]/1000.;
        vars[9] = mcrecotree->Jet_Dtr_P[h2_location]/1000.;
        vars[10] = mcrecotree->Jet_Dtr_PT[h1_location]/1000.;
        vars[11] = mcrecotree->Jet_Dtr_PT[h2_location]/1000.;
        vars[12] = calculate_z_lh(&h1_momentum, &h2_momentum);
        vars[13] = calculate_z_nlh(&h1_momentum, &h2_momentum);
        vars[14] = calculate_kt(&h1_momentum, &h2_momentum);
        vars[15] = mcrecotree->Jet_Dtr_PZ[h1_location]/1000.;
        vars[16] = mcrecotree->Jet_Dtr_PZ[h2_location]/1000.;
        vars[17] = mcrecotree->Jet_PT/1000.;
        vars[18] = 0;//mcrecotree->Jet_Eta;
        vars[19] = 0;//mcrecotree->Jet_Phi;

        // Z branch
        double D_px = mcrecotree->Ds_PX/1000.;
        double D_py = mcrecotree->Ds_PY/1000.;
        double D_pz = mcrecotree->Ds_PZ/1000.;
        double D_e  = mcrecotree->Ds_PE/1000.;
        TLorentzVector Dreco_4vector(D_px, D_py, D_pz, D_e);
        vars[20] = Dreco_4vector.Phi();

        // Muon branches
        double Km_px = mcrecotree->Km_PX/1000.;
        double Km_py = mcrecotree->Km_PY/1000.;
        double Km_pz = mcrecotree->Km_PZ/1000.;
        double Km_e  = mcrecotree->Km_PE/1000.;

        TLorentzVector Kmreco_4vector(Km_px, Km_py, Km_pz, Km_e);
        vars[21] = Kmreco_4vector.Phi();
        vars[22] = Kmreco_4vector.Pt();
        vars[23] = Kmreco_4vector.Eta();
        vars[24] = Km_px;
        vars[25] = Km_py;
        vars[26] = Km_pz;
        vars[27] = Km_e;
        vars[28] = mcrecotree->Km_M/1000.;
        vars[29] = mcrecotree->Km_TRACK_PCHI2;
        
        double Kp_px = mcrecotree->Kp_PX/1000.;
        double Kp_py = mcrecotree->Kp_PY/1000.;
        double Kp_pz = mcrecotree->Kp_PZ/1000.;
        double Kp_e  = mcrecotree->Kp_PE/1000.;
        TLorentzVector Kpreco_4vector(Kp_px, Kp_py, Kp_pz, Kp_e);
        vars[30] = Kpreco_4vector.Phi();
        vars[31] = Kpreco_4vector.Pt();
        vars[32] = Kpreco_4vector.Eta();
        vars[33] = Kp_px;
        vars[34] = Kp_py;
        vars[35] = Kp_pz;
        vars[36] = Kp_e;
        vars[37] = mcrecotree->Kp_M/1000.;
        vars[38] = mcrecotree->Kp_TRACK_PCHI2;
        
        // Fill the TNtuple
        ntuple_purity->Fill(vars);
    }

    std::cout<<"Purity TNtuple done!"<<std::endl; //OK

    // Write the TNtuple in the output file
    fout->cd();
    ntuple_purity->Write();
    fout->Close();

    return 0;
}