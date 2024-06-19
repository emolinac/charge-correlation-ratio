#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"
#include "../include/utils-visual.h"

void macro_print_unfolding()
{
    // Open the file with the unfold TNtuple
    TFile* f = new TFile((output_folder+namef_ntuple_unfold).c_str());

    // Get the TNtuple
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_unfold.c_str());

    // Declare histograms and fill it
    TH1F* hmeas = new TH1F("hmeas","",Nbin_jet_pt,jet_pt_limits);
    TH1F* htrue = new TH1F("htrue","",Nbin_jet_pt,jet_pt_limits);
    TH2F* hresp = new TH2F("hresp","",Nbin_jet_pt,jet_pt_limits,Nbin_jet_pt,jet_pt_limits);

    hmeas->Sumw2();
    htrue->Sumw2();

    set_histogram_style(htrue, kCyan, std_line_width, std_marker_style, std_marker_size);
    set_histogram_style(hmeas, kBlue, std_line_width, std_marker_style, std_marker_size);

    // Set branches to variables
    float signal, jet_pt_mc, jet_pt_mcreco, eq_charge;
    ntuple->SetBranchAddress("signal"       ,&signal       );
    ntuple->SetBranchAddress("eq_charge"    ,&eq_charge    );
    ntuple->SetBranchAddress("jet_pt_mc"    ,&jet_pt_mc    );
    ntuple->SetBranchAddress("jet_pt_mcreco",&jet_pt_mcreco);

    // Declares response object from roounfold
    RooUnfoldResponse response(hmeas, htrue, hresp, "response");

    for(int entry = 0 ;  entry < ntuple->GetEntries() ; entry++)
    {
        ntuple->GetEntry(entry);

        // Checking opposite charge hadrons
        if(eq_charge!=0) continue;

        // If there is no matching event in MC 
        if(signal!=1) {response.Fake(jet_pt_mcreco); continue;}

        // If there is a matching event in MC
        response.Fill(jet_pt_mcreco,jet_pt_mc);
        hmeas->Fill(jet_pt_mcreco);
        htrue->Fill(jet_pt_mc);
    }
    
    // Matrix invertion
    RooUnfoldBayes unfold(&response, hmeas, 100);
    auto* hreco = unfold.Hunfold();

    set_histogram_style(hreco, kRed, std_line_width, 21, std_marker_size);

    hreco->Draw();
    hmeas->Draw("same");
    htrue->Draw("same");

    TLegend* legend = new TLegend();
    legend->AddEntry(hreco,"Unfolded");
    legend->AddEntry(htrue,"True");
    legend->AddEntry(hmeas,"Reco");
    legend->Draw();
}