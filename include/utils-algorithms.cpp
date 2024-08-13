#ifndef UTILS_ALGORITHMS_H
#define UTILS_ALGORITHMS_H

#include "THFJets.h"

// These functions returns 1 if components of the desired dihadron exist within jet
int dh_comp_exist_mc(TMCJets*      tree, int pid_ha, int pid_hb);
int dh_comp_exist_mcreco(THFJets*  tree, int pid_ha, int pid_hb);
int dh_comp_exist_data(THFJetsData* tree, int pid_ha, int pid_hb);
int dh_comp_exist_mcrecotruth(THFJets* tree, int pid_ha, int pid_hb);
int dh_comp_exist_decays(THFJets* tree, int pid_ha, int pid_hb);

// These functions locate the leading hadron and store the location and the energy
void loc_lh_mc(TMCJets* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy);
void loc_nlh_mc(TMCJets* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy);

void loc_lh_mcreco(THFJets* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy);
void loc_nlh_mcreco(THFJets* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy);

void loc_lh_mcmatchedjet(THFJets* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy);
void loc_nlh_mcmatchedjet(THFJets* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy);

void loc_lh_mcmatcheddtr(THFJets* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy);
void loc_nlh_mcmatcheddtr(THFJets* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy);

void loc_lh_decays(THFJets* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy);
void loc_nlh_decays(THFJets* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy);

void loc_lh_data(THFJetsData* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy);
void loc_nlh_data(THFJetsData* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy);

// Function to calculate the uncertainty based on propagation of errors
void set_uncertainties(TH1F* hcs_samesign, TH1F* hcs_diffsign, TH1F* hrc);
void set_uncertainties_purity(TH1F* hdata, TH1F* hpurity, TH1F* hdatapurity);

// Functions to check nature of dihadrons
int validate_dihadron(int lh_id, int nlh_id)
int validate_dihadron_decays(int lh_id, int nlh_id, int pid_ha, int pid_hb)
#endif