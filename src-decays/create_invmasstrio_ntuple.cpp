#include <iostream>
#include "analysis-constants.h"
#include "kinematical-functions.h"
#include "names.h"
#include "utils.h"
#include "TLorentzVector.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TROOT.h"
#include "TZJetsData.h"
#include "TZJetsData.C"

int main()
{
    // Declare the output TFile
    TFile* fout = new TFile((output_folder+namef_ntuple_invmasstrio).c_str(),"RECREATE");
    gROOT->cd();

    // Declare the TNtuples
    TNtuple* ntuple_invmass = new TNtuple(name_ntuple_invmasstrio.c_str(),"",ntuple_invmasstrio_vars);
    
    // Declare the TTrees to be used to build the ntuples
    TZJetsData* datatree = new TZJetsData();

    // Fill the mcreco TNtuple
    int entries = datatree->fChain->GetEntries();

    // Define Lorentz Vector to use
    TLorentzVector* h1comb_momentum = new TLorentzVector();
    TLorentzVector* h2comb_momentum = new TLorentzVector();
    TLorentzVector* Jet_4vector     = new TLorentzVector();
    TLorentzVector* Z0data_4vector  = new TLorentzVector();
    TLorentzVector* mumdata_4vector = new TLorentzVector();
    TLorentzVector* mupdata_4vector = new TLorentzVector();

    for(int evt = 0 ; evt < datatree->fChain->GetEntries() ; evt++)
    {
        std::cout<<evt*100./entries<<" \% completed."<<std::endl;

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

        // Get the charges!
        float h1_charge = datatree->Jet_Dtr_ThreeCharge[h1_location];
        float h2_charge = datatree->Jet_Dtr_ThreeCharge[h2_location];
        float eq_charge = (h1_charge*h2_charge<0) ? 0 : 1;

        // Get the momentum of the hadrons
        TVector3 h1_momentum(datatree->Jet_Dtr_PX[h1_location], datatree->Jet_Dtr_PY[h1_location], datatree->Jet_Dtr_PZ[h1_location]);
        TVector3 h2_momentum(datatree->Jet_Dtr_PX[h2_location], datatree->Jet_Dtr_PY[h2_location], datatree->Jet_Dtr_PZ[h2_location]);

        // Define array carrying the variables
        float vars[Nvars_invmasstrio];

//        // Check existence of combination with a meson mass
//        int comb1_exist = 0;
//        for(int jet_entry = 0 ; jet_entry < datatree->Jet_NDtr ; jet_entry++)
//        {
//            for(int jet_entry_2 = jet_entry+1 ; jet_entry_2 < datatree->Jet_NDtr ; jet_entry_2++)
//            {
//                // Always skip a combination with two or more leading hadrons
//                if(datatree->Jet_Dtr_PX[jet_entry]==-999||jet_entry==h1_location||jet_entry_2==h1_location) continue;
//
//                h1comb_momentum->SetPxPyPzE(datatree->Jet_Dtr_PX[h1_location] + datatree->Jet_Dtr_PX[jet_entry] + datatree->Jet_Dtr_PX[jet_entry_2], 
//                                            datatree->Jet_Dtr_PY[h1_location] + datatree->Jet_Dtr_PY[jet_entry] + datatree->Jet_Dtr_PY[jet_entry_2], 
//                                            datatree->Jet_Dtr_PZ[h1_location] + datatree->Jet_Dtr_PZ[jet_entry] + datatree->Jet_Dtr_PZ[jet_entry_2],
//                                            datatree->Jet_Dtr_E[h1_location]  + datatree->Jet_Dtr_E[jet_entry]  + datatree->Jet_Dtr_E[jet_entry_2]);
//
//                if(h1comb_momentum->M()/1000.>0.730&&h1comb_momentum->M()/1000.<0.810&&datatree->Jet_Dtr_ID[h1_location]!=datatree->Jet_Dtr_ID[jet_entry]) 
//                {comb1_exist++; break;}
//            }
//        }

        //std::cout<<"First check complete"<<std::endl;

//        int comb2_exist = 0;
//        for(int jet_entry = 0 ; jet_entry < datatree->Jet_NDtr ; jet_entry++)
//        {
//            for(int jet_entry_2 = jet_entry+1 ; jet_entry_2 < datatree->Jet_NDtr ; jet_entry_2++)
//            {
//                if(datatree->Jet_Dtr_PX[jet_entry]==-999||jet_entry==h1_location||jet_entry==h2_location||jet_entry_2==h1_location||jet_entry_2==h2_location) continue;
//
//                h2comb_momentum->SetPxPyPzE(datatree->Jet_Dtr_PX[h2_location] + datatree->Jet_Dtr_PX[jet_entry] + datatree->Jet_Dtr_PX[jet_entry_2], 
//                                            datatree->Jet_Dtr_PY[h2_location] + datatree->Jet_Dtr_PY[jet_entry] + datatree->Jet_Dtr_PY[jet_entry_2], 
//                                            datatree->Jet_Dtr_PZ[h2_location] + datatree->Jet_Dtr_PZ[jet_entry] + datatree->Jet_Dtr_PZ[jet_entry_2],
//                                            datatree->Jet_Dtr_E[h2_location]  + datatree->Jet_Dtr_E[jet_entry]  + datatree->Jet_Dtr_E[jet_entry_2]);
//
//                if(h2comb_momentum->M()/1000.>0.730&&h2comb_momentum->M()/1000.<0.810&&datatree->Jet_Dtr_ID[h2_location]!=datatree->Jet_Dtr_ID[jet_entry]) 
//                {comb2_exist++; break;}
//            }
//        }

        //std::cout<<"Second check complete"<<std::endl;

        // Pick the leading hadron and check all possible combinations with other hadrons
        for(int jet_entry = 0 ; jet_entry < datatree->Jet_NDtr ; jet_entry++)
        {
            for(int jet_entry_2 = jet_entry+1 ; jet_entry_2 < datatree->Jet_NDtr ; jet_entry_2++)
            {
                if(datatree->Jet_Dtr_PX[jet_entry]==-999||datatree->Jet_Dtr_PX[jet_entry_2]==-999||
                   jet_entry==h1_location||jet_entry_2==h1_location/*||jet_entry==h1_location||comb1_exist==1*/) continue;

                h1comb_momentum->SetPxPyPzE(datatree->Jet_Dtr_PX[h1_location] + datatree->Jet_Dtr_PX[jet_entry] + datatree->Jet_Dtr_PX[jet_entry_2], 
                                            datatree->Jet_Dtr_PY[h1_location] + datatree->Jet_Dtr_PY[jet_entry] + datatree->Jet_Dtr_PY[jet_entry_2], 
                                            datatree->Jet_Dtr_PZ[h1_location] + datatree->Jet_Dtr_PZ[jet_entry] + datatree->Jet_Dtr_PZ[jet_entry_2],
                                            datatree->Jet_Dtr_E[h1_location]  + datatree->Jet_Dtr_E[jet_entry]  + datatree->Jet_Dtr_E[jet_entry_2]);
                vars[0]  = eq_charge;
                vars[1]  = h1comb_momentum->M()/1000.;
                vars[2]  = datatree->Jet_Dtr_ID[h1_location];
                vars[3]  = datatree->Jet_Dtr_ID[jet_entry];
                vars[4]  = datatree->Jet_Dtr_ID[jet_entry_2];
                vars[5]  = datatree->Jet_Dtr_TrackChi2[h1_location];
                vars[6]  = datatree->Jet_Dtr_TrackChi2[h2_location];
                vars[7]  = datatree->Jet_Dtr_TrackNDF[h1_location];
                vars[8]  = datatree->Jet_Dtr_TrackNDF[h2_location];
                vars[9]  = datatree->Jet_Dtr_ProbNNghost[h1_location];
                vars[10]  = datatree->Jet_Dtr_ProbNNghost[h2_location];
                vars[11] = datatree->Jet_Dtr_P[h1_location]/1000.;
                vars[12] = datatree->Jet_Dtr_P[h2_location]/1000.;
                vars[13] = datatree->Jet_Dtr_PT[h1_location]/1000.;
                vars[14] = datatree->Jet_Dtr_PT[h2_location]/1000.;
                vars[15] = calculate_z_lh(&h1_momentum, &h2_momentum);
                vars[16] = calculate_z_nlh(&h1_momentum, &h2_momentum);
                vars[17] = calculate_kt(&h1_momentum, &h2_momentum);
                vars[18] = datatree->Jet_Dtr_PZ[h1_location]/1000.;
                vars[19] = datatree->Jet_Dtr_PZ[h2_location]/1000.;
                vars[20] = datatree->Jet_PT/1000.;

                // Create Jet 4vector to get jet eta and jet phi
                double Jet_px = datatree->Jet_PX;
                double Jet_py = datatree->Jet_PY;
                double Jet_pz = datatree->Jet_PZ;
                double Jet_pe = datatree->Jet_PE;
                Jet_4vector->SetPxPyPzE(Jet_px, Jet_py, Jet_pz, Jet_pe);
                vars[21] = Jet_4vector->Eta();
                vars[22] = Jet_4vector->Phi();

                // add mum_phi:mum_pt:mum_eta:mum_probchi2:mup_phi:mup_pt:mup_eta:mup_probchi2
                double Z0_px = datatree->Z0_PX/1000.;
                double Z0_py = datatree->Z0_PY/1000.;
                double Z0_pz = datatree->Z0_PZ/1000.;
                double Z0_e  = datatree->Z0_PE/1000.;
                Z0data_4vector->SetPxPyPzE(Z0_px, Z0_py, Z0_pz, Z0_e);
                vars[23] = Z0data_4vector->Phi();

                double mum_px = datatree->mum_PX/1000.;
                double mum_py = datatree->mum_PY/1000.;
                double mum_pz = datatree->mum_PZ/1000.;
                double mum_e  = datatree->mum_PE/1000.;
                mumdata_4vector->SetPxPyPzE(mum_px, mum_py, mum_pz, mum_e);
                vars[24] = mumdata_4vector->Phi();
                vars[25] = mumdata_4vector->Pt();
                vars[26] = mumdata_4vector->Eta();
                vars[27] = mum_px;
                vars[28] = mum_py;
                vars[29] = mum_pz;
                vars[30] = mum_e;
                vars[31] = mumdata_4vector->M();//datatree->mum_M;
                vars[32] = datatree->mum_TRACK_PCHI2;

                double mup_px = datatree->mup_PX/1000.;
                double mup_py = datatree->mup_PY/1000.;
                double mup_pz = datatree->mup_PZ/1000.;
                double mup_e  = datatree->mup_PE/1000.;
                mupdata_4vector->SetPxPyPzE(mup_px, mup_py, mup_pz, mup_e);
                vars[33] = mupdata_4vector->Phi();
                vars[34] = mupdata_4vector->Pt();
                vars[35] = mupdata_4vector->Eta();
                vars[36] = mup_px;
                vars[37] = mup_py;
                vars[38] = mup_pz;
                vars[39] = mup_e;
                vars[40] = mupdata_4vector->M();//datatree->mup_M;
                vars[41] = datatree->mup_TRACK_PCHI2;

                ntuple_invmass->Fill(vars);
            }
        }
        
        //std::cout<<"First filling complete"<<std::endl;

        // Pick the subleading hadron and check all possible combinations except for the with the leading hadron which is already accounted
        for(int jet_entry = 0 ; jet_entry < datatree->Jet_NDtr ; jet_entry++)
        {
            for(int jet_entry_2 = jet_entry+1 ; jet_entry_2 < datatree->Jet_NDtr ; jet_entry_2++)
            {
                if(datatree->Jet_Dtr_PX[jet_entry]==-999||datatree->Jet_Dtr_PX[jet_entry_2]==-999||
                   jet_entry==h1_location||jet_entry_2==h1_location||jet_entry==h2_location||jet_entry_2==h2_location) continue;

                h2comb_momentum->SetPxPyPzE(datatree->Jet_Dtr_PX[h2_location] + datatree->Jet_Dtr_PX[jet_entry] + datatree->Jet_Dtr_PX[jet_entry_2], 
                                            datatree->Jet_Dtr_PY[h2_location] + datatree->Jet_Dtr_PY[jet_entry] + datatree->Jet_Dtr_PY[jet_entry_2], 
                                            datatree->Jet_Dtr_PZ[h2_location] + datatree->Jet_Dtr_PZ[jet_entry] + datatree->Jet_Dtr_PZ[jet_entry_2],
                                            datatree->Jet_Dtr_E[h2_location]  + datatree->Jet_Dtr_E[jet_entry]  + datatree->Jet_Dtr_E[jet_entry_2]);
                vars[0]  = eq_charge;
                vars[1]  = h2comb_momentum->M()/1000.;
                vars[2]  = datatree->Jet_Dtr_ID[h2_location];
                vars[3]  = datatree->Jet_Dtr_ID[jet_entry];
                vars[4]  = datatree->Jet_Dtr_ID[jet_entry_2];
                vars[5]  = datatree->Jet_Dtr_TrackChi2[h1_location];
                vars[6]  = datatree->Jet_Dtr_TrackChi2[h2_location];
                vars[7]  = datatree->Jet_Dtr_TrackNDF[h1_location];
                vars[8]  = datatree->Jet_Dtr_TrackNDF[h2_location];
                vars[9]  = datatree->Jet_Dtr_ProbNNghost[h1_location];
                vars[10]  = datatree->Jet_Dtr_ProbNNghost[h2_location];
                vars[11] = datatree->Jet_Dtr_P[h1_location]/1000.;
                vars[12] = datatree->Jet_Dtr_P[h2_location]/1000.;
                vars[13] = datatree->Jet_Dtr_PT[h1_location]/1000.;
                vars[14] = datatree->Jet_Dtr_PT[h2_location]/1000.;
                vars[15] = calculate_z_lh(&h1_momentum, &h2_momentum);
                vars[16] = calculate_z_nlh(&h1_momentum, &h2_momentum);
                vars[17] = calculate_kt(&h1_momentum, &h2_momentum);
                vars[18] = datatree->Jet_Dtr_PZ[h1_location]/1000.;
                vars[19] = datatree->Jet_Dtr_PZ[h2_location]/1000.;
                vars[20] = datatree->Jet_PT/1000.;

                // Create Jet 4vector to get jet eta and jet phi
                double Jet_px = datatree->Jet_PX;
                double Jet_py = datatree->Jet_PY;
                double Jet_pz = datatree->Jet_PZ;
                double Jet_pe = datatree->Jet_PE;
                Jet_4vector->SetPxPyPzE(Jet_px, Jet_py, Jet_pz, Jet_pe);
                vars[21] = Jet_4vector->Eta();
                vars[22] = Jet_4vector->Phi();

                // add mum_phi:mum_pt:mum_eta:mum_probchi2:mup_phi:mup_pt:mup_eta:mup_probchi2
                double Z0_px = datatree->Z0_PX/1000.;
                double Z0_py = datatree->Z0_PY/1000.;
                double Z0_pz = datatree->Z0_PZ/1000.;
                double Z0_e  = datatree->Z0_PE/1000.;
                Z0data_4vector->SetPxPyPzE(Z0_px, Z0_py, Z0_pz, Z0_e);
                vars[23] = Z0data_4vector->Phi();

                double mum_px = datatree->mum_PX/1000.;
                double mum_py = datatree->mum_PY/1000.;
                double mum_pz = datatree->mum_PZ/1000.;
                double mum_e  = datatree->mum_PE/1000.;
                mumdata_4vector->SetPxPyPzE(mum_px, mum_py, mum_pz, mum_e);
                vars[24] = mumdata_4vector->Phi();
                vars[25] = mumdata_4vector->Pt();
                vars[26] = mumdata_4vector->Eta();
                vars[27] = mum_px;
                vars[28] = mum_py;
                vars[29] = mum_pz;
                vars[30] = mum_e;
                vars[31] = mumdata_4vector->M();//datatree->mum_M;
                vars[32] = datatree->mum_TRACK_PCHI2;

                double mup_px = datatree->mup_PX/1000.;
                double mup_py = datatree->mup_PY/1000.;
                double mup_pz = datatree->mup_PZ/1000.;
                double mup_e  = datatree->mup_PE/1000.;
                mupdata_4vector->SetPxPyPzE(mup_px, mup_py, mup_pz, mup_e);
                vars[33] = mupdata_4vector->Phi();
                vars[34] = mupdata_4vector->Pt();
                vars[35] = mupdata_4vector->Eta();
                vars[36] = mup_px;
                vars[37] = mup_py;
                vars[38] = mup_pz;
                vars[39] = mup_e;
                vars[40] = mupdata_4vector->M();//datatree->mup_M;
                vars[41] = datatree->mup_TRACK_PCHI2;

                ntuple_invmass->Fill(vars);
            }
        }
    
        //std::cout<<"Second filling complete"<<std::endl;
    }

    std::cout<<"Inv. Mass Trio TNtuple done!"<<std::endl;


    // Write the TNtuple in the output file
    fout->cd();
    ntuple_invmass->Write();
    fout->Close();

    return 0;
}