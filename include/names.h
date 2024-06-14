#ifndef NAMES_H
#define NAMES_H

// Naming convention : all folders must end with the backslash

// Names of the folders
std::string mother_folder = "/home/esteban/Documents/umich-work/lhcb/charge-correlation-ratio/";
std::string output_folder = mother_folder+"output-files/";
std::string input_folder  = mother_folder+"input-files/";

// Names of the files
std::string namef_rc_z_mc          = "rc_z_mc.root";
std::string namef_rc_z_mcreco      = "rc_z_mcreco.root";
std::string namef_rc_z_data        = "rc_z_data.root";
std::string namef_rc_z_data_p      = "rc_z_data_purity.root";
std::string namef_rc_z_data_d      = "rc_z_data_decays.root";
std::string namef_rc_kt_mc         = "rc_kt_mc.root";
std::string namef_rc_kt_mcreco     = "rc_kt_mcreco.root";
std::string namef_rc_kt_data       = "rc_kt_data.root";
std::string namef_rc_kt_data_p     = "rc_kt_data_purity.root";
std::string namef_rc_kt_data_d     = "rc_kt_data_decays.root";
std::string namef_rc_jet_pt_mc     = "rc_jet_pt_mc.root";
std::string namef_rc_jet_pt_mcreco = "rc_jet_pt_mcreco.root";
std::string namef_rc_jet_pt_data   = "rc_jet_pt_data.root";
std::string namef_rc_jet_pt_data_p = "rc_jet_pt_data_purity.root";
std::string namef_rc_jet_pt_data_d = "rc_jet_pt_data_decays.root";
std::string namef_ntuple_dihadron  = "ntuple_dihadron.root";
std::string namef_ntuple_purity    = "ntuple_purity.root";
std::string namef_ntuple_resolution= "ntuple_resolution.root";
std::string namef_ntuple_decays    = "ntuple_decays.root";

// Name of the ntuples
std::string name_ntuple_data       = "ntuple_data";
std::string name_ntuple_mc         = "ntuple_mc";
std::string name_ntuple_mcreco     = "ntuple_mcreco";
std::string name_ntuple_purity     = "ntuple_purity";
std::string name_ntuple_resolution = "ntuple_resolution";
std::string name_ntuple_decays     = "ntuple_decays";

// TNTuples variables
const int Nvars_mc         = 32; 
const int Nvars_mcreco     = 40; 
const int Nvars_data       = 41; 
const int Nvars_purity     = 39;
const int Nvars_resolution = 40;
const int Nvars_decays     = 19; 
const char* ntuple_mc_vars         = "eq_charge:lh_id:nlh_id:lh_p:nlh_p:lh_pt:nlh_pt:lh_z:nlh_z:dh_kt:lh_pz:nlh_pz:jet_pt:jet_eta:jet_phi:z0_phi:mum_phi:mum_pt:mum_eta:mum_px:mum_py:mum_pz:mum_pe:mum_m:mup_phi:mup_pt:mup_eta:mup_px:mup_py:mup_pz:mup_pe:mup_m";
const char* ntuple_mcreco_vars     = "eq_charge:lh_id:nlh_id:lh_chi2:nlh_chi2:lh_ndf:nlh_ndf:lh_probnnghost:nlh_probnnghost:lh_p:nlh_p:lh_pt:nlh_pt:lh_z:nlh_z:dh_kt:lh_pz:nlh_pz:jet_pt:jet_eta:jet_phi:z0_phi:mum_phi:mum_pt:mum_eta:mum_px:mum_py:mum_pz:mum_pe:mum_m:mum_probchi2:mup_phi:mup_pt:mup_eta:mup_px:mup_py:mup_pz:mup_pe:mup_m:mup_probchi2";
const char* ntuple_data_vars       = "eq_charge:dh_m:lh_id:nlh_id:lh_chi2:nlh_chi2:lh_ndf:nlh_ndf:lh_probnnghost:nlh_probnnghost:lh_p:nlh_p:lh_pt:nlh_pt:lh_z:nlh_z:dh_kt:lh_pz:nlh_pz:jet_pt:jet_eta:jet_phi:z0_phi:mum_phi:mum_pt:mum_eta:mum_px:mum_py:mum_pz:mum_pe:mum_m:mum_probchi2:mup_phi:mup_pt:mup_eta:mup_px:mup_py:mup_pz:mup_pe:mup_m:mup_probchi2";
const char* ntuple_purity_vars     = "eq_charge:signal:lh_chi2:nlh_chi2:lh_ndf:nlh_ndf:lh_probnnghost:nlh_probnnghost:lh_p:nlh_p:lh_pt:nlh_pt:lh_z:nlh_z:dh_kt:lh_pz:nlh_pz:jet_pt:jet_eta:jet_phi:z0_phi:mum_phi:mum_pt:mum_eta:mum_px:mum_py:mum_pz:mum_pe:mum_m:mum_probchi2:mup_phi:mup_pt:mup_eta:mup_px:mup_py:mup_pz:mup_pe:mup_m:mup_probchi2";
const char* ntuple_resolution_vars = "eq_charge:lh_chi2:nlh_chi2:lh_ndf:nlh_ndf:lh_probnnghost:nlh_probnnghost:lh_p:nlh_p:lh_pt:nlh_pt:dh_z_mcreco:dh_z_mc:dh_kt_mcreco:dh_kt_mc:lh_pz:nlh_pz:jet_pt_mcreco:jet_pt_mc:jet_eta:jet_phi:z0_phi:mum_phi:mum_pt:mum_eta:mum_px:mum_py:mum_pz:mum_pe:mum_m:mum_probchi2:mup_phi:mup_pt:mup_eta:mup_px:mup_py:mup_pz:mup_pe:mup_m:mup_probchi2";
const char* ntuple_decays_vars     = "eq_charge:lh_id:nlh_id:lh_motherid:nlh_motherid:lh_topmotherid:nlh_topmotherid:lh_p:nlh_p:lh_pt:nlh_pt:lh_z:nlh_z:dh_kt:lh_pz:nlh_pz:jet_pt:jet_eta:jet_phi";

#endif