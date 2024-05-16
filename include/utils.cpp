#ifndef UTILS_H
#define UTILS_H

#include "TZJets.h"

// These functions returns 1 if components of the desired dihadron exist within jet
int dh_comp_exist_mc(TMCJets*      tree, int pid_ha, int pid_hb);
int dh_comp_exist_mcreco(TZJets*  tree, int pid_ha, int pid_hb);
int dh_comp_exist_data(TZJetsData* tree, int pid_ha, int pid_hb);
int dh_comp_exist_mcrecotruth(TZJets* tree, int pid_ha, int pid_hb);

// These functions locate the leading hadron and store the location and the energy
void loc_lh_mc(TMCJets* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy);
void loc_nlh_mc(TMCJets* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy);

void loc_lh_mcreco(TZJets* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy);
void loc_nlh_mcreco(TZJets* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy);

void loc_lh_mcrecotruth(TZJets* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy);
void loc_nlh_mcrecotruth(TZJets* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy);

void loc_lh_data(TZJetsData* tree, int pid_ha, int pid_hb, int &lh_loc, double &lh_energy);
void loc_nlh_data(TZJetsData* tree, int pid_ha, int pid_hb, int lh_loc, double lh_energy, int &nlh_loc, double &nlh_energy);

// Function to calculate the uncertainty based on propagation of errors
void set_uncertainties(TH1F* hcs_samesign, TH1F* hcs_diffsign, TH1F* hrc);

#endif