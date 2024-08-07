#include "../include/analysis-constants.h"
#include "../include/directories.h"
#include "../include/names.h"
#include "../include/utils-algorithms.h"
#include "../include/utils-visual.h"
#include "../include/TZJets.h"
#include "../include/TZJets.C"

void macro_print_singlepart_energy_resolution()
{
    // Declare the TTrees to get the matched daughters
    TZJets* mcrecotree   = new TZJets();

    TH1F* h = new TH1F("h","",100,-20,20);
    
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

        // Check if there is a truth level dihadron
        loc_lh_mcmatcheddtr(mcrecotree, pid_ha, pid_hb, matched_h1_location, matched_h1_energy);
        loc_nlh_mcmatcheddtr(mcrecotree, pid_ha, pid_hb, matched_h1_location, matched_h1_energy, matched_h2_location, matched_h2_energy);

        // Get the signal
        int signal = ((matched_h1_location!=-999&&matched_h2_location!=-999)&&\
                      (mcrecotree->Jet_Dtr_ID[h1_location]==mcrecotree->Jet_Dtr_TRUE_ID[matched_h1_location]&&\
                       mcrecotree->Jet_Dtr_ID[h2_location]==mcrecotree->Jet_Dtr_TRUE_ID[matched_h2_location])/*&&\
                      (h1_location==matched_h1_location&&h2_location==matched_h2_location)*/) ? 1 : 0 ;
        
        // If there is no matching dihadron skip
        if(signal==0) continue;

        // Fill the resolution histogram
        double mcreco_min_mc_lh  = mcrecotree->Jet_Dtr_E[h1_location] - mcrecotree->Jet_Dtr_TRUE_E[h1_location];
        double mcreco_min_mc_nlh = mcrecotree->Jet_Dtr_E[h2_location] - mcrecotree->Jet_Dtr_TRUE_E[h2_location];
        h->Fill(mcreco_min_mc_lh/1000.);
        h->Fill(mcreco_min_mc_nlh/1000.);
    }

    set_histogram_style(h, kViolet+2, std_line_width, std_marker_style, std_marker_size);
    h->Draw();
    h->SetTitle(";#Delta E(mcreco-mc);");
    gPad->SetLogy(1);

}