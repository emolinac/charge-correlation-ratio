#ifndef UTILS_H
#define UTILS_H

#include "TMCJets.h"
#include "TZJets.h"
#include "TZJetsData.h"
#include "TH1.h"
#include <iostream>

// These functions returns 1 if components of the desired dihadron exist within jet
int dh_comp_exist_mc(TMCJets* tree, int pid_ha, int pid_hb)
{
    // Get number of daughters in this jet
    const int ndtr = tree->CELLjet_MCNDtr;
    
    // Set counter
    int dihadron_components = 0;
    for(int part = 0 ; part < ndtr ; part++)
    {
        if(tree->MCJet_Dtr_ID[part]==pid_ha||tree->MCJet_Dtr_ID[part]==pid_hb) dihadron_components++;
    }

    if(dihadron_components<2) return 0;

    return 1;
}

int dh_comp_exist_mcreco(TZJets* tree, int pid_ha, int pid_hb)
{
    // Get number of daughters in this jet
    const int ndtr = tree->Jet_NDtr;
    
    // Set counter
    int dihadron_components = 0;
    for(int part = 0 ; part < ndtr ; part++)
    {
        if(tree->Jet_Dtr_ID[part]==pid_ha||tree->Jet_Dtr_ID[part]==pid_hb) dihadron_components++;
    }

    if(dihadron_components<2) return 0;

    return 1;
}

int dh_comp_exist_data(TZJetsData* tree, int pid_ha, int pid_hb)
{
    // Get number of daughters in this jet
    const int ndtr = tree->Jet_NDtr;
    
    // Set counter
    int dihadron_components = 0;
    for(int part = 0 ; part < ndtr ; part++)
    {
        if(tree->Jet_Dtr_ID[part]==pid_ha||tree->Jet_Dtr_ID[part]==pid_hb) dihadron_components++;
    }

    if(dihadron_components<2) return 0;

    return 1;
}

// These functions locate the leading hadron and store the location and the energy
void loc_lh_mc(TMCJets* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy)
{
    // Get number of daughters in this jet
    const int ndtr = tree->CELLjet_MCNDtr;

    // Check location of leading hadron
    for(int part = 0 ; part < ndtr ; part++) 
    {
        // If particle is not a hadron skip it
        if(tree->MCJet_Dtr_IsBaryon[part]==0&&tree->MCJet_Dtr_IsMeson[part]==0) continue;
        if(tree->MCJet_Dtr_E[part]>lh_energy) {lh_loc = part; lh_energy = tree->MCJet_Dtr_E[part];}
    }
    
    // Check if leading hadron is a component of the desired dihadron
    if(tree->MCJet_Dtr_ID[lh_loc]==pid_ha||tree->MCJet_Dtr_ID[lh_loc]==pid_hb) return;

    // If the leading hadron is not a component of the desired dihadron then we set everything to -999
    lh_loc    = -999;
    lh_energy = -999;

    return;
}

void loc_nlh_mc(TMCJets* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy)
{
    double delta = 100000000;

    // Get number of daughters in this jet
    const int ndtr = tree->CELLjet_MCNDtr;

    // Locate the particle that has the biggest energy besides the leading hadron
    for(int part = 0 ; part < ndtr ; part++)
    {
        // Skip leading hadron or if particle is not a hadron
        if(tree->MCJet_Dtr_IsBaryon[part]==0&&tree->MCJet_Dtr_IsMeson[part]==0) continue;
        if(part==lh_loc) continue;

        // Check the size of the energy diference
        if((lh_energy - tree->MCJet_Dtr_E[part])<delta)
        {
            delta      = lh_energy - tree->MCJet_Dtr_E[part];
            nlh_loc    = part;
            nlh_energy = tree->MCJet_Dtr_E[part];
        }
    }

    // Check veracity of next-to-leading hadron
    if(tree->MCJet_Dtr_ID[nlh_loc]==pid_ha||tree->MCJet_Dtr_ID[nlh_loc]==pid_hb) return;

    nlh_loc    = -999;
    nlh_energy = -999;

    return;
}

