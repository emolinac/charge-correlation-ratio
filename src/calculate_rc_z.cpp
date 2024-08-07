#include <iostream>
#include "analysis-constants.h"
#include "directories.h"
#include "names.h"
#include "utils-algorithms.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TCut.h"

int main()
{
    // Define number of types of files you will have
    const int N = 3; // data, mc, mcreco
    std::string name_output[N] = {namef_rc_z_data   , namef_rc_z_mc   , namef_rc_z_mcreco   };
    std::string name_ntuple[N] = {name_ntuple_data , name_ntuple_mc , name_ntuple_mcreco };
    TCut samesign_cuts[N]      = {samesign_cut_data, samesign_cut_mc, samesign_cut_mcreco};
    TCut diffsign_cuts[N]      = {diffsign_cut_data, diffsign_cut_mc, diffsign_cut_mcreco};

    // Open the output files
    TFile* fout[N];
    for(int i = 0 ; i < N ; i++) fout[i] = new TFile((output_folder+name_output[i]).c_str(),"RECREATE");
    gROOT->cd();

    // Open the file with the TNtuples
    TFile* fin = new TFile((output_folder+namef_ntuple_dihadron).c_str());
    
    // Get the dihadron TNtuple
    TNtuple* ntuple[N];
    for(int i = 0 ; i < N ; i++) ntuple[i] = (TNtuple*) fin->Get((name_ntuple[i]).c_str());
    
    // Create the histograms
    
    TH1F* hcs_samesign[N]; TH1F* hcs_diffsign[N];
    TH1F* hcs_sum[N]; TH1F* hcs_sub[N];
    TH1F* rc[N];           

    for(int i = 0 ; i < N ; i++)
    {
        hcs_samesign[i] = new TH1F(Form("hcs_samesign_%i",i),"",Nbin_z,z_limits);
        hcs_diffsign[i] = new TH1F(Form("hcs_diffsign_%i",i),"",Nbin_z,z_limits);
        hcs_sum[i]      = new TH1F(Form("hcs_sum_%i",i)     ,"",Nbin_z,z_limits);
        hcs_sub[i]      = new TH1F(Form("hcs_sub_%i",i)     ,"",Nbin_z,z_limits);
        rc[i]           = new TH1F(Form("rc_%i",i)          ,"",Nbin_z,z_limits);

        hcs_samesign[i]->Sumw2();
        hcs_diffsign[i]->Sumw2();

        // Calculate rc for the data
        ntuple[i]->Project(Form("hcs_diffsign_%i",i),"nlh_z",diffsign_cuts[i]);
        ntuple[i]->Project(Form("hcs_samesign_%i",i),"nlh_z",samesign_cuts[i]);
        hcs_sub[i]->Add(hcs_samesign[i],hcs_diffsign[i],1,-1);
        hcs_sum[i]->Add(hcs_samesign[i],hcs_diffsign[i],1, 1);
        rc[i]->Divide(hcs_sub[i],hcs_sum[i],1,1);

        // Calculate uncertainties
        set_uncertainties(hcs_samesign[i], hcs_diffsign[i], rc[i]);

        // Write it
        fout[i]->cd();
        hcs_sub[i]->Write();
        hcs_sum[i]->Write();
        rc[i]->Write("rc_z");
        gROOT->cd();

        // Close the file
        fout[i]->Close();
    }

    return 0;
}