#ifndef ANALYSIS_CONSTANTS_H
#define ANALYSIS_CONSTANTS_H

#include "TCut.h"
#include "TString.h"

// PID 
const int p_id     = 2212;
const int pbar_id  = -p_id;
const int pip_id   = 211;
const int pim_id   = -pip_id;
const int kp_id    = 321;
const int km_id    = -kp_id;
const int dp_id    = 411;
const int dm_id    = -dp_id;
const int dsp_id    = 431;
const int dsm_id    = -dsp_id;
const int gamma_id = 22;

// Masses (GeV)
const double rho_mass      = 0.77526;  // PDG 2023
const double omega_mass    = 0.78266; // PDG 2023
const double eta_mass      = 0.547862; // PDG 2023
const double etaprime_mass = 0.95778;  // PDG 2023
const double kaonp_mass    = 0.493677; // PDG 2023
const double kaonm_mass    = 0.493677; // PDG 2023
const double kaon_mass     = 0.497611; // PDG 2023
const double pi_mass       = 0.134977;
const double phi_mass      = 1.019455;
const double mass_res      = 0.008; // Mass resolution parameter (see src-resolution)


// Selected hadrons to perform analysis
// const int pid_ha = pip_id;
// const int pid_hb = kp_id;

const int pid_ha = dp_id;
const int pid_hb = kp_id;

// Define binning
const int Nbin_z      = 4;//NOMINAL : 5;
const int Nbin_kt     = 4;//NOMINAL : 5;
const int Nbin_jet_pt = 3; // usual binning in jet pt

const double z_min  = 0;
const double z_max  = 0.5;
const double kt_min = 0.25;  
const double kt_max = 2.; 
const double jet_pt_min = 20; 
const double jet_pt_max = 100;

// Binning
const double jet_pt_limits[] = {jet_pt_min, 21.82, 25.124, jet_pt_max};
const double z_limits[] = {z_min, 0.180725, 0.276875, 0.380525, z_max };
const double kt_limits[] = {kt_min, 0.542512, 0.830388, 1.22344, kt_max};

// Define analysis cuts
// Jet cuts
TCut jet_eta_cut = "jet_eta>2.5&&jet_eta<4.";
TCut jet_pt_cut  = Form("jet_pt>%f",jet_pt_min);
TCut jet_cuts    = jet_eta_cut+jet_pt_cut;

// Track cuts
TCut chi2ndf_cut  = "lh_chi2/lh_ndf<3&&nlh_chi2/nlh_ndf<3";
TCut p_cut        = "lh_p>4&&lh_p<1000&&nlh_p>4&&nlh_p<1000";
TCut pt_cut       = "lh_pt>0.250&&nlh_pt>0.250";
TCut pnnghost_cut = "lh_probnnghost<0.5&&nlh_probnnghost<0.5";

TCut trackmc_cuts = p_cut+pt_cut;
TCut track_cuts   = chi2ndf_cut+p_cut+pt_cut+pnnghost_cut;

// Topological cuts
TCut phi_zjet_cut     = "TMath::Abs(D_phi-jet_phi)>7*TMath::Pi()/8.";
TCut phi_Kmjet_cut   = "TMath::Abs(jet_phi-Km_phi)>0.4";
TCut phi_Kpjet_cut   = "TMath::Abs(jet_phi-Kp_phi)>0.4";
TCut topological_cuts = phi_zjet_cut+phi_Kmjet_cut+phi_Kpjet_cut;

// Z boson cuts
TCut mu_pt_cut        = "Km_pt>20.&&Kp_pt>20.";
TCut mu_eta_cut       = "Km_eta>2&&Km_eta<4.5&&Kp_eta>2&&Kp_eta<4.5";
TCut Km_Kp_mass_cut = "sqrt(Km_m*Km_m + Kp_m*Kp_m + 2*(Km_pe*Kp_pe - Km_px*Kp_px - Km_py*Kp_py - Km_pz*Kp_pz))>60 && \
                         sqrt(Km_m*Km_m + Kp_m*Kp_m + 2*(Km_pe*Kp_pe - Km_px*Kp_px - Km_py*Kp_py - Km_pz*Kp_pz))<120";