void loc_lh_mcreco(TZJets* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy)
{
    // Get number of daughters in this jet
    const int ndtr = tree->Jet_NDtr;

    // Check location of leading hadron
    for(int part = 0 ; part < ndtr ; part++) 
    {
        // If particle is not a hadron skip it
        if(tree->Jet_Dtr_IsBaryon[part]==0&&tree->Jet_Dtr_IsMeson[part]==0) continue;
        if(tree->Jet_Dtr_E[part]>lh_energy) {lh_loc = part; lh_energy = tree->Jet_Dtr_E[part];}
    }
    
    // Check if leading hadron is a component of the desired dihadron
    if(tree->Jet_Dtr_ID[lh_loc]==pid_ha||tree->Jet_Dtr_ID[lh_loc]==pid_hb) return;
    
    // If the leading hadron is not a component of the desired dihadron then we set everything to -999
    lh_loc    = -999;
    lh_energy = -999;
    
    return;
}

void loc_nlh_mcreco(TZJets* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy)
{
    double delta = 100000000;

    // Get number of daughters in this jet
    const int ndtr = tree->Jet_NDtr;

    // Locate the particle that has the biggest energy besides the leading hadron
    for(int part = 0 ; part < ndtr ; part++)
    {
        // Skip leading hadron or if particle is not a hadron
        if(tree->Jet_Dtr_IsBaryon[part]==0&&tree->Jet_Dtr_IsMeson[part]==0) continue;
        if(part==lh_loc) continue;

        // Check the size of the energy diference
        if((lh_energy - tree->Jet_Dtr_E[part])<delta)
        {
            delta      = lh_energy - tree->Jet_Dtr_E[part];
            nlh_loc    = part;
            nlh_energy = tree->Jet_Dtr_E[part];
        }
    }

    // Check veracity of next-to-leading hadron
    if(tree->Jet_Dtr_ID[nlh_loc]==pid_ha||tree->Jet_Dtr_ID[nlh_loc]==pid_hb) return;

    nlh_loc    = -999;
    nlh_energy = -999;

    return;
}

void loc_lh_data(TZJetsData* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy)
{
    // Get number of daughters in this jet
    const int ndtr = tree->Jet_NDtr;

    // Check location of leading hadron
    for(int part = 0 ; part < ndtr ; part++) 
    {
        // If particle is not a hadron skip it
        if(tree->Jet_Dtr_IsBaryon[part]==0&&tree->Jet_Dtr_IsMeson[part]==0) continue;
        if(tree->Jet_Dtr_E[part]>lh_energy) {lh_loc = part; lh_energy = tree->Jet_Dtr_E[part];}
    }
    
    // Check if leading hadron is a component of the desired dihadron
    if(tree->Jet_Dtr_ID[lh_loc]==pid_ha||tree->Jet_Dtr_ID[lh_loc]==pid_hb) return;
    
    // If the leading hadron is not a component of the desired dihadron then we set everything to -999
    lh_loc    = -999;
    lh_energy = -999;
    
    return;
}

void loc_nlh_data(TZJetsData* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy)
{
    double delta = 100000000;
    // Get number of daughters in this jet
    const int ndtr = tree->Jet_NDtr;

    // Locate the particle that has the biggest energy besides the leading hadron
    for(int part = 0 ; part < ndtr ; part++)
    {
        // Skip leading hadron or if particle is not a hadron
        if(tree->Jet_Dtr_IsBaryon[part]==0&&tree->Jet_Dtr_IsMeson[part]==0) continue;
        if(part==lh_loc) continue;

        // Check the size of the energy diference
        if((lh_energy - tree->Jet_Dtr_E[part])<delta)
        {
            delta      = lh_energy - tree->Jet_Dtr_E[part];
            nlh_loc    = part;
            nlh_energy = tree->Jet_Dtr_E[part];
        }
    }

    // Check veracity of next-to-leading hadron
    if(tree->Jet_Dtr_ID[nlh_loc]==pid_ha||tree->Jet_Dtr_ID[nlh_loc]==pid_hb) return;

    nlh_loc    = -999;
    nlh_energy = -999;

    return;
}

// Function to calculate the uncertainty
void set_uncertainties(TH1F* hcs_samesign, TH1F* hcs_diffsign, TH1F* hrc)
{
    for(int bin = 1 ; bin <= hrc->GetNbinsX() ; bin++)
    {
        double h1h2        = hcs_samesign->GetBinContent(bin);
        double h1h2bar     = hcs_diffsign->GetBinContent(bin);
        double h1h2_err    = hcs_samesign->GetBinError(bin);
        double h1h2bar_err = hcs_diffsign->GetBinError(bin);

        double err = 2./pow(h1h2+h1h2bar,2)*sqrt(pow(h1h2bar*h1h2_err-h1h2*h1h2bar_err,2));
        hrc->SetBinError(bin, err);
    }

    return;
}

#endif