#include <iostream>
#include "analysis-constants.h"
#include "decay-functions.h"
#include "kinematical-functions.h"
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
    
    // Declare 4 momenta of particle combinations
    TLorentzVector h1comb_momentum;
    TLorentzVector h2comb_momentum;  
    
    // Fill the mcreco TNtuple
    for(int evt = 0 ; evt < mcrecotree->fChain->GetEntries() ; evt++)
    {
        std::cout<<"Working in jet "<<evt<<std::endl;
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

        // Get the momentum of the hadrons
        TVector3 h1_momentum(mcrecotree->Jet_mcjet_dtrPX[h1_location], mcrecotree->Jet_mcjet_dtrPY[h1_location], mcrecotree->Jet_mcjet_dtrPZ[h1_location]);
        TVector3 h2_momentum(mcrecotree->Jet_mcjet_dtrPX[h2_location], mcrecotree->Jet_mcjet_dtrPY[h2_location], mcrecotree->Jet_mcjet_dtrPZ[h2_location]);

        // Check number of two particles combination that have an invariant mass similar to decaying meson
        double comb2parts_exist_1 = 0;
        double comb2parts_exist_2 = 0;
        double comb3parts_exist_1 = 0;
        double comb3parts_exist_2 = 0;
        double comb4parts_exist_1 = 0;
        double comb4parts_exist_2 = 0;
        
        // Check combinatios for leading hadron
        for(int jet_entry = 0 ; jet_entry < mcrecotree->Jet_mcjet_nmcdtrs ; jet_entry++)
        {
            // Skip particle if it is empty or leading hadron
            if(mcrecotree->Jet_mcjet_dtrPX[jet_entry]==-999||jet_entry==h1_location) continue;

            h1comb_momentum.SetPxPyPzE(mcrecotree->Jet_mcjet_dtrPX[h1_location] + mcrecotree->Jet_mcjet_dtrPX[jet_entry], 
                                       mcrecotree->Jet_mcjet_dtrPY[h1_location] + mcrecotree->Jet_mcjet_dtrPY[jet_entry], 
                                       mcrecotree->Jet_mcjet_dtrPZ[h1_location] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry],
                                       mcrecotree->Jet_mcjet_dtrE[h1_location]  + mcrecotree->Jet_mcjet_dtrE[jet_entry]);

            if(check_rho_decay(mcrecotree->Jet_mcjet_dtrID[h1_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],h1comb_momentum.M()/1000.)||
               check_kaon0s_decay(mcrecotree->Jet_mcjet_dtrID[h1_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],h1comb_momentum.M()/1000.))
               comb2parts_exist_1++;
            
            for(int jet_entry_2 = jet_entry+1 ; jet_entry_2 < mcrecotree->Jet_mcjet_nmcdtrs ; jet_entry_2++)
            {
                // Skip particle if it is empty or leading hadron or self
                if(mcrecotree->Jet_mcjet_dtrPX[jet_entry_2]==-999||jet_entry_2==h1_location||jet_entry_2==jet_entry) continue;
                
                h1comb_momentum.SetPxPyPzE(mcrecotree->Jet_mcjet_dtrPX[h1_location] + mcrecotree->Jet_mcjet_dtrPX[jet_entry] + mcrecotree->Jet_mcjet_dtrPX[jet_entry_2],
                                           mcrecotree->Jet_mcjet_dtrPY[h1_location] + mcrecotree->Jet_mcjet_dtrPY[jet_entry] + mcrecotree->Jet_mcjet_dtrPY[jet_entry_2],
                                           mcrecotree->Jet_mcjet_dtrPZ[h1_location] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry_2],
                                           mcrecotree->Jet_mcjet_dtrE[h1_location]  + mcrecotree->Jet_mcjet_dtrE[jet_entry]  + mcrecotree->Jet_mcjet_dtrE[jet_entry_2]);

                if(check_rhopm_decay(mcrecotree->Jet_mcjet_dtrID[h1_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],mcrecotree->Jet_mcjet_dtrID[jet_entry_2],h1comb_momentum.M()/1000.)||
                   check_kaonpm_decay(mcrecotree->Jet_mcjet_dtrID[h1_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],mcrecotree->Jet_mcjet_dtrID[jet_entry_2],h1comb_momentum.M()/1000.))
                   comb3parts_exist_1++;
                
                for(int jet_entry_3 = jet_entry_2+1 ; jet_entry_3 < mcrecotree->Jet_mcjet_nmcdtrs ; jet_entry_3++)
                {
                    if(mcrecotree->Jet_mcjet_dtrPX[jet_entry_2]==-999||jet_entry_3==h1_location||jet_entry_3==jet_entry||jet_entry_3==jet_entry_2) continue;

                    h1comb_momentum.SetPxPyPzE(mcrecotree->Jet_mcjet_dtrPX[h1_location] + mcrecotree->Jet_mcjet_dtrPX[jet_entry] + mcrecotree->Jet_mcjet_dtrPX[jet_entry_2] + mcrecotree->Jet_mcjet_dtrPX[jet_entry_3],
                                               mcrecotree->Jet_mcjet_dtrPY[h1_location] + mcrecotree->Jet_mcjet_dtrPY[jet_entry] + mcrecotree->Jet_mcjet_dtrPY[jet_entry_2] + mcrecotree->Jet_mcjet_dtrPY[jet_entry_3],
                                               mcrecotree->Jet_mcjet_dtrPZ[h1_location] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry_2] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry_3],
                                               mcrecotree->Jet_mcjet_dtrE[h1_location]  + mcrecotree->Jet_mcjet_dtrE[jet_entry]  + mcrecotree->Jet_mcjet_dtrE[jet_entry_2]  + mcrecotree->Jet_mcjet_dtrE[jet_entry_3] );

                    if(check_kaon0s_decay(mcrecotree->Jet_mcjet_dtrID[h1_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],mcrecotree->Jet_mcjet_dtrID[jet_entry_2],mcrecotree->Jet_mcjet_dtrID[jet_entry_3],h1comb_momentum.M()/1000.)||
                       check_eta_decay(mcrecotree->Jet_mcjet_dtrID[h1_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],mcrecotree->Jet_mcjet_dtrID[jet_entry_2],mcrecotree->Jet_mcjet_dtrID[jet_entry_3],h1comb_momentum.M()/1000.)||
                       check_omega_decay(mcrecotree->Jet_mcjet_dtrID[h1_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],mcrecotree->Jet_mcjet_dtrID[jet_entry_2],mcrecotree->Jet_mcjet_dtrID[jet_entry_3],h1comb_momentum.M()/1000.))
                       comb4parts_exist_1++;                
                }
            }
        }

        // Check combinatios for subleading hadron
        for(int jet_entry = 0 ; jet_entry < mcrecotree->Jet_mcjet_nmcdtrs ; jet_entry++)
        {
            // Skip particle if it is empty or leading hadron
            if(mcrecotree->Jet_mcjet_dtrPX[jet_entry]==-999||jet_entry==h1_location||jet_entry==h2_location) continue;

            h1comb_momentum.SetPxPyPzE(mcrecotree->Jet_mcjet_dtrPX[h2_location] + mcrecotree->Jet_mcjet_dtrPX[jet_entry], 
                                       mcrecotree->Jet_mcjet_dtrPY[h2_location] + mcrecotree->Jet_mcjet_dtrPY[jet_entry], 
                                       mcrecotree->Jet_mcjet_dtrPZ[h2_location] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry],
                                       mcrecotree->Jet_mcjet_dtrE[h2_location]  + mcrecotree->Jet_mcjet_dtrE[jet_entry]);

            if(check_rho_decay(mcrecotree->Jet_mcjet_dtrID[h2_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],h1comb_momentum.M()/1000.)||
               check_kaon0s_decay(mcrecotree->Jet_mcjet_dtrID[h2_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],h1comb_momentum.M()/1000.))
               comb2parts_exist_2++;
            
            for(int jet_entry_2 = jet_entry+1 ; jet_entry_2 < mcrecotree->Jet_mcjet_nmcdtrs ; jet_entry_2++)
            {
                // Skip particle if it is empty or leading hadron or self
                if(mcrecotree->Jet_mcjet_dtrPX[jet_entry_2]==-999||jet_entry_2==h1_location||jet_entry_2==h2_location||jet_entry_2==jet_entry) continue;
                
                h1comb_momentum.SetPxPyPzE(mcrecotree->Jet_mcjet_dtrPX[h2_location] + mcrecotree->Jet_mcjet_dtrPX[jet_entry] + mcrecotree->Jet_mcjet_dtrPX[jet_entry_2],
                                           mcrecotree->Jet_mcjet_dtrPY[h2_location] + mcrecotree->Jet_mcjet_dtrPY[jet_entry] + mcrecotree->Jet_mcjet_dtrPY[jet_entry_2],
                                           mcrecotree->Jet_mcjet_dtrPZ[h2_location] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry_2],
                                           mcrecotree->Jet_mcjet_dtrE[h2_location]  + mcrecotree->Jet_mcjet_dtrE[jet_entry]  + mcrecotree->Jet_mcjet_dtrE[jet_entry_2]);

                if(check_rhopm_decay(mcrecotree->Jet_mcjet_dtrID[h2_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],mcrecotree->Jet_mcjet_dtrID[jet_entry_2],h1comb_momentum.M()/1000.)||
                   check_kaonpm_decay(mcrecotree->Jet_mcjet_dtrID[h2_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],mcrecotree->Jet_mcjet_dtrID[jet_entry_2],h1comb_momentum.M()/1000.))
                   comb3parts_exist_2++;
                
                for(int jet_entry_3 = jet_entry_2+1 ; jet_entry_3 < mcrecotree->Jet_mcjet_nmcdtrs ; jet_entry_3++)
                {
                    if(mcrecotree->Jet_mcjet_dtrPX[jet_entry_2]==-999||jet_entry_3==h1_location||jet_entry_3==h2_location||jet_entry_3==jet_entry||jet_entry_3==jet_entry_2) continue;

                    h1comb_momentum.SetPxPyPzE(mcrecotree->Jet_mcjet_dtrPX[h2_location] + mcrecotree->Jet_mcjet_dtrPX[jet_entry] + mcrecotree->Jet_mcjet_dtrPX[jet_entry_2] + mcrecotree->Jet_mcjet_dtrPX[jet_entry_3],
                                               mcrecotree->Jet_mcjet_dtrPY[h2_location] + mcrecotree->Jet_mcjet_dtrPY[jet_entry] + mcrecotree->Jet_mcjet_dtrPY[jet_entry_2] + mcrecotree->Jet_mcjet_dtrPY[jet_entry_3],
                                               mcrecotree->Jet_mcjet_dtrPZ[h2_location] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry_2] + mcrecotree->Jet_mcjet_dtrPZ[jet_entry_3],
                                               mcrecotree->Jet_mcjet_dtrE[h2_location]  + mcrecotree->Jet_mcjet_dtrE[jet_entry]  + mcrecotree->Jet_mcjet_dtrE[jet_entry_2]  + mcrecotree->Jet_mcjet_dtrE[jet_entry_3] );

                    if(check_kaon0s_decay(mcrecotree->Jet_mcjet_dtrID[h2_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],mcrecotree->Jet_mcjet_dtrID[jet_entry_2],mcrecotree->Jet_mcjet_dtrID[jet_entry_3],h1comb_momentum.M()/1000.)||
                       check_eta_decay(mcrecotree->Jet_mcjet_dtrID[h2_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],mcrecotree->Jet_mcjet_dtrID[jet_entry_2],mcrecotree->Jet_mcjet_dtrID[jet_entry_3],h1comb_momentum.M()/1000.)||
                       check_omega_decay(mcrecotree->Jet_mcjet_dtrID[h2_location],mcrecotree->Jet_mcjet_dtrID[jet_entry],mcrecotree->Jet_mcjet_dtrID[jet_entry_2],mcrecotree->Jet_mcjet_dtrID[jet_entry_3],h1comb_momentum.M()/1000.))
                       comb4parts_exist_2++;                
                }
            }
        }

        /*
        std::cout<<"comb2parts_1="<<comb2parts_exist_1<<" ,comb2parts_2="<<comb2parts_exist_2<<std::endl;
        std::cout<<"comb3parts_1="<<comb3parts_exist_1<<" ,comb3parts_2="<<comb3parts_exist_2<<std::endl;
        std::cout<<"comb4parts_1="<<comb4parts_exist_1<<" ,comb4parts_2="<<comb4parts_exist_2<<std::endl;
        */

        int signal = (comb2parts_exist_1>0||comb2parts_exist_2>0||comb3parts_exist_1>0||comb3parts_exist_2>0||comb4parts_exist_1>0||comb4parts_exist_2>0) ? 0 : 1;  
        std::cout<<"Signal = "<<signal<<std::endl;

        // Define array carrying the variables
        float vars[Nvars_decays];
        vars[0]  = eq_charge;
        vars[1]  = signal;
        vars[2]  = mcrecotree->Jet_mcjet_dtrID[h1_location];
        vars[3]  = mcrecotree->Jet_mcjet_dtrID[h2_location];
        vars[4]  = mcrecotree->Jet_mcjet_MotherID[h1_location];
        vars[5]  = mcrecotree->Jet_mcjet_MotherID[h2_location];
        vars[6]  = mcrecotree->Jet_mcjet_TopMotherID[h1_location];
        vars[7]  = mcrecotree->Jet_mcjet_TopMotherID[h2_location];
        vars[8]  = mcrecotree->Jet_mcjet_dtrP[h1_location]/1000.;
        vars[9]  = mcrecotree->Jet_mcjet_dtrP[h2_location]/1000.;
        vars[10] = mcrecotree->Jet_mcjet_dtrPT[h1_location]/1000.;
        vars[11] = mcrecotree->Jet_mcjet_dtrPT[h2_location]/1000.;
        vars[12] = calculate_z_lh(&h1_momentum, &h2_momentum);
        vars[13] = calculate_z_nlh(&h1_momentum, &h2_momentum);
        vars[14] = calculate_kt(&h1_momentum, &h2_momentum);
        vars[15] = mcrecotree->Jet_mcjet_dtrPZ[h1_location]/1000.;
        vars[16] = mcrecotree->Jet_mcjet_dtrPZ[h2_location]/1000.;
        vars[17] = mcrecotree->Jet_mcjet_PT/1000.;
        vars[18] = mcrecotree->Jet_mcjet_ETA;
        vars[19] = mcrecotree->Jet_mcjet_PHI;

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