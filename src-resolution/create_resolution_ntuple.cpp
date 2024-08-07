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
#include "TZJets.h"
#include "TZJets.C"
#include "TZJetsData.h"
#include "TZJetsData.C"

int main()
{
    // Declare the output TFile
    TFile* fout = new TFile((output_folder+namef_ntuple_resolution).c_str(),"RECREATE");
    gROOT->cd();

    // Declare the TNtuples
    TNtuple* ntuple_resolution = new TNtuple(name_ntuple_resolution.c_str(),"",ntuple_resolution_vars);

    // Declare the TTrees to be used to build the ntuples
    TZJets* mcrecotree   = new TZJets();
    
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

        // Check if there is a truth level dihadron
        loc_lh_mcmatcheddtr(mcrecotree, pid_ha, pid_hb, matched_h1_location, matched_h1_energy);
        loc_nlh_mcmatcheddtr(mcrecotree, pid_ha, pid_hb, matched_h1_location, matched_h1_energy, matched_h2_location, matched_h2_energy);

        // Get the signal
        int signal = ((matched_h1_location!=-999&&matched_h2_location!=-999)&&\
                      (mcrecotree->Jet_Dtr_ID[h1_location]==mcrecotree->Jet_Dtr_TRUE_ID[matched_h1_location]&&\
                       mcrecotree->Jet_Dtr_ID[h2_location]==mcrecotree->Jet_Dtr_TRUE_ID[matched_h2_location])&&\
                      (h1_location==matched_h1_location&&h2_location==matched_h2_location)) ? 1 : 0 ;
        
        // If there is no matching dihadron skip
        if(signal==0) continue;

        // Get the charges!
        float h1_charge = mcrecotree->Jet_Dtr_ThreeCharge[h1_location];
        float h2_charge = mcrecotree->Jet_Dtr_ThreeCharge[h2_location];
        float eq_charge = (h1_charge*h2_charge<0) ? 0 : 1;

        // Get the momentum of the hadrons
        TVector3 h1_momentum(mcrecotree->Jet_Dtr_PX[h1_location], mcrecotree->Jet_Dtr_PY[h1_location], mcrecotree->Jet_Dtr_PZ[h1_location]);
        TVector3 h2_momentum(mcrecotree->Jet_Dtr_PX[h2_location], mcrecotree->Jet_Dtr_PY[h2_location], mcrecotree->Jet_Dtr_PZ[h2_location]);
        TVector3 h1true_momentum(mcrecotree->Jet_Dtr_TRUE_PX[h1_location], mcrecotree->Jet_Dtr_TRUE_PY[h1_location], mcrecotree->Jet_Dtr_TRUE_PZ[h1_location]);
        TVector3 h2true_momentum(mcrecotree->Jet_Dtr_TRUE_PX[h2_location], mcrecotree->Jet_Dtr_TRUE_PY[h2_location], mcrecotree->Jet_Dtr_TRUE_PZ[h2_location]);

        // Set 4 momentum (I know, this is bad practice)
        TLorentzVector h1_4momentum(mcrecotree->Jet_Dtr_PX[h1_location], mcrecotree->Jet_Dtr_PY[h1_location], mcrecotree->Jet_Dtr_PZ[h1_location], mcrecotree->Jet_Dtr_E[h1_location]);
        TLorentzVector h2_4momentum(mcrecotree->Jet_Dtr_PX[h2_location], mcrecotree->Jet_Dtr_PY[h2_location], mcrecotree->Jet_Dtr_PZ[h2_location], mcrecotree->Jet_Dtr_E[h2_location]);
        TLorentzVector h1true_4momentum(mcrecotree->Jet_Dtr_TRUE_PX[h1_location], mcrecotree->Jet_Dtr_TRUE_PY[h1_location], mcrecotree->Jet_Dtr_TRUE_PZ[h1_location], mcrecotree->Jet_Dtr_TRUE_E[h1_location]);
        TLorentzVector h2true_4momentum(mcrecotree->Jet_Dtr_TRUE_PX[h2_location], mcrecotree->Jet_Dtr_TRUE_PY[h2_location], mcrecotree->Jet_Dtr_TRUE_PZ[h2_location], mcrecotree->Jet_Dtr_TRUE_E[h2_location]);

        TLorentzVector dh_4momentum(mcrecotree->Jet_Dtr_PX[h1_location] + mcrecotree->Jet_Dtr_PX[h2_location],
                                    mcrecotree->Jet_Dtr_PY[h1_location] + mcrecotree->Jet_Dtr_PY[h2_location],
                                    mcrecotree->Jet_Dtr_PZ[h1_location] + mcrecotree->Jet_Dtr_PZ[h2_location],
                                    mcrecotree->Jet_Dtr_E[h1_location]  + mcrecotree->Jet_Dtr_E[h2_location]);

        TLorentzVector dhtrue_4momentum(mcrecotree->Jet_Dtr_TRUE_PX[h1_location] + mcrecotree->Jet_Dtr_TRUE_PX[h2_location],
                                        mcrecotree->Jet_Dtr_TRUE_PY[h1_location] + mcrecotree->Jet_Dtr_TRUE_PY[h2_location],
                                        mcrecotree->Jet_Dtr_TRUE_PZ[h1_location] + mcrecotree->Jet_Dtr_TRUE_PZ[h2_location],
                                        mcrecotree->Jet_Dtr_TRUE_E[h1_location]  + mcrecotree->Jet_Dtr_TRUE_E[h2_location]);
        
        
        // Define array carrying the variables
        float vars[Nvars_resolution];
        vars[0]  = eq_charge;
        vars[1]  = mcrecotree->Jet_Dtr_TrackChi2[h1_location];
        vars[2]  = mcrecotree->Jet_Dtr_TrackChi2[h2_location];
        vars[3]  = mcrecotree->Jet_Dtr_TrackNDF[h1_location];
        vars[4]  = mcrecotree->Jet_Dtr_TrackNDF[h2_location];
        vars[5]  = mcrecotree->Jet_Dtr_ProbNNghost[h1_location];
        vars[6]  = mcrecotree->Jet_Dtr_ProbNNghost[h2_location];
        vars[7]  = calculate_z_nlh(&h1_momentum, &h2_momentum);
        vars[8]  = calculate_z_nlh(&h1true_momentum, &h2true_momentum);
        vars[9]  = calculate_kt(&h1_momentum, &h2_momentum);
        vars[10] = calculate_kt(&h1true_momentum, &h2true_momentum);
        vars[11] = dh_4momentum.M()/1000.;
        vars[12] = dhtrue_4momentum.M()/1000.;
        vars[13] = h1_4momentum.M()/1000.;
        vars[14] = h1true_4momentum.M()/1000.;
        vars[15] = h2_4momentum.M()/1000.;
        vars[16] = h2true_4momentum.M()/1000.;
        vars[17] = mcrecotree->Jet_PT/1000.;
        vars[18] = mcrecotree->Jet_mcjet_PT/1000.;
        vars[19] = mcrecotree->Jet_Eta;
        vars[20] = mcrecotree->Jet_Phi;

        // Z branch
        double Z0_px = mcrecotree->Z0_PX/1000.;
        double Z0_py = mcrecotree->Z0_PY/1000.;
        double Z0_pz = mcrecotree->Z0_PZ/1000.;
        double Z0_e  = mcrecotree->Z0_PE/1000.;
        TLorentzVector Z0reco_4vector(Z0_px, Z0_py, Z0_pz, Z0_e);
        vars[21] = Z0reco_4vector.Phi();

        // Muon branches
        double mum_px = mcrecotree->mum_PX/1000.;
        double mum_py = mcrecotree->mum_PY/1000.;
        double mum_pz = mcrecotree->mum_PZ/1000.;
        double mum_e  = mcrecotree->mum_PE/1000.;

        TLorentzVector mumreco_4vector(mum_px, mum_py, mum_pz, mum_e);
        vars[22] = mumreco_4vector.Phi();
        vars[23] = mumreco_4vector.Pt();
        vars[24] = mumreco_4vector.Eta();
        vars[25] = mum_px;
        vars[26] = mum_py;
        vars[27] = mum_pz;
        vars[28] = mum_e;
        vars[29] = mcrecotree->mum_M/1000.;
        vars[30] = mcrecotree->mum_TRACK_PCHI2;
        
        double mup_px = mcrecotree->mup_PX/1000.;
        double mup_py = mcrecotree->mup_PY/1000.;
        double mup_pz = mcrecotree->mup_PZ/1000.;
        double mup_e  = mcrecotree->mup_PE/1000.;
        TLorentzVector mupreco_4vector(mup_px, mup_py, mup_pz, mup_e);
        vars[31] = mupreco_4vector.Phi();
        vars[32] = mupreco_4vector.Pt();
        vars[33] = mupreco_4vector.Eta();
        vars[34] = mup_px;
        vars[35] = mup_py;
        vars[36] = mup_pz;
        vars[37] = mup_e;
        vars[38] = mcrecotree->mup_M/1000.;
        vars[39] = mcrecotree->mup_TRACK_PCHI2;

        // lh and nlh momenta
        vars[40] = mcrecotree->Jet_Dtr_P[h1_location]/1000.;
        vars[41] = mcrecotree->Jet_Dtr_P[h2_location]/1000.;
        vars[42] = mcrecotree->Jet_Dtr_PT[h1_location]/1000.;
        vars[43] = mcrecotree->Jet_Dtr_PT[h2_location]/1000.;
        
        // Fill the TNtuple
        ntuple_resolution->Fill(vars);
    }

    std::cout<<"Resolution TNtuple done!"<<std::endl; //OK

    // Write the TNtuple in the output file
    fout->cd();
    ntuple_resolution->Write();
    fout->Close();

    return 0;
}