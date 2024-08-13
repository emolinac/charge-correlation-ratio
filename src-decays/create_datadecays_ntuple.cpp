#include <iostream>
#include "analysis-constants.h"
#include "decay-functions.h"
#include "kinematical-functions.h"
#include "directories.h"
#include "names.h"
#include "utils-algorithms.h"
#include "TLorentzVector.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TROOT.h"
#include "THFJetsData.h"
#include "THFJetsData.C"

int main()
{
    // Declare the output TFile
    TFile* fout = new TFile((output_folder+namef_ntuple_datadecays).c_str(),"RECREATE");
    gROOT->cd();

    // Declare the TNtuples
    TNtuple* ntuple_datadecays = new TNtuple(name_ntuple_datadecays.c_str(),"",ntuple_datadecays_vars);
    
    // Declare the TTrees to be used to build the ntuples
    THFJetsData* datatree = new THFJetsData();

    // Declare 4 momenta of particle combinations
    TLorentzVector h1comb_momentum;
    TLorentzVector h2comb_momentum;  
    
    // Fill the TNtuple
    for(int evt = 0 ; evt < datatree->fChain->GetEntries() ; evt++)
    {
        //std::cout<<100.*evt/datatree->fChain->GetEntries()<<"\% done"<<std::endl;
        // Access entry of tree
        datatree->GetEntry(evt);

        // Check if there is desired dihadron
        if(!dh_comp_exist_data(datatree, pid_ha, pid_hb)) continue; //OK

        // Determine location leading hadron
        int h1_location  = 0;
        double h1_energy = 0;
        loc_lh_data(datatree, pid_ha, pid_hb, h1_location, h1_energy); //OK

        // Check of leading hadron
        if(h1_location == -999) continue;

        // Determine location of next-to-leading hadron
        int h2_location  = 0;
        double h2_energy = 0;
        loc_nlh_data(datatree, pid_ha, pid_hb, h1_location, h1_energy, h2_location, h2_energy); //OK

        // Check of next to leading hadron
        if(h2_location == -999) continue;

        // Check nature of the dihadron in the case where the two should be from different species
        if(!validate_dihadron(datatree->Jet_Dtr_ID[h1_location],datatree->Jet_Dtr_ID[h2_location]))
        {
            //std::cout<<"Rejected pair of "<<datatree->Jet_Dtr_ID[h1_location]<<","<<datatree->Jet_Dtr_ID[h2_location]<<std::endl;
            continue;
        }

        // Get the charges!
        float h1_charge = datatree->Jet_Dtr_ThreeCharge[h1_location];
        float h2_charge = datatree->Jet_Dtr_ThreeCharge[h2_location];
        float eq_charge = (h1_charge*h2_charge<0) ? 0 : 1;

        // Get the momentum of the hadrons
        TVector3 h1_momentum(datatree->Jet_Dtr_PX[h1_location], datatree->Jet_Dtr_PY[h1_location], datatree->Jet_Dtr_PZ[h1_location]);
        TVector3 h2_momentum(datatree->Jet_Dtr_PX[h2_location], datatree->Jet_Dtr_PY[h2_location], datatree->Jet_Dtr_PZ[h2_location]);

        // Check number of two particles combination that have an invariant mass similar to decaying meson
        double comb2parts_exist_1 = 0;
        double comb2parts_exist_2 = 0;
        double comb3parts_exist_1 = 0;
        double comb3parts_exist_2 = 0;
        double comb4parts_exist_1 = 0;
        double comb4parts_exist_2 = 0;
        
        // Check combinatios for leading hadron
        for(int jet_entry = 0 ; jet_entry < datatree->Jet_NDtr ; jet_entry++)
        {
            if(datatree->Jet_Dtr_PX[jet_entry]==-999||datatree->Jet_Dtr_ID[jet_entry]==0||
               datatree->Jet_Dtr_ID[jet_entry]==22||datatree->Jet_Dtr_ID[jet_entry]==-22||  //exclude photons
               (datatree->Jet_Dtr_ID[jet_entry]>10&&datatree->Jet_Dtr_ID[jet_entry]<19)||   //exclude leptons
               (datatree->Jet_Dtr_ID[jet_entry]<-10&&datatree->Jet_Dtr_ID[jet_entry]>-19)|| //exclude antileptons
               jet_entry==h1_location) continue;

            h1comb_momentum.SetPxPyPzE(datatree->Jet_Dtr_PX[h1_location] + datatree->Jet_Dtr_PX[jet_entry], 
                                       datatree->Jet_Dtr_PY[h1_location] + datatree->Jet_Dtr_PY[jet_entry], 
                                       datatree->Jet_Dtr_PZ[h1_location] + datatree->Jet_Dtr_PZ[jet_entry],
                                       datatree->Jet_Dtr_E[h1_location]  + datatree->Jet_Dtr_E[jet_entry]);

            if(check_rho_decay(datatree->Jet_Dtr_ID[h1_location],datatree->Jet_Dtr_ID[jet_entry],h1comb_momentum.M()/1000.)||
               check_kaon0s_decay(datatree->Jet_Dtr_ID[h1_location],datatree->Jet_Dtr_ID[jet_entry],h1comb_momentum.M()/1000.))
               comb2parts_exist_1++;
            
            for(int jet_entry_2 = jet_entry+1 ; jet_entry_2 < datatree->Jet_NDtr ; jet_entry_2++)
            {
                if(datatree->Jet_Dtr_PX[jet_entry_2]==-999||datatree->Jet_Dtr_ID[jet_entry_2]==0||
                   datatree->Jet_Dtr_ID[jet_entry_2]==22||datatree->Jet_Dtr_ID[jet_entry_2]==-22||  //exclude photons
                   (datatree->Jet_Dtr_ID[jet_entry_2]>10&&datatree->Jet_Dtr_ID[jet_entry_2]<19)||   //exclude leptons
                   (datatree->Jet_Dtr_ID[jet_entry_2]<-10&&datatree->Jet_Dtr_ID[jet_entry_2]>-19)|| //exclude antileptons
                   jet_entry_2==h1_location||jet_entry_2==jet_entry) continue;
                
                h1comb_momentum.SetPxPyPzE(datatree->Jet_Dtr_PX[h1_location] + datatree->Jet_Dtr_PX[jet_entry] + datatree->Jet_Dtr_PX[jet_entry_2],
                                           datatree->Jet_Dtr_PY[h1_location] + datatree->Jet_Dtr_PY[jet_entry] + datatree->Jet_Dtr_PY[jet_entry_2],
                                           datatree->Jet_Dtr_PZ[h1_location] + datatree->Jet_Dtr_PZ[jet_entry] + datatree->Jet_Dtr_PZ[jet_entry_2],
                                           datatree->Jet_Dtr_E[h1_location]  + datatree->Jet_Dtr_E[jet_entry]  + datatree->Jet_Dtr_E[jet_entry_2]);

                if(check_rhopm_decay(datatree->Jet_Dtr_ID[h1_location],datatree->Jet_Dtr_ID[jet_entry],datatree->Jet_Dtr_ID[jet_entry_2],h1comb_momentum.M()/1000.)||
                   check_kaonpm_decay(datatree->Jet_Dtr_ID[h1_location],datatree->Jet_Dtr_ID[jet_entry],datatree->Jet_Dtr_ID[jet_entry_2],h1comb_momentum.M()/1000.))
                   comb3parts_exist_1++;
                
                for(int jet_entry_3 = jet_entry_2+1 ; jet_entry_3 < datatree->Jet_NDtr ; jet_entry_3++)
                {
                    if(datatree->Jet_Dtr_PX[jet_entry_3]==-999||datatree->Jet_Dtr_ID[jet_entry_3]==0||
                       datatree->Jet_Dtr_ID[jet_entry_3]==22||datatree->Jet_Dtr_ID[jet_entry_3]==-22||  //exclude photons
                       (datatree->Jet_Dtr_ID[jet_entry_3]>10&&datatree->Jet_Dtr_ID[jet_entry_3]<19)||   //exclude leptons
                       (datatree->Jet_Dtr_ID[jet_entry_3]<-10&&datatree->Jet_Dtr_ID[jet_entry_3]>-19)|| //exclude antileptons
                       jet_entry_3==h1_location||jet_entry_3==jet_entry||jet_entry_3==jet_entry_2) continue;

                    h1comb_momentum.SetPxPyPzE(datatree->Jet_Dtr_PX[h1_location] + datatree->Jet_Dtr_PX[jet_entry] + datatree->Jet_Dtr_PX[jet_entry_2] + datatree->Jet_Dtr_PX[jet_entry_3],
                                               datatree->Jet_Dtr_PY[h1_location] + datatree->Jet_Dtr_PY[jet_entry] + datatree->Jet_Dtr_PY[jet_entry_2] + datatree->Jet_Dtr_PY[jet_entry_3],
                                               datatree->Jet_Dtr_PZ[h1_location] + datatree->Jet_Dtr_PZ[jet_entry] + datatree->Jet_Dtr_PZ[jet_entry_2] + datatree->Jet_Dtr_PZ[jet_entry_3],
                                               datatree->Jet_Dtr_E[h1_location]  + datatree->Jet_Dtr_E[jet_entry]  + datatree->Jet_Dtr_E[jet_entry_2]  + datatree->Jet_Dtr_E[jet_entry_3] );

                    if(check_kaon0s_decay(datatree->Jet_Dtr_ID[h1_location],datatree->Jet_Dtr_ID[jet_entry],datatree->Jet_Dtr_ID[jet_entry_2],datatree->Jet_Dtr_ID[jet_entry_3],h1comb_momentum.M()/1000.)||
                       check_eta_decay(datatree->Jet_Dtr_ID[h1_location],datatree->Jet_Dtr_ID[jet_entry],datatree->Jet_Dtr_ID[jet_entry_2],datatree->Jet_Dtr_ID[jet_entry_3],h1comb_momentum.M()/1000.)||
                       check_omega_decay(datatree->Jet_Dtr_ID[h1_location],datatree->Jet_Dtr_ID[jet_entry],datatree->Jet_Dtr_ID[jet_entry_2],datatree->Jet_Dtr_ID[jet_entry_3],h1comb_momentum.M()/1000.))
                       comb4parts_exist_1++;                
                }
            }
        }

        // Check combinatios for subleading hadron
        for(int jet_entry = 0 ; jet_entry < datatree->Jet_NDtr ; jet_entry++)
        {
            if(datatree->Jet_Dtr_PX[jet_entry]==-999||datatree->Jet_Dtr_ID[jet_entry]==0||
               datatree->Jet_Dtr_ID[jet_entry]==22||datatree->Jet_Dtr_ID[jet_entry]==-22||  //exclude photons
               (datatree->Jet_Dtr_ID[jet_entry]>10&&datatree->Jet_Dtr_ID[jet_entry]<19)||   //exclude leptons
               (datatree->Jet_Dtr_ID[jet_entry]<-10&&datatree->Jet_Dtr_ID[jet_entry]>-19)|| //exclude antileptons
               jet_entry==h1_location||jet_entry==h2_location) continue;

            h1comb_momentum.SetPxPyPzE(datatree->Jet_Dtr_PX[h2_location] + datatree->Jet_Dtr_PX[jet_entry], 
                                       datatree->Jet_Dtr_PY[h2_location] + datatree->Jet_Dtr_PY[jet_entry], 
                                       datatree->Jet_Dtr_PZ[h2_location] + datatree->Jet_Dtr_PZ[jet_entry],
                                       datatree->Jet_Dtr_E[h2_location]  + datatree->Jet_Dtr_E[jet_entry]);

            if(check_rho_decay(datatree->Jet_Dtr_ID[h2_location],datatree->Jet_Dtr_ID[jet_entry],h1comb_momentum.M()/1000.)||
               check_kaon0s_decay(datatree->Jet_Dtr_ID[h2_location],datatree->Jet_Dtr_ID[jet_entry],h1comb_momentum.M()/1000.))
               comb2parts_exist_2++;
            
            for(int jet_entry_2 = jet_entry+1 ; jet_entry_2 < datatree->Jet_NDtr ; jet_entry_2++)
            {
                if(datatree->Jet_Dtr_PX[jet_entry_2]==-999||datatree->Jet_Dtr_ID[jet_entry_2]==0||
                   datatree->Jet_Dtr_ID[jet_entry_2]==22||datatree->Jet_Dtr_ID[jet_entry_2]==-22||  //exclude photons
                   (datatree->Jet_Dtr_ID[jet_entry_2]>10&&datatree->Jet_Dtr_ID[jet_entry_2]<19)||   //exclude leptons
                   (datatree->Jet_Dtr_ID[jet_entry_2]<-10&&datatree->Jet_Dtr_ID[jet_entry_2]>-19)|| //exclude antileptons
                   jet_entry_2==h1_location||jet_entry_2==h2_location||jet_entry_2==jet_entry) continue;

                
                h1comb_momentum.SetPxPyPzE(datatree->Jet_Dtr_PX[h2_location] + datatree->Jet_Dtr_PX[jet_entry] + datatree->Jet_Dtr_PX[jet_entry_2],
                                           datatree->Jet_Dtr_PY[h2_location] + datatree->Jet_Dtr_PY[jet_entry] + datatree->Jet_Dtr_PY[jet_entry_2],
                                           datatree->Jet_Dtr_PZ[h2_location] + datatree->Jet_Dtr_PZ[jet_entry] + datatree->Jet_Dtr_PZ[jet_entry_2],
                                           datatree->Jet_Dtr_E[h2_location]  + datatree->Jet_Dtr_E[jet_entry]  + datatree->Jet_Dtr_E[jet_entry_2]);

                if(check_rhopm_decay(datatree->Jet_Dtr_ID[h2_location],datatree->Jet_Dtr_ID[jet_entry],datatree->Jet_Dtr_ID[jet_entry_2],h1comb_momentum.M()/1000.)||
                   check_kaonpm_decay(datatree->Jet_Dtr_ID[h2_location],datatree->Jet_Dtr_ID[jet_entry],datatree->Jet_Dtr_ID[jet_entry_2],h1comb_momentum.M()/1000.))
                   comb3parts_exist_2++;
                
                for(int jet_entry_3 = jet_entry_2+1 ; jet_entry_3 < datatree->Jet_NDtr ; jet_entry_3++)
                {
                    if(datatree->Jet_Dtr_PX[jet_entry_3]==-999||datatree->Jet_Dtr_ID[jet_entry_3]==0||
                       datatree->Jet_Dtr_ID[jet_entry_3]==22||datatree->Jet_Dtr_ID[jet_entry_3]==-22||  //exclude photons
                       (datatree->Jet_Dtr_ID[jet_entry_3]>10&&datatree->Jet_Dtr_ID[jet_entry_3]<19)||   //exclude leptons
                       (datatree->Jet_Dtr_ID[jet_entry_3]<-10&&datatree->Jet_Dtr_ID[jet_entry_3]>-19)|| //exclude antileptons
                       jet_entry_3==h1_location||jet_entry_3==h2_location||jet_entry_3==jet_entry||jet_entry_3==jet_entry_2) continue;

                    h1comb_momentum.SetPxPyPzE(datatree->Jet_Dtr_PX[h2_location] + datatree->Jet_Dtr_PX[jet_entry] + datatree->Jet_Dtr_PX[jet_entry_2] + datatree->Jet_Dtr_PX[jet_entry_3],
                                               datatree->Jet_Dtr_PY[h2_location] + datatree->Jet_Dtr_PY[jet_entry] + datatree->Jet_Dtr_PY[jet_entry_2] + datatree->Jet_Dtr_PY[jet_entry_3],
                                               datatree->Jet_Dtr_PZ[h2_location] + datatree->Jet_Dtr_PZ[jet_entry] + datatree->Jet_Dtr_PZ[jet_entry_2] + datatree->Jet_Dtr_PZ[jet_entry_3],
                                               datatree->Jet_Dtr_E[h2_location]  + datatree->Jet_Dtr_E[jet_entry]  + datatree->Jet_Dtr_E[jet_entry_2]  + datatree->Jet_Dtr_E[jet_entry_3] );

                    if(check_kaon0s_decay(datatree->Jet_Dtr_ID[h2_location],datatree->Jet_Dtr_ID[jet_entry],datatree->Jet_Dtr_ID[jet_entry_2],datatree->Jet_Dtr_ID[jet_entry_3],h1comb_momentum.M()/1000.)||
                       check_eta_decay(datatree->Jet_Dtr_ID[h2_location],datatree->Jet_Dtr_ID[jet_entry],datatree->Jet_Dtr_ID[jet_entry_2],datatree->Jet_Dtr_ID[jet_entry_3],h1comb_momentum.M()/1000.)||
                       check_omega_decay(datatree->Jet_Dtr_ID[h2_location],datatree->Jet_Dtr_ID[jet_entry],datatree->Jet_Dtr_ID[jet_entry_2],datatree->Jet_Dtr_ID[jet_entry_3],h1comb_momentum.M()/1000.))
                       comb4parts_exist_2++;                
                }
            }
        }


        // Define array carrying the variables
        float vars[Nvars_datadecays];

        int signal = (comb2parts_exist_1>0||comb2parts_exist_2>0||comb3parts_exist_1>0||comb3parts_exist_2>0||comb4parts_exist_1>0||comb4parts_exist_2>0) ? 0 : 1;  
        
        vars[0]  = eq_charge;
        vars[1]  = signal;
        vars[2]  = datatree->Jet_Dtr_ID[h1_location];
        vars[3]  = datatree->Jet_Dtr_ID[h2_location];
        vars[4]  = datatree->Jet_Dtr_TrackChi2[h1_location];
        vars[5]  = datatree->Jet_Dtr_TrackChi2[h2_location];
        vars[6]  = datatree->Jet_Dtr_TrackNDF[h1_location];
        vars[7]  = datatree->Jet_Dtr_TrackNDF[h2_location];
        vars[8]  = datatree->Jet_Dtr_ProbNNghost[h1_location];
        vars[9]  = datatree->Jet_Dtr_ProbNNghost[h2_location];
        vars[10] = datatree->Jet_Dtr_P[h1_location]/1000.;
        vars[11] = datatree->Jet_Dtr_P[h2_location]/1000.;
        vars[12] = datatree->Jet_Dtr_PT[h1_location]/1000.;
        vars[13] = datatree->Jet_Dtr_PT[h2_location]/1000.;
        vars[14] = calculate_z_lh(&h1_momentum, &h2_momentum);
        vars[15] = calculate_z_nlh(&h1_momentum, &h2_momentum);
        vars[16] = calculate_kt(&h1_momentum, &h2_momentum);
        vars[17] = datatree->Jet_Dtr_PZ[h1_location]/1000.;
        vars[18] = datatree->Jet_Dtr_PZ[h2_location]/1000.;
        vars[19] = datatree->Jet_PT/1000.;
        // Create Jet 4vector to get jet eta and jet phi
        double Jet_px = datatree->Jet_PX;
        double Jet_py = datatree->Jet_PY;
        double Jet_pz = datatree->Jet_PZ;
        double Jet_pe = datatree->Jet_PE;
        TLorentzVector Jet_4vector(Jet_px, Jet_py, Jet_pz, Jet_pe);
        vars[20] = Jet_4vector.Eta();
        vars[21] = Jet_4vector.Phi();
        double D_px = datatree->D_PX/1000.;
        double D_py = datatree->D_PY/1000.;
        double D_pz = datatree->D_PZ/1000.;
        double D_e  = datatree->D_PE/1000.;
        TLorentzVector Ddata_4vector(D_px, D_py, D_pz, D_e);
        vars[22] = Ddata_4vector.Phi();
        double Km_px = datatree->Km_PX/1000.;
        double Km_py = datatree->Km_PY/1000.;
        double Km_pz = datatree->Km_PZ/1000.;
        double Km_e  = datatree->Km_PE/1000.;
        TLorentzVector Kmdata_4vector(Km_px, Km_py, Km_pz, Km_e);
        vars[23] = Kmdata_4vector.Phi();
        vars[24] = Kmdata_4vector.Pt();
        vars[25] = Kmdata_4vector.Eta();
        vars[26] = Km_px;
        vars[27] = Km_py;
        vars[28] = Km_pz;
        vars[29] = Km_e;
        vars[30] = Kmdata_4vector.M();//datatree->Km_M;
        vars[31] = datatree->Km_TRACK_PCHI2;
        double Kp_px = datatree->Kp_PX/1000.;
        double Kp_py = datatree->Kp_PY/1000.;
        double Kp_pz = datatree->Kp_PZ/1000.;
        double Kp_e  = datatree->Kp_PE/1000.;
        TLorentzVector Kpdata_4vector(Kp_px, Kp_py, Kp_pz, Kp_e);
        vars[32] = Kpdata_4vector.Phi();
        vars[33] = Kpdata_4vector.Pt();
        vars[34] = Kpdata_4vector.Eta();
        vars[35] = Kp_px;
        vars[36] = Kp_py;
        vars[37] = Kp_pz;
        vars[38] = Kp_e;
        vars[39] = Kpdata_4vector.M();//datatree->Kp_M;
        vars[40] = datatree->Kp_TRACK_PCHI2;

        // Fill the TNtuple
        ntuple_datadecays->Fill(vars);
    }

    std::cout<<"Data decays TNtuple done!"<<std::endl; //OK

    // Write the TNtuple in the output file
    fout->cd();
    ntuple_datadecays->Write();
    fout->Close();

    return 0;
}