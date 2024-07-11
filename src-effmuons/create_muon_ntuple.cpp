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
    TFile* fout = new TFile((output_folder+namef_ntuple_effmuons).c_str(),"RECREATE");
    gROOT->cd();

    // Declare the TNtuples
    TNtuple* ntuple_muons      = new TNtuple(name_ntuple_muons.c_str()      ,"",ntuple_muons_vars);
    TNtuple* ntuple_reco_muons = new TNtuple(name_ntuple_reco_muons.c_str() ,"",ntuple_muons_vars);

    // Declare the TTrees to be used to build the ntuples
    TZJetsData* datatree   = new TZJetsData();
    TZJets*     mcrecotree = new TZJets();
    
    // Fill the mcreco TNtuple
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
        vars[1] = calculate_kt(&h1_momentum, &h2_momentum);
        vars[2] = mcrecotree->Jet_Dtr_PZ[h1_location]/1000.;
        vars[3] = mcrecotree->Jet_Dtr_PZ[h2_location]/1000.;
        vars[4] = mcrecotree->Jet_PT/1000.;
        vars[5] = mcrecotree->Jet_Eta;
        vars[6] = mcrecotree->Jet_Phi;

        // Z branch
        double Z0_px = mcrecotree->Z0_PX/1000.;
        double Z0_py = mcrecotree->Z0_PY/1000.;
        double Z0_pz = mcrecotree->Z0_PZ/1000.;
        double Z0_e  = mcrecotree->Z0_PE/1000.;
        TLorentzVector Z0reco_4vector(Z0_px, Z0_py, Z0_pz, Z0_e);
        vars[7] = Z0reco_4vector.Phi();

        // Muon branches
        double mum_px = mcrecotree->mum_PX/1000.;
        double mum_py = mcrecotree->mum_PY/1000.;
        double mum_pz = mcrecotree->mum_PZ/1000.;
        double mum_e  = mcrecotree->mum_PE/1000.;

        TLorentzVector mumreco_4vector(mum_px, mum_py, mum_pz, mum_e);
        vars[8]  = mumreco_4vector.Phi();
        vars[9]  = mumreco_4vector.Pt();
        vars[10] = mumreco_4vector.Eta();
        vars[11] = mum_px;
        vars[12] = mum_py;
        vars[13] = mum_pz;
        vars[14] = mum_e;
        vars[15] = mcrecotree->mum_M/1000.;
        vars[16] = mcrecotree->mum_TRACK_PCHI2;
        vars[17] = mcrecotree->mum_isMuon;
        vars[18] = mcrecotree->mum_ProbNNmu;
        vars[19] = mcrecotree->mum_IPCHI2_OWNPV;
        vars[20] = mcrecotree->mum_OWNPV_CHI2/mcrecotree->mum_OWNPV_NDOF;

        
        double mup_px = mcrecotree->mup_PX/1000.;
        double mup_py = mcrecotree->mup_PY/1000.;
        double mup_pz = mcrecotree->mup_PZ/1000.;
        double mup_e  = mcrecotree->mup_PE/1000.;
        TLorentzVector mupreco_4vector(mup_px, mup_py, mup_pz, mup_e);
        vars[21] = mupreco_4vector.Phi();
        vars[22] = mupreco_4vector.Pt();
        vars[23] = mupreco_4vector.Eta();
        vars[24] = mup_px;
        vars[25] = mup_py;
        vars[26] = mup_pz;
        vars[27] = mup_e;
        vars[28] = mcrecotree->mup_M/1000.;
        vars[29] = mcrecotree->mup_TRACK_PCHI2;
        vars[30] = mcrecotree->mup_isMuon;
        vars[31] = mcrecotree->mup_ProbNNmu;
        vars[32] = mcrecotree->mup_IPCHI2_OWNPV;
        vars[33] = mcrecotree->mup_OWNPV_CHI2/mcrecotree->mum_OWNPV_NDOF;

        // Fill the TNtuple
        ntuple_reco_muons->Fill(vars);
    }

    std::cout<<"MCreco Muon TNtuple done!"<<std::endl; //OK

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
                
        // Get the charges
        float h1_charge = datatree->Jet_Dtr_ThreeCharge[h1_location];
        float h2_charge = datatree->Jet_Dtr_ThreeCharge[h2_location];
        float eq_charge = (h1_charge*h2_charge<0) ? 0 : 1;

        // Get the momentum of the hadrons
        TVector3 h1_momentum(datatree->Jet_Dtr_PX[h1_location], datatree->Jet_Dtr_PY[h1_location], datatree->Jet_Dtr_PZ[h1_location]);
        TVector3 h2_momentum(datatree->Jet_Dtr_PX[h2_location], datatree->Jet_Dtr_PY[h2_location], datatree->Jet_Dtr_PZ[h2_location]);

        // Define array carrying the variables
        float vars[Nvars_data];
        vars[0] = eq_charge;
        vars[1] = calculate_kt(&h1_momentum, &h2_momentum);
        vars[2] = datatree->Jet_Dtr_PZ[h1_location]/1000.;
        vars[3] = datatree->Jet_Dtr_PZ[h2_location]/1000.;
        vars[4] = datatree->Jet_PT/1000.;

        // Create Jet 4vector to get jet eta and jet phi
        double Jet_px = datatree->Jet_PX;
        double Jet_py = datatree->Jet_PY;
        double Jet_pz = datatree->Jet_PZ;
        double Jet_pe = datatree->Jet_PE;
        TLorentzVector Jet_4vector(Jet_px, Jet_py, Jet_pz, Jet_pe);
        vars[5] = Jet_4vector.Eta();
        vars[6] = Jet_4vector.Phi();

        // add mum_phi:mum_pt:mum_eta:mum_probchi2:mup_phi:mup_pt:mup_eta:mup_probchi2
        double Z0_px = datatree->Z0_PX/1000.;
        double Z0_py = datatree->Z0_PY/1000.;
        double Z0_pz = datatree->Z0_PZ/1000.;
        double Z0_e  = datatree->Z0_PE/1000.;
        TLorentzVector Z0data_4vector(Z0_px, Z0_py, Z0_pz, Z0_e);
        vars[7] = Z0data_4vector.Phi();

        double mum_px = datatree->mum_PX/1000.;
        double mum_py = datatree->mum_PY/1000.;
        double mum_pz = datatree->mum_PZ/1000.;
        double mum_e  = datatree->mum_PE/1000.;
        TLorentzVector mumdata_4vector(mum_px, mum_py, mum_pz, mum_e);
        vars[8]  = mumdata_4vector.Phi();
        vars[9]  = mumdata_4vector.Pt();
        vars[10] = mumdata_4vector.Eta();
        vars[11] = mum_px;
        vars[12] = mum_py;
        vars[13] = mum_pz;
        vars[14] = mum_e;
        vars[15] = mumdata_4vector.M();//datatree->mum_M;
        vars[16] = datatree->mum_TRACK_PCHI2;
        vars[17] = datatree->mum_isMuon;
        vars[18] = datatree->mum_ProbNNmu;
        vars[19] = datatree->mum_IPCHI2_OWNPV;
        vars[20] = datatree->mum_OWNPV_CHI2/datatree->mum_OWNPV_NDOF;

        double mup_px = datatree->mup_PX/1000.;
        double mup_py = datatree->mup_PY/1000.;
        double mup_pz = datatree->mup_PZ/1000.;
        double mup_e  = datatree->mup_PE/1000.;
        TLorentzVector mupdata_4vector(mup_px, mup_py, mup_pz, mup_e);
        vars[21] = mupdata_4vector.Phi();
        vars[22] = mupdata_4vector.Pt();
        vars[23] = mupdata_4vector.Eta();
        vars[24] = mup_px;
        vars[25] = mup_py;
        vars[26] = mup_pz;
        vars[27] = mup_e;
        vars[28] = mupdata_4vector.M();//datatree->mup_M;
        vars[29] = datatree->mup_TRACK_PCHI2;
        vars[30] = datatree->mup_isMuon;
        vars[31] = datatree->mup_ProbNNmu;
        vars[32] = datatree->mup_IPCHI2_OWNPV;
        vars[33] = datatree->mup_OWNPV_CHI2/datatree->mup_OWNPV_NDOF;

        // Fill the TNtuple
        ntuple_muons->Fill(vars);
    }

    std::cout<<"Data Muon TNtuple done!"<<std::endl;

    // Write the TNtuple in the output file
    fout->cd();
    ntuple_muons->Write();
    ntuple_reco_muons->Write();
    fout->Close();

    return 0;
}