TCut mu_trackprob_cut = "Km_probchi2>0.001&&Kp_probchi2>0.001";

TCut Zboson_cuts   = mu_pt_cut+mu_eta_cut+Km_Kp_mass_cut+mu_trackprob_cut;
TCut Zbosonmc_cuts = mu_pt_cut+mu_eta_cut+Km_Kp_mass_cut;

// All analysis cuts
TCut diffsign_cut_mc     = "eq_charge==0"+jet_cuts+trackmc_cuts+topological_cuts+Zbosonmc_cuts;
TCut samesign_cut_mc     = "eq_charge==1"+jet_cuts+trackmc_cuts+topological_cuts+Zbosonmc_cuts;
TCut diffsign_cut_mcreco = "eq_charge==0"+jet_cuts+track_cuts  +topological_cuts+Zboson_cuts;
TCut samesign_cut_mcreco = "eq_charge==1"+jet_cuts+track_cuts  +topological_cuts+Zboson_cuts;
TCut diffsign_cut_data   = "eq_charge==0"+jet_cuts+track_cuts  +topological_cuts+Zboson_cuts;
TCut samesign_cut_data   = "eq_charge==1"+jet_cuts+track_cuts  +topological_cuts+Zboson_cuts;
TCut diffsign_cut_data_decay = Form("prob*(eq_charge==0&&jet_eta>2.5&&jet_eta<4.&&jet_pt>%f&&lh_chi2/lh_ndf<3&&nlh_chi2/nlh_ndf<3&&lh_p>4&&lh_p<1000&&nlh_p>4&&nlh_p<1000&&lh_pt>0.250&&nlh_pt>0.250&&\
                                lh_probnnghost<0.5&&nlh_probnnghost<0.5&&TMath::Abs(D_phi-jet_phi)>7*TMath::Pi()/8.&&TMath::Abs(jet_phi-Km_phi)>0.4&&TMath::Abs(jet_phi-Kp_phi)>0.4&&\
                                Km_pt>20.&&Kp_pt>20.&&Km_eta>2&&Km_eta<4.5&&Kp_eta>2&&Kp_eta<4.5&&sqrt(Km_m*Km_m + Kp_m*Kp_m + 2*(Km_pe*Kp_pe - Km_px*Kp_px - Km_py*Kp_py - Km_pz*Kp_pz))>60&&\
                                sqrt(Km_m*Km_m + Kp_m*Kp_m + 2*(Km_pe*Kp_pe - Km_px*Kp_px - Km_py*Kp_py - Km_pz*Kp_pz))<120&&Km_probchi2>0.001&&Kp_probchi2>0.001)",jet_pt_min);
TCut samesign_cut_data_decay = Form("prob*(eq_charge==1&&jet_eta>2.5&&jet_eta<4.&&jet_pt>%f&&lh_chi2/lh_ndf<3&&nlh_chi2/nlh_ndf<3&&lh_p>4&&lh_p<1000&&nlh_p>4&&nlh_p<1000&&lh_pt>0.250&&nlh_pt>0.250&&\
                                lh_probnnghost<0.5&&nlh_probnnghost<0.5&&TMath::Abs(D_phi-jet_phi)>7*TMath::Pi()/8.&&TMath::Abs(jet_phi-Km_phi)>0.4&&TMath::Abs(jet_phi-Kp_phi)>0.4&&\
                                Km_pt>20.&&Kp_pt>20.&&Km_eta>2&&Km_eta<4.5&&Kp_eta>2&&Kp_eta<4.5&&sqrt(Km_m*Km_m + Kp_m*Kp_m + 2*(Km_pe*Kp_pe - Km_px*Kp_px - Km_py*Kp_py - Km_pz*Kp_pz))>60&&\
                                sqrt(Km_m*Km_m + Kp_m*Kp_m + 2*(Km_pe*Kp_pe - Km_px*Kp_px - Km_py*Kp_py - Km_pz*Kp_pz))<120&&Km_probchi2>0.001&&Kp_probchi2>0.001)",jet_pt_min);

// Visual constants
const double std_marker_size  = 1.3;
const int    std_marker_style = 8;
const int    std_line_width   = 3;

#endif