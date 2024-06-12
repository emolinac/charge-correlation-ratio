#ifndef ANALYSIS_CONSTANTS_H
#define ANALYSIS_CONSTANTS_H

#include "TCut.h"

// PID 
const int p_id    = 2212;
const int pbar_id = -p_id;
const int pip_id  = 211;
const int pim_id  = -pip_id;
const int kp_id   = 321;
const int km_id   = -kp_id;

// Selected hadrons to perform analysis
const int pid_ha = pip_id;
const int pid_hb = pim_id;

// Define binning
const int Nbin_z      = 5;
const int Nbin_kt     = 5;
const int Nbin_jet_pt = 3; // usual binning in jet pt

const double z_min  = 0;
const double z_max  = 0.5;
const double kt_min = 0.;  
const double kt_max = 5.; 
const double jet_pt_min = 20; 
const double jet_pt_max = 100;

const double jet_pt_limits[] = {jet_pt_min,30.,50.,jet_pt_max};
const double z_limits[] = {z_min, 0.26625, 0.34875, 0.40875, 0.45875, z_max};
const double kt_limits[] = {kt_min, 0.7125, 1.2625, 1.9625, 3.0875, kt_max};

// Define analysis cuts
// Jet cuts
TCut jet_eta_cut = "jet_eta>2&&jet_eta<4.5";
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
TCut phi_zjet_cut     = "TMath::Abs(z0_phi-jet_phi)>7*TMath::Pi()/8.";
TCut phi_mumjet_cut   = "TMath::Abs(jet_phi-mum_phi)>0.4";
TCut phi_mupjet_cut   = "TMath::Abs(jet_phi-mup_phi)>0.4";
TCut topological_cuts = phi_zjet_cut+phi_mumjet_cut+phi_mupjet_cut;

// Z boson cuts
TCut mu_pt_cut        = "mum_pt>20.&&mup_pt>20.";
TCut mu_eta_cut       = "mum_eta>2&&mum_eta<4.5&&mup_eta>2&&mup_eta<4.5";
TCut mum_mup_mass_cut = "sqrt(mum_m*mum_m + mup_m*mup_m + 2*(mum_pe*mup_pe - mum_px*mup_px - mum_py*mup_py - mum_pz*mup_pz))>60 && \
                         sqrt(mum_m*mum_m + mup_m*mup_m + 2*(mum_pe*mup_pe - mum_px*mup_px - mum_py*mup_py - mum_pz*mup_pz))<120";
TCut mu_trackprob_cut = "mum_probchi2>0.001&&mup_probchi2>0.001";

TCut Zboson_cuts   = mu_pt_cut+mu_eta_cut+mum_mup_mass_cut+mu_trackprob_cut;
TCut Zbosonmc_cuts = mu_pt_cut+mu_eta_cut+mum_mup_mass_cut;

// All analysis cuts
TCut diffsign_cut_mc     = "eq_charge==0"+jet_cuts+trackmc_cuts+topological_cuts+Zbosonmc_cuts;
TCut samesign_cut_mc     = "eq_charge==1"+jet_cuts+trackmc_cuts+topological_cuts+Zbosonmc_cuts;
TCut diffsign_cut_mcreco = "eq_charge==0"+jet_cuts+track_cuts  +topological_cuts+Zboson_cuts;
TCut samesign_cut_mcreco = "eq_charge==1"+jet_cuts+track_cuts  +topological_cuts+Zboson_cuts;
TCut diffsign_cut_data   = "eq_charge==0"+jet_cuts+track_cuts  +topological_cuts+Zboson_cuts;
TCut samesign_cut_data   = "eq_charge==1"+jet_cuts+track_cuts  +topological_cuts+Zboson_cuts;

// Visual constants
const double std_marker_size  = 1.3;
const int    std_marker_style = 8;
const int    std_line_width   = 3;

#endif