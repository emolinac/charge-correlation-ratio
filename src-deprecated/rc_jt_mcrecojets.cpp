#include "analysis-constants.h"
#include "names.h"
#include "utils.h"
#include "TMCJets.h"
#include "TMCJets.C"
#include "TFile.h"
#include "TH1F.h"

int main()
{
    // Declare file where histograms will be saved
    TFile* fout = new TFile((output_folder+rc_kt_mcrecojets).c_str(),"RECREATE");
    gROOT->cd();

    // Declare a TTree based on the custom class
    TMCJets* mctree = new TMCJets();

    // Declare histograms
    TH1F* samesign_sigma_kt = new TH1F("samesign_sigma_kt","",Nbin_kt,kt_min,kt_max);
    TH1F* diffsign_sigma_kt = new TH1F("diffsign_sigma_kt","",Nbin_kt,kt_min,kt_max);
    TH1F* sum_sigma_kt      = new TH1F("sum_sigma_kt"     ,"",Nbin_kt,kt_min,kt_max);
    TH1F* sub_sigma_kt      = new TH1F("sub_sigma_kt"     ,"",Nbin_kt,kt_min,kt_max);
    TH1F* rc_kt            = new TH1F("rc_kt"           ,"",Nbin_kt,kt_min,kt_max);

    samesign_sigma_kt->Sumw2();
    diffsign_sigma_kt->Sumw2();
    sum_sigma_kt->Sumw2();     
    sub_sigma_kt->Sumw2();     
    rc_kt->Sumw2();             

    // Jets loop
    for(int evt = 0 ; evt < mctree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        mctree->GetEntry(evt);

        // Check if there is desired dihadron
        if(!dh_comp_exist_mcreco(mctree, pid_ha, pid_hb)) continue;

        // Determine location leading hadron
        int h1_location  = 0;
        double h1_energy = 0;
        loc_lh_mcreco(mctree, pid_ha, pid_hb, h1_location, h1_energy);

        // Check of leading hadron
        if(h1_location == -999) continue;

        // Determine location of next-to-leading hadron
        int h2_location  = 0;
        double h2_energy = 0;
        loc_nlh_mcreco(mctree, pid_ha, pid_hb, h1_location, h1_energy, h2_location, h2_energy);

        // Check of next to leading hadron
        if(h2_location == -999) continue;
        
        // Fill histogram accordingly
        float h1_charge = mctree->MCJet_recojet_Dtr_ThreeCharge[h1_location];
        float h2_charge = mctree->MCJet_recojet_Dtr_ThreeCharge[h2_location];
        if(h1_charge*h2_charge<0) diffsign_sigma_kt->Fill(mctree->MCJet_recojet_Dtr_kt[h2_location]);
        else samesign_sigma_kt->Fill(mctree->MCJet_recojet_Dtr_kt[h2_location]);

        // Obtain the rc
        sub_sigma_kt->Add(samesign_sigma_kt,diffsign_sigma_kt,1,-1);
        sum_sigma_kt->Add(samesign_sigma_kt,diffsign_sigma_kt,1, 1);
        rc_kt->Divide(sub_sigma_kt,sum_sigma_kt,1,1);
    }
    
    fout->cd();
    samesign_sigma_kt->Write();
    diffsign_sigma_kt->Write();
    sub_sigma_kt->Write();
    sum_sigma_kt->Write();
    rc_kt->Write();
    
    fout->Close();

    return 0;
}


//std::cout<<"In the jet "<<evt<<" there are the following particles"<<std::endl;
//for(int part = 0 ; part < ndtr ; part++)
//{
//    std::cout<<"PID = "<<mctree->MCJet_recojet_Dtr_ID[part]<<"   E="<<mctree->MCJet_recojet_Dtr_E[part]<<std::endl;
//}
//std::cout<<"The leading hadron E="<<mctree->MCJet_recojet_Dtr_E[h1_location]<<std::endl;
//std::cout<<"The next tl hadron E="<<mctree->MCJet_recojet_Dtr_E[h2_location]<<std::endl;