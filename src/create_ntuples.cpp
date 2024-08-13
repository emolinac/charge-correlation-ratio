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
    TFile* fout = new TFile((output_folder+namef_ntuple_dihadron).c_str(),"RECREATE");
    gROOT->cd();

    // Declare the TNtuples
    TNtuple* ntuple_mc     = new TNtuple(name_ntuple_mc.c_str()    ,"",ntuple_mc_vars    );
    TNtuple* ntuple_mcreco = new TNtuple(name_ntuple_mcreco.c_str(),"",ntuple_mcreco_vars);
    TNtuple* ntuple_data   = new TNtuple(name_ntuple_data.c_str()  ,"",ntuple_data_vars  );

    // Declare the TTrees to be used to build the ntuples
    THFJetsData* datatree = new THFJetsData();
    THFJets* mcrecotree   = new THFJets();
    TMCJets* mctree      = new TMCJets();

    // Fill the mc TNtuple
    // OK I have to be very carfeul here about the relationship between the TRUE quantities and the ones that are in the mcjet branches.
    // they might no be the same.
    double total = 0;
    double cases = 0;
    for(int evt = 0 ; evt < mctree->fChain->GetEntries() ; evt++)
    {
        //std::cout<<100.*evt/mctree->fChain->GetEntries()<<"\% done"<<std::endl;
        
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

        double Km_px = mctree->MCJet_truth_Km_PX/1000.;
        double Km_py = mctree->MCJet_truth_Km_PY/1000.;
        double Km_pz = mctree->MCJet_truth_Km_PZ/1000.;
        double Km_e  = mctree->MCJet_truth_Km_PE/1000.;
        
        double Kp_px = mctree->MCJet_truth_Kp_PX/1000.;
        double Kp_py = mctree->MCJet_truth_Kp_PY/1000.;
        double Kp_pz = mctree->MCJet_truth_Kp_PZ/1000.;
        double Kp_e  = mctree->MCJet_truth_Kp_PE/1000.;
        
        // Muon branches
        TLorentzVector zbosonmc_4vector(Km_px+Kp_px, Km_py+Kp_py, Km_pz+Kp_pz, Km_e+Kp_e);
        
        vars[15] = zbosonmc_4vector.Phi();
        vars[16] = mctree->MCJet_truth_Km_PHI;
        vars[17] = mctree->MCJet_truth_Km_PT/1000.;
        vars[18] = mctree->MCJet_truth_Km_ETA;
        vars[19] = Km_px;
        vars[20] = Km_py;
        vars[21] = Km_pz;
        vars[22] = Km_e;
        vars[23] = mctree->MCJet_truth_Km_M/1000.;
        vars[24] = mctree->MCJet_truth_Kp_PHI;
        vars[25] = mctree->MCJet_truth_Kp_PT/1000.;
        vars[26] = mctree->MCJet_truth_Kp_ETA;
        vars[27] = Kp_px;
        vars[28] = Kp_py;
        vars[29] = Kp_pz;
        vars[30] = Kp_e;
        vars[31] = mctree->MCJet_truth_Kp_M/1000.;
        
        // :Km_pt:Km_eta

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
        vars[19] = 0;//mcrecotree->Jet_Eta;
        vars[20] = 0;//mcrecotree->Jet_Phi;

        // Z branch
        double D_px = mcrecotree->Ds_PX/1000.;
        double D_py = mcrecotree->Ds_PY/1000.;
        double D_pz = mcrecotree->Ds_PZ/1000.;
        double D_e  = mcrecotree->Ds_PE/1000.;
        TLorentzVector Dreco_4vector(D_px, D_py, D_pz, D_e);
        vars[21] = Dreco_4vector.Phi();

        // Muon branches
        double Km_px = mcrecotree->Km_PX/1000.;
        double Km_py = mcrecotree->Km_PY/1000.;
        double Km_pz = mcrecotree->Km_PZ/1000.;
        double Km_e  = mcrecotree->Km_PE/1000.;

        TLorentzVector Kmreco_4vector(Km_px, Km_py, Km_pz, Km_e);
        vars[22] = Kmreco_4vector.Phi();
        vars[23] = Kmreco_4vector.Pt();
        vars[24] = Kmreco_4vector.Eta();
        vars[25] = Km_px;
        vars[26] = Km_py;
        vars[27] = Km_pz;
        vars[28] = Km_e;
        vars[29] = mcrecotree->Km_M/1000.;
        vars[30] = mcrecotree->Km_TRACK_PCHI2;
        
        double Kp_px = mcrecotree->Kp_PX/1000.;
        double Kp_py = mcrecotree->Kp_PY/1000.;
        double Kp_pz = mcrecotree->Kp_PZ/1000.;
        double Kp_e  = mcrecotree->Kp_PE/1000.;
        TLorentzVector Kpreco_4vector(Kp_px, Kp_py, Kp_pz, Kp_e);
        vars[31] = Kpreco_4vector.Phi();
        vars[32] = Kpreco_4vector.Pt();
        vars[33] = Kpreco_4vector.Eta();
        vars[34] = Kp_px;
        vars[35] = Kp_py;
        vars[36] = Kp_pz;
        vars[37] = Kp_e;
        vars[38] = mcrecotree->Kp_M/1000.;
        vars[39] = mcrecotree->Kp_TRACK_PCHI2;

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

        // add Km_phi:Km_pt:Km_eta:Km_probchi2:Kp_phi:Kp_pt:Kp_eta:Kp_probchi2
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