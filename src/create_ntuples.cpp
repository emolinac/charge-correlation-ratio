#include <iostream>
#include "analysis-constants.h"
#include "kinematical-functions.h"
#include "names.h"
#include "utils.h"
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
    TFile* fout = new TFile((output_folder+namef_ntuple_dihadron).c_str(),"RECREATE");
    gROOT->cd();

    // Declare the TNtuples
    TNtuple* ntuple_mc     = new TNtuple(name_ntuple_mc.c_str()    ,"",ntuple_mc_vars    );
    TNtuple* ntuple_mcreco = new TNtuple(name_ntuple_mcreco.c_str(),"",ntuple_mcreco_vars);
    TNtuple* ntuple_data   = new TNtuple(name_ntuple_data.c_str()  ,"",ntuple_data_vars  );

    // Declare the TTrees to be used to build the ntuples
    TZJetsData* datatree = new TZJetsData();
    TZJets* mcrecotree   = new TZJets();
    TMCJets* mctree      = new TMCJets();

    // Fill the mc TNtuple
    // OK I have to be very carfeul here about the relationship between the TRUE quantities and the ones that are in the mcjet branches.
    // they might no be the same.
    double total = 0;
    double cases = 0;
    for(int evt = 0 ; evt < mctree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        mctree->GetEntry(evt);

        // Check if there is desired dihadron
        if(!dh_comp_exist_mc(mctree, pid_ha, pid_hb)) continue; //OK

        // Determine location leading hadron
        int h1_location  = 0;
        double h1_energy = 0;
        loc_lh_mc(mctree, pid_ha, pid_hb, h1_location, h1_energy); //OK

        // Check of leading hadron
        if(h1_location == -999) {continue;}

        // Determine location of next-to-leading hadron
        int h2_location  = 0;
        double h2_energy = 0;
        loc_nlh_mc(mctree, pid_ha, pid_hb, h1_location, h1_energy, h2_location, h2_energy); //OK

        // Check of next to leading hadron
        if(h2_location == -999) continue;

        total++;

        // Check nature of the dihadron in the case where the two should be from different species
        if(!validate_dihadron(mctree->MCJet_Dtr_ID[h1_location],mctree->MCJet_Dtr_ID[h2_location]))
        {
            //std::cout<<"Rejected pair of "<<mctree->MCJet_Dtr_ID[h1_location]<<","<<mctree->MCJet_Dtr_ID[h2_location]<<std::endl;
            continue;
        }
        cases++;

        // Fill histogram accordingly
        float h1_charge = mctree->MCJet_Dtr_ThreeCharge[h1_location];
        float h2_charge = mctree->MCJet_Dtr_ThreeCharge[h2_location];
        float eq_charge = (h1_charge*h2_charge<0) ? 0 : 1;

        // Safety print
        if(mctree->MCJet_Dtr_Z[h2_location]>0.5)
        {
            std::cout<<"SOMETHING IS REALLY WRONG GERE BUDDY!"<<std::endl;
        }

        // Obtain the momentum of the hadrons
        TVector3 h1_momentum(mctree->MCJet_Dtr_PX[h1_location], mctree->MCJet_Dtr_PY[h1_location], mctree->MCJet_Dtr_PZ[h1_location]);
        TVector3 h2_momentum(mctree->MCJet_Dtr_PX[h2_location], mctree->MCJet_Dtr_PY[h2_location], mctree->MCJet_Dtr_PZ[h2_location]);
        
        // Define array carrying the variables
        float vars[Nvars_mc];
        vars[0]  = eq_charge;
        vars[1]  = mctree->MCJet_Dtr_ID[h1_location];
        vars[2]  = mctree->MCJet_Dtr_ID[h2_location];
        vars[3]  = mctree->MCJet_Dtr_P[h1_location]/1000.;
        vars[4]  = mctree->MCJet_Dtr_P[h2_location]/1000.;
        vars[5]  = mctree->MCJet_Dtr_PT[h1_location]/1000.;
        vars[6]  = mctree->MCJet_Dtr_PT[h2_location]/1000.;
        vars[7]  = calculate_z_lh(&h1_momentum, &h2_momentum);
        vars[8]  = calculate_z_nlh(&h1_momentum, &h2_momentum);
        vars[9]  = calculate_kt(&h1_momentum, &h2_momentum);
        vars[10] = mctree->MCJet_Dtr_PZ[h1_location]/1000.;
        vars[11] = mctree->MCJet_Dtr_PZ[h2_location]/1000.; 
        vars[12] = mctree->MCJet_PT/1000.;
        vars[13] = mctree->MCJet_ETA;
        vars[14] = mctree->MCJet_PHI;

        double mum_px = mctree->MCJet_truth_mum_PX/1000.;
        double mum_py = mctree->MCJet_truth_mum_PY/1000.;
        double mum_pz = mctree->MCJet_truth_mum_PZ/1000.;
        double mum_e  = mctree->MCJet_truth_mum_PE/1000.;
        
        double mup_px = mctree->MCJet_truth_mup_PX/1000.;
        double mup_py = mctree->MCJet_truth_mup_PY/1000.;
        double mup_pz = mctree->MCJet_truth_mup_PZ/1000.;
        double mup_e  = mctree->MCJet_truth_mup_PE/1000.;
        
        // Muon branches
        TLorentzVector zbosonmc_4vector(mum_px+mup_px, mum_py+mup_py, mum_pz+mup_pz, mum_e+mup_e);
        
        vars[15] = zbosonmc_4vector.Phi();
        vars[16] = mctree->MCJet_truth_mum_PHI;
        vars[17] = mctree->MCJet_truth_mum_PT/1000.;
        vars[18] = mctree->MCJet_truth_mum_ETA;
        vars[19] = mum_px;
        vars[20] = mum_py;
        vars[21] = mum_pz;
        vars[22] = mum_e;
        vars[23] = mctree->MCJet_truth_mum_M/1000.;
        vars[24] = mctree->MCJet_truth_mup_PHI;
        vars[25] = mctree->MCJet_truth_mup_PT/1000.;
        vars[26] = mctree->MCJet_truth_mup_ETA;
        vars[27] = mup_px;
        vars[28] = mup_py;
        vars[29] = mup_pz;
        vars[30] = mup_e;
        vars[31] = mctree->MCJet_truth_mup_M/1000.;
        
        // :mum_pt:mum_eta

        // Fill the TNtuple
        ntuple_mc->Fill(vars);
    }
    std::cout<<"MC percentage of diff species "<<cases*100./total<<std::endl;
    std::cout<<"MC TNtuple done!"<<std::endl;

    // Fill the mcreco TNtuple
    total = 0;
    cases = 0;
    for(int evt = 0 ; evt < mcrecotree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        mcrecotree->GetEntry(evt);

        // Check if there is desired dihadron
        if(!dh_comp_exist_mcreco(mcrecotree, pid_ha, pid_hb)) continue; //OK

        // Determine location leading hadron
        int h1_location  = 0;
        double h1_energy = 0;
        loc_lh_mcreco(mcrecotree, pid_ha, pid_hb, h1_location, h1_energy); //OK

        // Check of leading hadron
        if(h1_location == -999) continue;

        // Determine location of next-to-leading hadron
        int h2_location  = 0;
        double h2_energy = 0;
        loc_nlh_mcreco(mcrecotree, pid_ha, pid_hb, h1_location, h1_energy, h2_location, h2_energy); //OK

        // Check of next to leading hadron
        if(h2_location == -999) continue;

        total++;

        // Check nature of the dihadron in the case where the two should be from different species
        if(!validate_dihadron(mcrecotree->Jet_Dtr_ID[h1_location],mcrecotree->Jet_Dtr_ID[h2_location]))
        {
            //std::cout<<"Rejected pair of "<<mcrecotree->Jet_Dtr_ID[h1_location]<<","<<mcrecotree->Jet_Dtr_ID[h2_location]<<std::endl;
            continue;
        }

        cases++;

        // Get the charges!
        float h1_charge = mcrecotree->Jet_Dtr_ThreeCharge[h1_location];
        float h2_charge = mcrecotree->Jet_Dtr_ThreeCharge[h2_location];
        float eq_charge = (h1_charge*h2_charge<0) ? 0 : 1;

        // Get the momentum of the hadrons
        TVector3 h1_momentum(mcrecotree->Jet_Dtr_PX[h1_location], mcrecotree->Jet_Dtr_PY[h1_location], mcrecotree->Jet_Dtr_PZ[h1_location]);
        TVector3 h2_momentum(mcrecotree->Jet_Dtr_PX[h2_location], mcrecotree->Jet_Dtr_PY[h2_location], mcrecotree->Jet_Dtr_PZ[h2_location]);

        // Define array carrying the variables
        float vars[Nvars_mcreco];
        vars[0]  = eq_charge;
        vars[1]  = mcrecotree->Jet_Dtr_ID[h1_location];
        vars[2]  = mcrecotree->Jet_Dtr_ID[h2_location];
        vars[3]  = mcrecotree->Jet_Dtr_TrackChi2[h1_location];
        vars[4]  = mcrecotree->Jet_Dtr_TrackChi2[h2_location];
        vars[5]  = mcrecotree->Jet_Dtr_TrackNDF[h1_location];
        vars[6]  = mcrecotree->Jet_Dtr_TrackNDF[h2_location];
        vars[7]  = mcrecotree->Jet_Dtr_ProbNNghost[h1_location];
        vars[8]  = mcrecotree->Jet_Dtr_ProbNNghost[h2_location];
        vars[9]  = mcrecotree->Jet_Dtr_P[h1_location]/1000.;
        vars[10] = mcrecotree->Jet_Dtr_P[h2_location]/1000.;
        vars[11] = mcrecotree->Jet_Dtr_PT[h1_location]/1000.;
        vars[12] = mcrecotree->Jet_Dtr_PT[h2_location]/1000.;
        vars[13] = calculate_z_lh(&h1_momentum, &h2_momentum);
        vars[14] = calculate_z_nlh(&h1_momentum, &h2_momentum);
        vars[15] = calculate_kt(&h1_momentum, &h2_momentum);
        vars[16] = mcrecotree->Jet_Dtr_PZ[h1_location]/1000.;
        vars[17] = mcrecotree->Jet_Dtr_PZ[h2_location]/1000.;
        vars[18] = mcrecotree->Jet_PT/1000.;
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

        // Fill the TNtuple
        ntuple_mcreco->Fill(vars);
    }

    std::cout<<"MCReco percentage of diff species "<<cases*100./total<<std::endl;

    total = 0;
    cases = 0;

    std::cout<<"MCreco TNtuple done!"<<std::endl; //OK

    // Fille the data TNtuple
    for(int evt = 0 ; evt < datatree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        datatree->GetEntry(evt);

        // Check if there is desired dihadron
        if(!dh_comp_exist_data(datatree, pid_ha, pid_hb)) continue;

        // Determine location leading hadron
        int h1_location  = 0;
        double h1_energy = 0;
        loc_lh_data(datatree, pid_ha, pid_hb, h1_location, h1_energy);

        // Check of leading hadron
        if(h1_location == -999) continue;

        // Determine location of next-to-leading hadron
        int h2_location  = 0;
        double h2_energy = 0;
        loc_nlh_data(datatree, pid_ha, pid_hb, h1_location, h1_energy, h2_location, h2_energy);

        // Check of next to leading hadron
        if(h2_location == -999) continue;

        total++;

        // Check nature of the dihadron in the case where the two should be from different species
        if(!validate_dihadron(datatree->Jet_Dtr_ID[h1_location],datatree->Jet_Dtr_ID[h2_location]))
        {
            //std::cout<<"Rejected pair of "<<datatree->Jet_Dtr_ID[h1_location]<<","<<datatree->Jet_Dtr_ID[h2_location]<<std::endl;
            continue;
        }

        cases++;

        // Get the charges
        float h1_charge = datatree->Jet_Dtr_ThreeCharge[h1_location];
        float h2_charge = datatree->Jet_Dtr_ThreeCharge[h2_location];
        float eq_charge = (h1_charge*h2_charge<0) ? 0 : 1;

        // Get the momentum of the hadrons
        TVector3 h1_momentum(datatree->Jet_Dtr_PX[h1_location], datatree->Jet_Dtr_PY[h1_location], datatree->Jet_Dtr_PZ[h1_location]);
        TVector3 h2_momentum(datatree->Jet_Dtr_PX[h2_location], datatree->Jet_Dtr_PY[h2_location], datatree->Jet_Dtr_PZ[h2_location]);

        // Define array carrying the variables
        float vars[Nvars_data];
        vars[0]  = eq_charge;
        // Define dihadron invariant mass
        double h1h2_px = datatree->Jet_Dtr_PX[h1_location] + datatree->Jet_Dtr_PX[h2_location];
        double h1h2_py = datatree->Jet_Dtr_PY[h1_location] + datatree->Jet_Dtr_PY[h2_location];
        double h1h2_pz = datatree->Jet_Dtr_PZ[h1_location] + datatree->Jet_Dtr_PZ[h2_location];
        double h1h2_pe = datatree->Jet_Dtr_E[h1_location]  + datatree->Jet_Dtr_E[h2_location];
        TLorentzVector dihadron_4vector(h1h2_px/1000., h1h2_py/1000., h1h2_pz/1000., h1h2_pe/1000.);
        vars[1]  = dihadron_4vector.M();
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

        // add mum_phi:mum_pt:mum_eta:mum_probchi2:mup_phi:mup_pt:mup_eta:mup_probchi2
        double Z0_px = datatree->Z0_PX/1000.;
        double Z0_py = datatree->Z0_PY/1000.;
        double Z0_pz = datatree->Z0_PZ/1000.;
        double Z0_e  = datatree->Z0_PE/1000.;
        TLorentzVector Z0data_4vector(Z0_px, Z0_py, Z0_pz, Z0_e);
        vars[22] = Z0data_4vector.Phi();

        double mum_px = datatree->mum_PX/1000.;
        double mum_py = datatree->mum_PY/1000.;
        double mum_pz = datatree->mum_PZ/1000.;
        double mum_e  = datatree->mum_PE/1000.;
        TLorentzVector mumdata_4vector(mum_px, mum_py, mum_pz, mum_e);
        vars[23] = mumdata_4vector.Phi();
        vars[24] = mumdata_4vector.Pt();
        vars[25] = mumdata_4vector.Eta();
        vars[26] = mum_px;
        vars[27] = mum_py;
        vars[28] = mum_pz;
        vars[29] = mum_e;
        vars[30] = mumdata_4vector.M();//datatree->mum_M;
        vars[31] = datatree->mum_TRACK_PCHI2;

        double mup_px = datatree->mup_PX/1000.;
        double mup_py = datatree->mup_PY/1000.;
        double mup_pz = datatree->mup_PZ/1000.;
        double mup_e  = datatree->mup_PE/1000.;
        TLorentzVector mupdata_4vector(mup_px, mup_py, mup_pz, mup_e);
        vars[32] = mupdata_4vector.Phi();
        vars[33] = mupdata_4vector.Pt();
        vars[34] = mupdata_4vector.Eta();
        vars[35] = mup_px;
        vars[36] = mup_py;
        vars[37] = mup_pz;
        vars[38] = mup_e;
        vars[39] = mupdata_4vector.M();//datatree->mup_M;
        vars[40] = datatree->mup_TRACK_PCHI2;

        // Fill the TNtuple
        ntuple_data->Fill(vars);
    }

    std::cout<<"Data percentage of diff species "<<cases*100./total<<std::endl;
    std::cout<<"Data TNtuple done!"<<std::endl;
    

    // Write the TNtuple in the output file
    fout->cd();
    ntuple_data->Write();
    ntuple_mc->Write();
    ntuple_mcreco->Write();
    fout->Close();

    return 0;
}