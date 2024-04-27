//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Apr 26 23:53:44 2024 by ROOT version 6.26/10
// from TChain StdHltZJets/DecayTree/
//////////////////////////////////////////////////////////

#ifndef TZJetsData_h
#define TZJetsData_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class TZJetsData {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxZ0_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxZ0_OWNPV_COV = 1;
   static constexpr Int_t kMaxZ0_ORIVX_COV = 1;
   static constexpr Int_t kMaxmup_OWNPV_COV = 1;
   static constexpr Int_t kMaxmup_ORIVX_COV = 1;
   static constexpr Int_t kMaxmum_OWNPV_COV = 1;
   static constexpr Int_t kMaxmum_ORIVX_COV = 1;

   // Declaration of leaf types
   Double_t        H_10_MIPDV;
   Double_t        H_10_P;
   Double_t        H_10_PT;
   Double_t        H_10_PE;
   Double_t        H_10_PX;
   Double_t        H_10_PY;
   Double_t        H_10_PZ;
   Double_t        H_10_MM;
   Double_t        H_10_MMERR;
   Double_t        H_10_M;
   Int_t           H_10_ID;
   Double_t        Z0_MIPDV;
   Double_t        Z0_P;
   Double_t        Z0_PT;
   Double_t        Z0_PE;
   Double_t        Z0_PX;
   Double_t        Z0_PY;
   Double_t        Z0_PZ;
   Double_t        Z0_MM;
   Double_t        Z0_MMERR;
   Double_t        Z0_M;
   Int_t           Z0_ID;
   Int_t           Z0_AssociatedTracks_n_Tracks;
   Float_t         Z0_AssociatedTracks_PT[512];   //[Z0_AssociatedTracks_n_Tracks]
   Float_t         Z0_AssociatedTracks_PHI[512];   //[Z0_AssociatedTracks_n_Tracks]
   Float_t         Z0_AssociatedTracks_ETA[512];   //[Z0_AssociatedTracks_n_Tracks]
   Float_t         Z0_AssociatedTracks_VX[512];   //[Z0_AssociatedTracks_n_Tracks]
   Float_t         Z0_AssociatedTracks_VY[512];   //[Z0_AssociatedTracks_n_Tracks]
   Float_t         Z0_AssociatedTracks_VZ[512];   //[Z0_AssociatedTracks_n_Tracks]
   Float_t         Z0_AssociatedTracks_ProbChi2[512];   //[Z0_AssociatedTracks_n_Tracks]
   Float_t         Z0_AssociatedTracks_ProbGhost[512];   //[Z0_AssociatedTracks_n_Tracks]
   Float_t         Z0_AssociatedTracks_TrackType[512];   //[Z0_AssociatedTracks_n_Tracks]
   Float_t         Z0_AssociatedTracks_FirstState[512];   //[Z0_AssociatedTracks_n_Tracks]
   Double_t        Z0_ENDVERTEX_X;
   Double_t        Z0_ENDVERTEX_Y;
   Double_t        Z0_ENDVERTEX_Z;
   Double_t        Z0_ENDVERTEX_XERR;
   Double_t        Z0_ENDVERTEX_YERR;
   Double_t        Z0_ENDVERTEX_ZERR;
   Double_t        Z0_ENDVERTEX_CHI2;
   Int_t           Z0_ENDVERTEX_NDOF;
   Float_t         Z0_ENDVERTEX_COV_[3][3];
   Double_t        Z0_OWNPV_X;
   Double_t        Z0_OWNPV_Y;
   Double_t        Z0_OWNPV_Z;
   Double_t        Z0_OWNPV_XERR;
   Double_t        Z0_OWNPV_YERR;
   Double_t        Z0_OWNPV_ZERR;
   Double_t        Z0_OWNPV_CHI2;
   Int_t           Z0_OWNPV_NDOF;
   Float_t         Z0_OWNPV_COV_[3][3];
   Double_t        Z0_IP_OWNPV;
   Double_t        Z0_IPCHI2_OWNPV;
   Double_t        Z0_FD_OWNPV;
   Double_t        Z0_FDCHI2_OWNPV;
   Double_t        Z0_DIRA_OWNPV;
   Double_t        Z0_ORIVX_X;
   Double_t        Z0_ORIVX_Y;
   Double_t        Z0_ORIVX_Z;
   Double_t        Z0_ORIVX_XERR;
   Double_t        Z0_ORIVX_YERR;
   Double_t        Z0_ORIVX_ZERR;
   Double_t        Z0_ORIVX_CHI2;
   Int_t           Z0_ORIVX_NDOF;
   Float_t         Z0_ORIVX_COV_[3][3];
   Double_t        Z0_FD_ORIVX;
   Double_t        Z0_FDCHI2_ORIVX;
   Double_t        Z0_DIRA_ORIVX;
   Double_t        mup_MIPDV;
   Double_t        mup_P;
   Double_t        mup_PT;
   Double_t        mup_PE;
   Double_t        mup_PX;
   Double_t        mup_PY;
   Double_t        mup_PZ;
   Double_t        mup_M;
   Int_t           mup_ID;
   Double_t        mup_PIDe;
   Double_t        mup_PIDmu;
   Double_t        mup_PIDK;
   Double_t        mup_PIDp;
   Double_t        mup_PIDd;
   Double_t        mup_ProbNNe;
   Double_t        mup_ProbNNk;
   Double_t        mup_ProbNNp;
   Double_t        mup_ProbNNpi;
   Double_t        mup_ProbNNmu;
   Double_t        mup_ProbNNd;
   Double_t        mup_ProbNNghost;
   Bool_t          mup_hasMuon;
   Bool_t          mup_isMuon;
   Bool_t          mup_hasRich;
   Bool_t          mup_UsedRichAerogel;
   Bool_t          mup_UsedRich1Gas;
   Bool_t          mup_UsedRich2Gas;
   Bool_t          mup_RichAboveElThres;
   Bool_t          mup_RichAboveMuThres;
   Bool_t          mup_RichAbovePiThres;
   Bool_t          mup_RichAboveKaThres;
   Bool_t          mup_RichAbovePrThres;
   Bool_t          mup_hasCalo;
   Double_t        mup_OWNPV_X;
   Double_t        mup_OWNPV_Y;
   Double_t        mup_OWNPV_Z;
   Double_t        mup_OWNPV_XERR;
   Double_t        mup_OWNPV_YERR;
   Double_t        mup_OWNPV_ZERR;
   Double_t        mup_OWNPV_CHI2;
   Int_t           mup_OWNPV_NDOF;
   Float_t         mup_OWNPV_COV_[3][3];
   Double_t        mup_IP_OWNPV;
   Double_t        mup_IPCHI2_OWNPV;
   Double_t        mup_ORIVX_X;
   Double_t        mup_ORIVX_Y;
   Double_t        mup_ORIVX_Z;
   Double_t        mup_ORIVX_XERR;
   Double_t        mup_ORIVX_YERR;
   Double_t        mup_ORIVX_ZERR;
   Double_t        mup_ORIVX_CHI2;
   Int_t           mup_ORIVX_NDOF;
   Float_t         mup_ORIVX_COV_[3][3];
   Bool_t          mup_L0Global_Dec;
   Bool_t          mup_L0Global_TIS;
   Bool_t          mup_L0Global_TOS;
   Bool_t          mup_Hlt1Global_Dec;
   Bool_t          mup_Hlt1Global_TIS;
   Bool_t          mup_Hlt1Global_TOS;
   Bool_t          mup_Hlt1Phys_Dec;
   Bool_t          mup_Hlt1Phys_TIS;
   Bool_t          mup_Hlt1Phys_TOS;
   Bool_t          mup_Hlt2Global_Dec;
   Bool_t          mup_Hlt2Global_TIS;
   Bool_t          mup_Hlt2Global_TOS;
   Bool_t          mup_Hlt2Phys_Dec;
   Bool_t          mup_Hlt2Phys_TIS;
   Bool_t          mup_Hlt2Phys_TOS;
   Bool_t          mup_L0MuonDecision_Dec;
   Bool_t          mup_L0MuonDecision_TIS;
   Bool_t          mup_L0MuonDecision_TOS;
   Bool_t          mup_L0MuonEWDecision_Dec;
   Bool_t          mup_L0MuonEWDecision_TIS;
   Bool_t          mup_L0MuonEWDecision_TOS;
   Bool_t          mup_L0DiMuonDecision_Dec;
   Bool_t          mup_L0DiMuonDecision_TIS;
   Bool_t          mup_L0DiMuonDecision_TOS;
   Bool_t          mup_Hlt1SingleMuonHighPTDecision_Dec;
   Bool_t          mup_Hlt1SingleMuonHighPTDecision_TIS;
   Bool_t          mup_Hlt1SingleMuonHighPTDecision_TOS;
   Bool_t          mup_Hlt2SingleMuonDecision_Dec;
   Bool_t          mup_Hlt2SingleMuonDecision_TIS;
   Bool_t          mup_Hlt2SingleMuonDecision_TOS;
   Bool_t          mup_Hlt2SingleMuonLowPTDecision_Dec;
   Bool_t          mup_Hlt2SingleMuonLowPTDecision_TIS;
   Bool_t          mup_Hlt2SingleMuonLowPTDecision_TOS;
   Bool_t          mup_Hlt2SingleMuonHighPTDecision_Dec;
   Bool_t          mup_Hlt2SingleMuonHighPTDecision_TIS;
   Bool_t          mup_Hlt2SingleMuonHighPTDecision_TOS;
   Bool_t          mup_Hlt2EWSingleMuonHighPtDecision_Dec;
   Bool_t          mup_Hlt2EWSingleMuonHighPtDecision_TIS;
   Bool_t          mup_Hlt2EWSingleMuonHighPtDecision_TOS;
   Bool_t          mup_Hlt2EWSingleMuonVHighPtDecision_Dec;
   Bool_t          mup_Hlt2EWSingleMuonVHighPtDecision_TIS;
   Bool_t          mup_Hlt2EWSingleMuonVHighPtDecision_TOS;
   Int_t           mup_TRACK_Type;
   Int_t           mup_TRACK_Key;
   Double_t        mup_TRACK_CHI2NDOF;
   Double_t        mup_TRACK_PCHI2;
   Double_t        mup_TRACK_MatchCHI2;
   Double_t        mup_TRACK_GhostProb;
   Double_t        mup_TRACK_CloneDist;
   Double_t        mup_TRACK_Likelihood;
   Double_t        mum_MIPDV;
   Double_t        mum_P;
   Double_t        mum_PT;
   Double_t        mum_PE;
   Double_t        mum_PX;
   Double_t        mum_PY;
   Double_t        mum_PZ;
   Double_t        mum_M;
   Int_t           mum_ID;
   Double_t        mum_PIDe;
   Double_t        mum_PIDmu;
   Double_t        mum_PIDK;
   Double_t        mum_PIDp;
   Double_t        mum_PIDd;
   Double_t        mum_ProbNNe;
   Double_t        mum_ProbNNk;
   Double_t        mum_ProbNNp;
   Double_t        mum_ProbNNpi;
   Double_t        mum_ProbNNmu;
   Double_t        mum_ProbNNd;
   Double_t        mum_ProbNNghost;
   Bool_t          mum_hasMuon;
   Bool_t          mum_isMuon;
   Bool_t          mum_hasRich;
   Bool_t          mum_UsedRichAerogel;
   Bool_t          mum_UsedRich1Gas;
   Bool_t          mum_UsedRich2Gas;
   Bool_t          mum_RichAboveElThres;
   Bool_t          mum_RichAboveMuThres;
   Bool_t          mum_RichAbovePiThres;
   Bool_t          mum_RichAboveKaThres;
   Bool_t          mum_RichAbovePrThres;
   Bool_t          mum_hasCalo;
   Double_t        mum_OWNPV_X;
   Double_t        mum_OWNPV_Y;
   Double_t        mum_OWNPV_Z;
   Double_t        mum_OWNPV_XERR;
   Double_t        mum_OWNPV_YERR;
   Double_t        mum_OWNPV_ZERR;
   Double_t        mum_OWNPV_CHI2;
   Int_t           mum_OWNPV_NDOF;
   Float_t         mum_OWNPV_COV_[3][3];
   Double_t        mum_IP_OWNPV;
   Double_t        mum_IPCHI2_OWNPV;
   Double_t        mum_ORIVX_X;
   Double_t        mum_ORIVX_Y;
   Double_t        mum_ORIVX_Z;
   Double_t        mum_ORIVX_XERR;
   Double_t        mum_ORIVX_YERR;
   Double_t        mum_ORIVX_ZERR;
   Double_t        mum_ORIVX_CHI2;
   Int_t           mum_ORIVX_NDOF;
   Float_t         mum_ORIVX_COV_[3][3];
   Bool_t          mum_L0Global_Dec;
   Bool_t          mum_L0Global_TIS;
   Bool_t          mum_L0Global_TOS;
   Bool_t          mum_Hlt1Global_Dec;
   Bool_t          mum_Hlt1Global_TIS;
   Bool_t          mum_Hlt1Global_TOS;
   Bool_t          mum_Hlt1Phys_Dec;
   Bool_t          mum_Hlt1Phys_TIS;
   Bool_t          mum_Hlt1Phys_TOS;
   Bool_t          mum_Hlt2Global_Dec;
   Bool_t          mum_Hlt2Global_TIS;
   Bool_t          mum_Hlt2Global_TOS;
   Bool_t          mum_Hlt2Phys_Dec;
   Bool_t          mum_Hlt2Phys_TIS;
   Bool_t          mum_Hlt2Phys_TOS;
   Bool_t          mum_L0MuonDecision_Dec;
   Bool_t          mum_L0MuonDecision_TIS;
   Bool_t          mum_L0MuonDecision_TOS;
   Bool_t          mum_L0MuonEWDecision_Dec;
   Bool_t          mum_L0MuonEWDecision_TIS;
   Bool_t          mum_L0MuonEWDecision_TOS;
   Bool_t          mum_L0DiMuonDecision_Dec;
   Bool_t          mum_L0DiMuonDecision_TIS;
   Bool_t          mum_L0DiMuonDecision_TOS;
   Bool_t          mum_Hlt1SingleMuonHighPTDecision_Dec;
   Bool_t          mum_Hlt1SingleMuonHighPTDecision_TIS;
   Bool_t          mum_Hlt1SingleMuonHighPTDecision_TOS;
   Bool_t          mum_Hlt2SingleMuonDecision_Dec;
   Bool_t          mum_Hlt2SingleMuonDecision_TIS;
   Bool_t          mum_Hlt2SingleMuonDecision_TOS;
   Bool_t          mum_Hlt2SingleMuonLowPTDecision_Dec;
   Bool_t          mum_Hlt2SingleMuonLowPTDecision_TIS;
   Bool_t          mum_Hlt2SingleMuonLowPTDecision_TOS;
   Bool_t          mum_Hlt2SingleMuonHighPTDecision_Dec;
   Bool_t          mum_Hlt2SingleMuonHighPTDecision_TIS;
   Bool_t          mum_Hlt2SingleMuonHighPTDecision_TOS;
   Bool_t          mum_Hlt2EWSingleMuonHighPtDecision_Dec;
   Bool_t          mum_Hlt2EWSingleMuonHighPtDecision_TIS;
   Bool_t          mum_Hlt2EWSingleMuonHighPtDecision_TOS;
   Bool_t          mum_Hlt2EWSingleMuonVHighPtDecision_Dec;
   Bool_t          mum_Hlt2EWSingleMuonVHighPtDecision_TIS;
   Bool_t          mum_Hlt2EWSingleMuonVHighPtDecision_TOS;
   Int_t           mum_TRACK_Type;
   Int_t           mum_TRACK_Key;
   Double_t        mum_TRACK_CHI2NDOF;
   Double_t        mum_TRACK_PCHI2;
   Double_t        mum_TRACK_MatchCHI2;
   Double_t        mum_TRACK_GhostProb;
   Double_t        mum_TRACK_CloneDist;
   Double_t        mum_TRACK_Likelihood;
   Double_t        Jet_MIPDV;
   Double_t        Jet_P;
   Double_t        Jet_PT;
   Double_t        Jet_PE;
   Double_t        Jet_PX;
   Double_t        Jet_PY;
   Double_t        Jet_PZ;
   Double_t        Jet_MM;
   Double_t        Jet_MMERR;
   Double_t        Jet_M;
   Int_t           Jet_ID;
   Int_t           Jet_Dtr_nrecodtr;
   Double_t        jet_XVTX;
   Double_t        jet_YVTX;
   Double_t        jet_ZVTX;
   Int_t           Jet_NDtr;
   Float_t         Jet_Dtr_IP[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_IPCHI2[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_ID[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_ThreeCharge[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_IsMeson[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_IsBaryon[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_IsStrange[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PIDe[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PIDmu[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PIDk[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PIDp[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PIDpi[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_ProbNNe[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_ProbNNmu[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_ProbNNk[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_ProbNNp[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_ProbNNpi[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_ProbNNghost[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PX[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PY[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PZ[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_E[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_P[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PT[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_M[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PHI[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_ETA[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_XVTX[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_YVTX[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_ZVTX[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_R[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_JT[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_Z[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TrackType[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TrackKey[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TrackChi2[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TrackNDF[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TrackPCHI2[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PFType[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PFDaughterType[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PFclustype[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_PFclusE[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_KEY[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_ID[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_ThreeCharge[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_IsMeson[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_IsBaryon[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_IsStrange[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_PX[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_PY[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_PZ[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_E[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_P[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_PT[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_M[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_PHI[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_ETA[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_XVTX[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_YVTX[1024];   //[Jet_NDtr]
   Float_t         Jet_Dtr_TRUE_ZVTX[1024];   //[Jet_NDtr]
   UInt_t          nCandidate;
   ULong64_t       totCandidates;
   ULong64_t       EventInSequence;
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   UInt_t          BCID;
   Int_t           BCType;
   UInt_t          OdinTCK;
   UInt_t          L0DUTCK;
   UInt_t          HLT1TCK;
   UInt_t          HLT2TCK;
   ULong64_t       GpsTime;
   Short_t         Polarity;
   Int_t           nPV;
   Float_t         PVX[100];   //[nPV]
   Float_t         PVY[100];   //[nPV]
   Float_t         PVZ[100];   //[nPV]
   Float_t         PVXERR[100];   //[nPV]
   Float_t         PVYERR[100];   //[nPV]
   Float_t         PVZERR[100];   //[nPV]
   Float_t         PVCHI2[100];   //[nPV]
   Float_t         PVNDOF[100];   //[nPV]
   Float_t         PVNTRACKS[100];   //[nPV]
   Int_t           nPVs;
   Int_t           nTracks;
   Int_t           nLongTracks;
   Int_t           nDownstreamTracks;
   Int_t           nUpstreamTracks;
   Int_t           nVeloTracks;
   Int_t           nTTracks;
   Int_t           nBackTracks;
   Int_t           nRich1Hits;
   Int_t           nRich2Hits;
   Int_t           nVeloClusters;
   Int_t           nITClusters;
   Int_t           nTTClusters;
   Int_t           nOTClusters;
   Int_t           nSPDHits;
   Int_t           nMuonCoordsS0;
   Int_t           nMuonCoordsS1;
   Int_t           nMuonCoordsS2;
   Int_t           nMuonCoordsS3;
   Int_t           nMuonCoordsS4;
   Int_t           nMuonTracks;
   UInt_t          StrippingZ02MuMuLineDecision;

   // List of branches
   TBranch        *b_H_10_MIPDV;   //!
   TBranch        *b_H_10_P;   //!
   TBranch        *b_H_10_PT;   //!
   TBranch        *b_H_10_PE;   //!
   TBranch        *b_H_10_PX;   //!
   TBranch        *b_H_10_PY;   //!
   TBranch        *b_H_10_PZ;   //!
   TBranch        *b_H_10_MM;   //!
   TBranch        *b_H_10_MMERR;   //!
   TBranch        *b_H_10_M;   //!
   TBranch        *b_H_10_ID;   //!
   TBranch        *b_Z0_MIPDV;   //!
   TBranch        *b_Z0_P;   //!
   TBranch        *b_Z0_PT;   //!
   TBranch        *b_Z0_PE;   //!
   TBranch        *b_Z0_PX;   //!
   TBranch        *b_Z0_PY;   //!
   TBranch        *b_Z0_PZ;   //!
   TBranch        *b_Z0_MM;   //!
   TBranch        *b_Z0_MMERR;   //!
   TBranch        *b_Z0_M;   //!
   TBranch        *b_Z0_ID;   //!
   TBranch        *b_Z0_AssociatedTracks_n_Tracks;   //!
   TBranch        *b_Z0_AssociatedTracks_PT;   //!
   TBranch        *b_Z0_AssociatedTracks_PHI;   //!
   TBranch        *b_Z0_AssociatedTracks_ETA;   //!
   TBranch        *b_Z0_AssociatedTracks_VX;   //!
   TBranch        *b_Z0_AssociatedTracks_VY;   //!
   TBranch        *b_Z0_AssociatedTracks_VZ;   //!
   TBranch        *b_Z0_AssociatedTracks_ProbChi2;   //!
   TBranch        *b_Z0_AssociatedTracks_ProbGhost;   //!
   TBranch        *b_Z0_AssociatedTracks_TrackType;   //!
   TBranch        *b_Z0_AssociatedTracks_FirstState;   //!
   TBranch        *b_Z0_ENDVERTEX_X;   //!
   TBranch        *b_Z0_ENDVERTEX_Y;   //!
   TBranch        *b_Z0_ENDVERTEX_Z;   //!
   TBranch        *b_Z0_ENDVERTEX_XERR;   //!
   TBranch        *b_Z0_ENDVERTEX_YERR;   //!
   TBranch        *b_Z0_ENDVERTEX_ZERR;   //!
   TBranch        *b_Z0_ENDVERTEX_CHI2;   //!
   TBranch        *b_Z0_ENDVERTEX_NDOF;   //!
   TBranch        *b_Z0_ENDVERTEX_COV_;   //!
   TBranch        *b_Z0_OWNPV_X;   //!
   TBranch        *b_Z0_OWNPV_Y;   //!
   TBranch        *b_Z0_OWNPV_Z;   //!
   TBranch        *b_Z0_OWNPV_XERR;   //!
   TBranch        *b_Z0_OWNPV_YERR;   //!
   TBranch        *b_Z0_OWNPV_ZERR;   //!
   TBranch        *b_Z0_OWNPV_CHI2;   //!
   TBranch        *b_Z0_OWNPV_NDOF;   //!
   TBranch        *b_Z0_OWNPV_COV_;   //!
   TBranch        *b_Z0_IP_OWNPV;   //!
   TBranch        *b_Z0_IPCHI2_OWNPV;   //!
   TBranch        *b_Z0_FD_OWNPV;   //!
   TBranch        *b_Z0_FDCHI2_OWNPV;   //!
   TBranch        *b_Z0_DIRA_OWNPV;   //!
   TBranch        *b_Z0_ORIVX_X;   //!
   TBranch        *b_Z0_ORIVX_Y;   //!
   TBranch        *b_Z0_ORIVX_Z;   //!
   TBranch        *b_Z0_ORIVX_XERR;   //!
   TBranch        *b_Z0_ORIVX_YERR;   //!
   TBranch        *b_Z0_ORIVX_ZERR;   //!
   TBranch        *b_Z0_ORIVX_CHI2;   //!
   TBranch        *b_Z0_ORIVX_NDOF;   //!
   TBranch        *b_Z0_ORIVX_COV_;   //!
   TBranch        *b_Z0_FD_ORIVX;   //!
   TBranch        *b_Z0_FDCHI2_ORIVX;   //!
   TBranch        *b_Z0_DIRA_ORIVX;   //!
   TBranch        *b_mup_MIPDV;   //!
   TBranch        *b_mup_P;   //!
   TBranch        *b_mup_PT;   //!
   TBranch        *b_mup_PE;   //!
   TBranch        *b_mup_PX;   //!
   TBranch        *b_mup_PY;   //!
   TBranch        *b_mup_PZ;   //!
   TBranch        *b_mup_M;   //!
   TBranch        *b_mup_ID;   //!
   TBranch        *b_mup_PIDe;   //!
   TBranch        *b_mup_PIDmu;   //!
   TBranch        *b_mup_PIDK;   //!
   TBranch        *b_mup_PIDp;   //!
   TBranch        *b_mup_PIDd;   //!
   TBranch        *b_mup_ProbNNe;   //!
   TBranch        *b_mup_ProbNNk;   //!
   TBranch        *b_mup_ProbNNp;   //!
   TBranch        *b_mup_ProbNNpi;   //!
   TBranch        *b_mup_ProbNNmu;   //!
   TBranch        *b_mup_ProbNNd;   //!
   TBranch        *b_mup_ProbNNghost;   //!
   TBranch        *b_mup_hasMuon;   //!
   TBranch        *b_mup_isMuon;   //!
   TBranch        *b_mup_hasRich;   //!
   TBranch        *b_mup_UsedRichAerogel;   //!
   TBranch        *b_mup_UsedRich1Gas;   //!
   TBranch        *b_mup_UsedRich2Gas;   //!
   TBranch        *b_mup_RichAboveElThres;   //!
   TBranch        *b_mup_RichAboveMuThres;   //!
   TBranch        *b_mup_RichAbovePiThres;   //!
   TBranch        *b_mup_RichAboveKaThres;   //!
   TBranch        *b_mup_RichAbovePrThres;   //!
   TBranch        *b_mup_hasCalo;   //!
   TBranch        *b_mup_OWNPV_X;   //!
   TBranch        *b_mup_OWNPV_Y;   //!
   TBranch        *b_mup_OWNPV_Z;   //!
   TBranch        *b_mup_OWNPV_XERR;   //!
   TBranch        *b_mup_OWNPV_YERR;   //!
   TBranch        *b_mup_OWNPV_ZERR;   //!
   TBranch        *b_mup_OWNPV_CHI2;   //!
   TBranch        *b_mup_OWNPV_NDOF;   //!
   TBranch        *b_mup_OWNPV_COV_;   //!
   TBranch        *b_mup_IP_OWNPV;   //!
   TBranch        *b_mup_IPCHI2_OWNPV;   //!
   TBranch        *b_mup_ORIVX_X;   //!
   TBranch        *b_mup_ORIVX_Y;   //!
   TBranch        *b_mup_ORIVX_Z;   //!
   TBranch        *b_mup_ORIVX_XERR;   //!
   TBranch        *b_mup_ORIVX_YERR;   //!
   TBranch        *b_mup_ORIVX_ZERR;   //!
   TBranch        *b_mup_ORIVX_CHI2;   //!
   TBranch        *b_mup_ORIVX_NDOF;   //!
   TBranch        *b_mup_ORIVX_COV_;   //!
   TBranch        *b_mup_L0Global_Dec;   //!
   TBranch        *b_mup_L0Global_TIS;   //!
   TBranch        *b_mup_L0Global_TOS;   //!
   TBranch        *b_mup_Hlt1Global_Dec;   //!
   TBranch        *b_mup_Hlt1Global_TIS;   //!
   TBranch        *b_mup_Hlt1Global_TOS;   //!
   TBranch        *b_mup_Hlt1Phys_Dec;   //!
   TBranch        *b_mup_Hlt1Phys_TIS;   //!
   TBranch        *b_mup_Hlt1Phys_TOS;   //!
   TBranch        *b_mup_Hlt2Global_Dec;   //!
   TBranch        *b_mup_Hlt2Global_TIS;   //!
   TBranch        *b_mup_Hlt2Global_TOS;   //!
   TBranch        *b_mup_Hlt2Phys_Dec;   //!
   TBranch        *b_mup_Hlt2Phys_TIS;   //!
   TBranch        *b_mup_Hlt2Phys_TOS;   //!
   TBranch        *b_mup_L0MuonDecision_Dec;   //!
   TBranch        *b_mup_L0MuonDecision_TIS;   //!
   TBranch        *b_mup_L0MuonDecision_TOS;   //!
   TBranch        *b_mup_L0MuonEWDecision_Dec;   //!
   TBranch        *b_mup_L0MuonEWDecision_TIS;   //!
   TBranch        *b_mup_L0MuonEWDecision_TOS;   //!
   TBranch        *b_mup_L0DiMuonDecision_Dec;   //!
   TBranch        *b_mup_L0DiMuonDecision_TIS;   //!
   TBranch        *b_mup_L0DiMuonDecision_TOS;   //!
   TBranch        *b_mup_Hlt1SingleMuonHighPTDecision_Dec;   //!
   TBranch        *b_mup_Hlt1SingleMuonHighPTDecision_TIS;   //!
   TBranch        *b_mup_Hlt1SingleMuonHighPTDecision_TOS;   //!
   TBranch        *b_mup_Hlt2SingleMuonDecision_Dec;   //!
   TBranch        *b_mup_Hlt2SingleMuonDecision_TIS;   //!
   TBranch        *b_mup_Hlt2SingleMuonDecision_TOS;   //!
   TBranch        *b_mup_Hlt2SingleMuonLowPTDecision_Dec;   //!
   TBranch        *b_mup_Hlt2SingleMuonLowPTDecision_TIS;   //!
   TBranch        *b_mup_Hlt2SingleMuonLowPTDecision_TOS;   //!
   TBranch        *b_mup_Hlt2SingleMuonHighPTDecision_Dec;   //!
   TBranch        *b_mup_Hlt2SingleMuonHighPTDecision_TIS;   //!
   TBranch        *b_mup_Hlt2SingleMuonHighPTDecision_TOS;   //!
   TBranch        *b_mup_Hlt2EWSingleMuonHighPtDecision_Dec;   //!
   TBranch        *b_mup_Hlt2EWSingleMuonHighPtDecision_TIS;   //!
   TBranch        *b_mup_Hlt2EWSingleMuonHighPtDecision_TOS;   //!
   TBranch        *b_mup_Hlt2EWSingleMuonVHighPtDecision_Dec;   //!
   TBranch        *b_mup_Hlt2EWSingleMuonVHighPtDecision_TIS;   //!
   TBranch        *b_mup_Hlt2EWSingleMuonVHighPtDecision_TOS;   //!
   TBranch        *b_mup_TRACK_Type;   //!
   TBranch        *b_mup_TRACK_Key;   //!
   TBranch        *b_mup_TRACK_CHI2NDOF;   //!
   TBranch        *b_mup_TRACK_PCHI2;   //!
   TBranch        *b_mup_TRACK_MatchCHI2;   //!
   TBranch        *b_mup_TRACK_GhostProb;   //!
   TBranch        *b_mup_TRACK_CloneDist;   //!
   TBranch        *b_mup_TRACK_Likelihood;   //!
   TBranch        *b_mum_MIPDV;   //!
   TBranch        *b_mum_P;   //!
   TBranch        *b_mum_PT;   //!
   TBranch        *b_mum_PE;   //!
   TBranch        *b_mum_PX;   //!
   TBranch        *b_mum_PY;   //!
   TBranch        *b_mum_PZ;   //!
   TBranch        *b_mum_M;   //!
   TBranch        *b_mum_ID;   //!
   TBranch        *b_mum_PIDe;   //!
   TBranch        *b_mum_PIDmu;   //!
   TBranch        *b_mum_PIDK;   //!
   TBranch        *b_mum_PIDp;   //!
   TBranch        *b_mum_PIDd;   //!
   TBranch        *b_mum_ProbNNe;   //!
   TBranch        *b_mum_ProbNNk;   //!
   TBranch        *b_mum_ProbNNp;   //!
   TBranch        *b_mum_ProbNNpi;   //!
   TBranch        *b_mum_ProbNNmu;   //!
   TBranch        *b_mum_ProbNNd;   //!
   TBranch        *b_mum_ProbNNghost;   //!
   TBranch        *b_mum_hasMuon;   //!
   TBranch        *b_mum_isMuon;   //!
   TBranch        *b_mum_hasRich;   //!
   TBranch        *b_mum_UsedRichAerogel;   //!
   TBranch        *b_mum_UsedRich1Gas;   //!
   TBranch        *b_mum_UsedRich2Gas;   //!
   TBranch        *b_mum_RichAboveElThres;   //!
   TBranch        *b_mum_RichAboveMuThres;   //!
   TBranch        *b_mum_RichAbovePiThres;   //!
   TBranch        *b_mum_RichAboveKaThres;   //!
   TBranch        *b_mum_RichAbovePrThres;   //!
   TBranch        *b_mum_hasCalo;   //!
   TBranch        *b_mum_OWNPV_X;   //!
   TBranch        *b_mum_OWNPV_Y;   //!
   TBranch        *b_mum_OWNPV_Z;   //!
   TBranch        *b_mum_OWNPV_XERR;   //!
   TBranch        *b_mum_OWNPV_YERR;   //!
   TBranch        *b_mum_OWNPV_ZERR;   //!
   TBranch        *b_mum_OWNPV_CHI2;   //!
   TBranch        *b_mum_OWNPV_NDOF;   //!
   TBranch        *b_mum_OWNPV_COV_;   //!
   TBranch        *b_mum_IP_OWNPV;   //!
   TBranch        *b_mum_IPCHI2_OWNPV;   //!
   TBranch        *b_mum_ORIVX_X;   //!
   TBranch        *b_mum_ORIVX_Y;   //!
   TBranch        *b_mum_ORIVX_Z;   //!
   TBranch        *b_mum_ORIVX_XERR;   //!
   TBranch        *b_mum_ORIVX_YERR;   //!
   TBranch        *b_mum_ORIVX_ZERR;   //!
   TBranch        *b_mum_ORIVX_CHI2;   //!
   TBranch        *b_mum_ORIVX_NDOF;   //!
   TBranch        *b_mum_ORIVX_COV_;   //!
   TBranch        *b_mum_L0Global_Dec;   //!
   TBranch        *b_mum_L0Global_TIS;   //!
   TBranch        *b_mum_L0Global_TOS;   //!
   TBranch        *b_mum_Hlt1Global_Dec;   //!
   TBranch        *b_mum_Hlt1Global_TIS;   //!
   TBranch        *b_mum_Hlt1Global_TOS;   //!
   TBranch        *b_mum_Hlt1Phys_Dec;   //!
   TBranch        *b_mum_Hlt1Phys_TIS;   //!
   TBranch        *b_mum_Hlt1Phys_TOS;   //!
   TBranch        *b_mum_Hlt2Global_Dec;   //!
   TBranch        *b_mum_Hlt2Global_TIS;   //!
   TBranch        *b_mum_Hlt2Global_TOS;   //!
   TBranch        *b_mum_Hlt2Phys_Dec;   //!
   TBranch        *b_mum_Hlt2Phys_TIS;   //!
   TBranch        *b_mum_Hlt2Phys_TOS;   //!
   TBranch        *b_mum_L0MuonDecision_Dec;   //!
   TBranch        *b_mum_L0MuonDecision_TIS;   //!
   TBranch        *b_mum_L0MuonDecision_TOS;   //!
   TBranch        *b_mum_L0MuonEWDecision_Dec;   //!
   TBranch        *b_mum_L0MuonEWDecision_TIS;   //!
   TBranch        *b_mum_L0MuonEWDecision_TOS;   //!
   TBranch        *b_mum_L0DiMuonDecision_Dec;   //!
   TBranch        *b_mum_L0DiMuonDecision_TIS;   //!
   TBranch        *b_mum_L0DiMuonDecision_TOS;   //!
   TBranch        *b_mum_Hlt1SingleMuonHighPTDecision_Dec;   //!
   TBranch        *b_mum_Hlt1SingleMuonHighPTDecision_TIS;   //!
   TBranch        *b_mum_Hlt1SingleMuonHighPTDecision_TOS;   //!
   TBranch        *b_mum_Hlt2SingleMuonDecision_Dec;   //!
   TBranch        *b_mum_Hlt2SingleMuonDecision_TIS;   //!
   TBranch        *b_mum_Hlt2SingleMuonDecision_TOS;   //!
   TBranch        *b_mum_Hlt2SingleMuonLowPTDecision_Dec;   //!
   TBranch        *b_mum_Hlt2SingleMuonLowPTDecision_TIS;   //!
   TBranch        *b_mum_Hlt2SingleMuonLowPTDecision_TOS;   //!
   TBranch        *b_mum_Hlt2SingleMuonHighPTDecision_Dec;   //!
   TBranch        *b_mum_Hlt2SingleMuonHighPTDecision_TIS;   //!
   TBranch        *b_mum_Hlt2SingleMuonHighPTDecision_TOS;   //!
   TBranch        *b_mum_Hlt2EWSingleMuonHighPtDecision_Dec;   //!
   TBranch        *b_mum_Hlt2EWSingleMuonHighPtDecision_TIS;   //!
   TBranch        *b_mum_Hlt2EWSingleMuonHighPtDecision_TOS;   //!
   TBranch        *b_mum_Hlt2EWSingleMuonVHighPtDecision_Dec;   //!
   TBranch        *b_mum_Hlt2EWSingleMuonVHighPtDecision_TIS;   //!
   TBranch        *b_mum_Hlt2EWSingleMuonVHighPtDecision_TOS;   //!
   TBranch        *b_mum_TRACK_Type;   //!
   TBranch        *b_mum_TRACK_Key;   //!
   TBranch        *b_mum_TRACK_CHI2NDOF;   //!
   TBranch        *b_mum_TRACK_PCHI2;   //!
   TBranch        *b_mum_TRACK_MatchCHI2;   //!
   TBranch        *b_mum_TRACK_GhostProb;   //!
   TBranch        *b_mum_TRACK_CloneDist;   //!
   TBranch        *b_mum_TRACK_Likelihood;   //!
   TBranch        *b_Jet_MIPDV;   //!
   TBranch        *b_Jet_P;   //!
   TBranch        *b_Jet_PT;   //!
   TBranch        *b_Jet_PE;   //!
   TBranch        *b_Jet_PX;   //!
   TBranch        *b_Jet_PY;   //!
   TBranch        *b_Jet_PZ;   //!
   TBranch        *b_Jet_MM;   //!
   TBranch        *b_Jet_MMERR;   //!
   TBranch        *b_Jet_M;   //!
   TBranch        *b_Jet_ID;   //!
   TBranch        *b_Jet_Dtr_nrecodtr;   //!
   TBranch        *b_jet_XVTX;   //!
   TBranch        *b_jet_YVTX;   //!
   TBranch        *b_jet_ZVTX;   //!
   TBranch        *b_Jet_NDtr;   //!
   TBranch        *b_Jet_Dtr_IP;   //!
   TBranch        *b_Jet_Dtr_IPCHI2;   //!
   TBranch        *b_Jet_Dtr_ID;   //!
   TBranch        *b_Jet_Dtr_ThreeCharge;   //!
   TBranch        *b_Jet_Dtr_IsMeson;   //!
   TBranch        *b_Jet_Dtr_IsBaryon;   //!
   TBranch        *b_Jet_Dtr_IsStrange;   //!
   TBranch        *b_Jet_Dtr_PIDe;   //!
   TBranch        *b_Jet_Dtr_PIDmu;   //!
   TBranch        *b_Jet_Dtr_PIDk;   //!
   TBranch        *b_Jet_Dtr_PIDp;   //!
   TBranch        *b_Jet_Dtr_PIDpi;   //!
   TBranch        *b_Jet_Dtr_ProbNNe;   //!
   TBranch        *b_Jet_Dtr_ProbNNmu;   //!
   TBranch        *b_Jet_Dtr_ProbNNk;   //!
   TBranch        *b_Jet_Dtr_ProbNNp;   //!
   TBranch        *b_Jet_Dtr_ProbNNpi;   //!
   TBranch        *b_Jet_Dtr_ProbNNghost;   //!
   TBranch        *b_Jet_Dtr_PX;   //!
   TBranch        *b_Jet_Dtr_PY;   //!
   TBranch        *b_Jet_Dtr_PZ;   //!
   TBranch        *b_Jet_Dtr_E;   //!
   TBranch        *b_Jet_Dtr_P;   //!
   TBranch        *b_Jet_Dtr_PT;   //!
   TBranch        *b_Jet_Dtr_M;   //!
   TBranch        *b_Jet_Dtr_PHI;   //!
   TBranch        *b_Jet_Dtr_ETA;   //!
   TBranch        *b_Jet_Dtr_XVTX;   //!
   TBranch        *b_Jet_Dtr_YVTX;   //!
   TBranch        *b_Jet_Dtr_ZVTX;   //!
   TBranch        *b_Jet_Dtr_R;   //!
   TBranch        *b_Jet_Dtr_JT;   //!
   TBranch        *b_Jet_Dtr_Z;   //!
   TBranch        *b_Jet_Dtr_TrackType;   //!
   TBranch        *b_Jet_Dtr_TrackKey;   //!
   TBranch        *b_Jet_Dtr_TrackChi2;   //!
   TBranch        *b_Jet_Dtr_TrackNDF;   //!
   TBranch        *b_Jet_Dtr_TrackPCHI2;   //!
   TBranch        *b_Jet_Dtr_PFType;   //!
   TBranch        *b_Jet_Dtr_PFDaughterType;   //!
   TBranch        *b_Jet_Dtr_PFclustype;   //!
   TBranch        *b_Jet_Dtr_PFclusE;   //!
   TBranch        *b_Jet_Dtr_TRUE_KEY;   //!
   TBranch        *b_Jet_Dtr_TRUE_ID;   //!
   TBranch        *b_Jet_Dtr_TRUE_ThreeCharge;   //!
   TBranch        *b_Jet_Dtr_TRUE_IsMeson;   //!
   TBranch        *b_Jet_Dtr_TRUE_IsBaryon;   //!
   TBranch        *b_Jet_Dtr_TRUE_IsStrange;   //!
   TBranch        *b_Jet_Dtr_TRUE_PX;   //!
   TBranch        *b_Jet_Dtr_TRUE_PY;   //!
   TBranch        *b_Jet_Dtr_TRUE_PZ;   //!
   TBranch        *b_Jet_Dtr_TRUE_E;   //!
   TBranch        *b_Jet_Dtr_TRUE_P;   //!
   TBranch        *b_Jet_Dtr_TRUE_PT;   //!
   TBranch        *b_Jet_Dtr_TRUE_M;   //!
   TBranch        *b_Jet_Dtr_TRUE_PHI;   //!
   TBranch        *b_Jet_Dtr_TRUE_ETA;   //!
   TBranch        *b_Jet_Dtr_TRUE_XVTX;   //!
   TBranch        *b_Jet_Dtr_TRUE_YVTX;   //!
   TBranch        *b_Jet_Dtr_TRUE_ZVTX;   //!
   TBranch        *b_nCandidate;   //!
   TBranch        *b_totCandidates;   //!
   TBranch        *b_EventInSequence;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_BCID;   //!
   TBranch        *b_BCType;   //!
   TBranch        *b_OdinTCK;   //!
   TBranch        *b_L0DUTCK;   //!
   TBranch        *b_HLT1TCK;   //!
   TBranch        *b_HLT2TCK;   //!
   TBranch        *b_GpsTime;   //!
   TBranch        *b_Polarity;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVX;   //!
   TBranch        *b_PVY;   //!
   TBranch        *b_PVZ;   //!
   TBranch        *b_PVXERR;   //!
   TBranch        *b_PVYERR;   //!
   TBranch        *b_PVZERR;   //!
   TBranch        *b_PVCHI2;   //!
   TBranch        *b_PVNDOF;   //!
   TBranch        *b_PVNTRACKS;   //!
   TBranch        *b_nPVs;   //!
   TBranch        *b_nTracks;   //!
   TBranch        *b_nLongTracks;   //!
   TBranch        *b_nDownstreamTracks;   //!
   TBranch        *b_nUpstreamTracks;   //!
   TBranch        *b_nVeloTracks;   //!
   TBranch        *b_nTTracks;   //!
   TBranch        *b_nBackTracks;   //!
   TBranch        *b_nRich1Hits;   //!
   TBranch        *b_nRich2Hits;   //!
   TBranch        *b_nVeloClusters;   //!
   TBranch        *b_nITClusters;   //!
   TBranch        *b_nTTClusters;   //!
   TBranch        *b_nOTClusters;   //!
   TBranch        *b_nSPDHits;   //!
   TBranch        *b_nMuonCoordsS0;   //!
   TBranch        *b_nMuonCoordsS1;   //!
   TBranch        *b_nMuonCoordsS2;   //!
   TBranch        *b_nMuonCoordsS3;   //!
   TBranch        *b_nMuonCoordsS4;   //!
   TBranch        *b_nMuonTracks;   //!
   TBranch        *b_StrippingZ02MuMuLineDecision;   //!

   TZJetsData(TTree *tree=0);
   virtual ~TZJetsData();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef TZJetsData_cxx
TZJetsData::TZJetsData(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f || !f->IsOpen()) {
         f = new TFile("Memory Directory");
      }
      f->GetObject("StdHltZJets/DecayTree",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("StdHltZJets/DecayTree","");
      chain->Add("/home/esteban/Documents/umich-work/lhcb/charge-correlation-ratio-Z/input-files/Zjet_Data_2016_MU_04062024.root/StdHltZJets/DecayTree");
      chain->Add("/home/esteban/Documents/umich-work/lhcb/charge-correlation-ratio-Z/input-files/Zjet_Data_2016_MD_04062024.root/StdHltZJets/DecayTree");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

TZJetsData::~TZJetsData()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t TZJetsData::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t TZJetsData::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void TZJetsData::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("H_10_MIPDV", &H_10_MIPDV, &b_H_10_MIPDV);
   fChain->SetBranchAddress("H_10_P", &H_10_P, &b_H_10_P);
   fChain->SetBranchAddress("H_10_PT", &H_10_PT, &b_H_10_PT);
   fChain->SetBranchAddress("H_10_PE", &H_10_PE, &b_H_10_PE);
   fChain->SetBranchAddress("H_10_PX", &H_10_PX, &b_H_10_PX);
   fChain->SetBranchAddress("H_10_PY", &H_10_PY, &b_H_10_PY);
   fChain->SetBranchAddress("H_10_PZ", &H_10_PZ, &b_H_10_PZ);
   fChain->SetBranchAddress("H_10_MM", &H_10_MM, &b_H_10_MM);
   fChain->SetBranchAddress("H_10_MMERR", &H_10_MMERR, &b_H_10_MMERR);
   fChain->SetBranchAddress("H_10_M", &H_10_M, &b_H_10_M);
   fChain->SetBranchAddress("H_10_ID", &H_10_ID, &b_H_10_ID);
   fChain->SetBranchAddress("Z0_MIPDV", &Z0_MIPDV, &b_Z0_MIPDV);
   fChain->SetBranchAddress("Z0_P", &Z0_P, &b_Z0_P);
   fChain->SetBranchAddress("Z0_PT", &Z0_PT, &b_Z0_PT);
   fChain->SetBranchAddress("Z0_PE", &Z0_PE, &b_Z0_PE);
   fChain->SetBranchAddress("Z0_PX", &Z0_PX, &b_Z0_PX);
   fChain->SetBranchAddress("Z0_PY", &Z0_PY, &b_Z0_PY);
   fChain->SetBranchAddress("Z0_PZ", &Z0_PZ, &b_Z0_PZ);
   fChain->SetBranchAddress("Z0_MM", &Z0_MM, &b_Z0_MM);
   fChain->SetBranchAddress("Z0_MMERR", &Z0_MMERR, &b_Z0_MMERR);
   fChain->SetBranchAddress("Z0_M", &Z0_M, &b_Z0_M);
   fChain->SetBranchAddress("Z0_ID", &Z0_ID, &b_Z0_ID);
   fChain->SetBranchAddress("Z0_AssociatedTracks_n_Tracks", &Z0_AssociatedTracks_n_Tracks, &b_Z0_AssociatedTracks_n_Tracks);
   fChain->SetBranchAddress("Z0_AssociatedTracks_PT", Z0_AssociatedTracks_PT, &b_Z0_AssociatedTracks_PT);
   fChain->SetBranchAddress("Z0_AssociatedTracks_PHI", Z0_AssociatedTracks_PHI, &b_Z0_AssociatedTracks_PHI);
   fChain->SetBranchAddress("Z0_AssociatedTracks_ETA", Z0_AssociatedTracks_ETA, &b_Z0_AssociatedTracks_ETA);
   fChain->SetBranchAddress("Z0_AssociatedTracks_VX", Z0_AssociatedTracks_VX, &b_Z0_AssociatedTracks_VX);
   fChain->SetBranchAddress("Z0_AssociatedTracks_VY", Z0_AssociatedTracks_VY, &b_Z0_AssociatedTracks_VY);
   fChain->SetBranchAddress("Z0_AssociatedTracks_VZ", Z0_AssociatedTracks_VZ, &b_Z0_AssociatedTracks_VZ);
   fChain->SetBranchAddress("Z0_AssociatedTracks_ProbChi2", Z0_AssociatedTracks_ProbChi2, &b_Z0_AssociatedTracks_ProbChi2);
   fChain->SetBranchAddress("Z0_AssociatedTracks_ProbGhost", Z0_AssociatedTracks_ProbGhost, &b_Z0_AssociatedTracks_ProbGhost);
   fChain->SetBranchAddress("Z0_AssociatedTracks_TrackType", Z0_AssociatedTracks_TrackType, &b_Z0_AssociatedTracks_TrackType);
   fChain->SetBranchAddress("Z0_AssociatedTracks_FirstState", Z0_AssociatedTracks_FirstState, &b_Z0_AssociatedTracks_FirstState);
   fChain->SetBranchAddress("Z0_ENDVERTEX_X", &Z0_ENDVERTEX_X, &b_Z0_ENDVERTEX_X);
   fChain->SetBranchAddress("Z0_ENDVERTEX_Y", &Z0_ENDVERTEX_Y, &b_Z0_ENDVERTEX_Y);
   fChain->SetBranchAddress("Z0_ENDVERTEX_Z", &Z0_ENDVERTEX_Z, &b_Z0_ENDVERTEX_Z);
   fChain->SetBranchAddress("Z0_ENDVERTEX_XERR", &Z0_ENDVERTEX_XERR, &b_Z0_ENDVERTEX_XERR);
   fChain->SetBranchAddress("Z0_ENDVERTEX_YERR", &Z0_ENDVERTEX_YERR, &b_Z0_ENDVERTEX_YERR);
   fChain->SetBranchAddress("Z0_ENDVERTEX_ZERR", &Z0_ENDVERTEX_ZERR, &b_Z0_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("Z0_ENDVERTEX_CHI2", &Z0_ENDVERTEX_CHI2, &b_Z0_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("Z0_ENDVERTEX_NDOF", &Z0_ENDVERTEX_NDOF, &b_Z0_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("Z0_ENDVERTEX_COV_", Z0_ENDVERTEX_COV_, &b_Z0_ENDVERTEX_COV_);
   fChain->SetBranchAddress("Z0_OWNPV_X", &Z0_OWNPV_X, &b_Z0_OWNPV_X);
   fChain->SetBranchAddress("Z0_OWNPV_Y", &Z0_OWNPV_Y, &b_Z0_OWNPV_Y);
   fChain->SetBranchAddress("Z0_OWNPV_Z", &Z0_OWNPV_Z, &b_Z0_OWNPV_Z);
   fChain->SetBranchAddress("Z0_OWNPV_XERR", &Z0_OWNPV_XERR, &b_Z0_OWNPV_XERR);
   fChain->SetBranchAddress("Z0_OWNPV_YERR", &Z0_OWNPV_YERR, &b_Z0_OWNPV_YERR);
   fChain->SetBranchAddress("Z0_OWNPV_ZERR", &Z0_OWNPV_ZERR, &b_Z0_OWNPV_ZERR);
   fChain->SetBranchAddress("Z0_OWNPV_CHI2", &Z0_OWNPV_CHI2, &b_Z0_OWNPV_CHI2);
   fChain->SetBranchAddress("Z0_OWNPV_NDOF", &Z0_OWNPV_NDOF, &b_Z0_OWNPV_NDOF);
   fChain->SetBranchAddress("Z0_OWNPV_COV_", Z0_OWNPV_COV_, &b_Z0_OWNPV_COV_);
   fChain->SetBranchAddress("Z0_IP_OWNPV", &Z0_IP_OWNPV, &b_Z0_IP_OWNPV);
   fChain->SetBranchAddress("Z0_IPCHI2_OWNPV", &Z0_IPCHI2_OWNPV, &b_Z0_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Z0_FD_OWNPV", &Z0_FD_OWNPV, &b_Z0_FD_OWNPV);
   fChain->SetBranchAddress("Z0_FDCHI2_OWNPV", &Z0_FDCHI2_OWNPV, &b_Z0_FDCHI2_OWNPV);
   fChain->SetBranchAddress("Z0_DIRA_OWNPV", &Z0_DIRA_OWNPV, &b_Z0_DIRA_OWNPV);
   fChain->SetBranchAddress("Z0_ORIVX_X", &Z0_ORIVX_X, &b_Z0_ORIVX_X);
   fChain->SetBranchAddress("Z0_ORIVX_Y", &Z0_ORIVX_Y, &b_Z0_ORIVX_Y);
   fChain->SetBranchAddress("Z0_ORIVX_Z", &Z0_ORIVX_Z, &b_Z0_ORIVX_Z);
   fChain->SetBranchAddress("Z0_ORIVX_XERR", &Z0_ORIVX_XERR, &b_Z0_ORIVX_XERR);
   fChain->SetBranchAddress("Z0_ORIVX_YERR", &Z0_ORIVX_YERR, &b_Z0_ORIVX_YERR);
   fChain->SetBranchAddress("Z0_ORIVX_ZERR", &Z0_ORIVX_ZERR, &b_Z0_ORIVX_ZERR);
   fChain->SetBranchAddress("Z0_ORIVX_CHI2", &Z0_ORIVX_CHI2, &b_Z0_ORIVX_CHI2);
   fChain->SetBranchAddress("Z0_ORIVX_NDOF", &Z0_ORIVX_NDOF, &b_Z0_ORIVX_NDOF);
   fChain->SetBranchAddress("Z0_ORIVX_COV_", Z0_ORIVX_COV_, &b_Z0_ORIVX_COV_);
   fChain->SetBranchAddress("Z0_FD_ORIVX", &Z0_FD_ORIVX, &b_Z0_FD_ORIVX);
   fChain->SetBranchAddress("Z0_FDCHI2_ORIVX", &Z0_FDCHI2_ORIVX, &b_Z0_FDCHI2_ORIVX);
   fChain->SetBranchAddress("Z0_DIRA_ORIVX", &Z0_DIRA_ORIVX, &b_Z0_DIRA_ORIVX);
   fChain->SetBranchAddress("mup_MIPDV", &mup_MIPDV, &b_mup_MIPDV);
   fChain->SetBranchAddress("mup_P", &mup_P, &b_mup_P);
   fChain->SetBranchAddress("mup_PT", &mup_PT, &b_mup_PT);
   fChain->SetBranchAddress("mup_PE", &mup_PE, &b_mup_PE);
   fChain->SetBranchAddress("mup_PX", &mup_PX, &b_mup_PX);
   fChain->SetBranchAddress("mup_PY", &mup_PY, &b_mup_PY);
   fChain->SetBranchAddress("mup_PZ", &mup_PZ, &b_mup_PZ);
   fChain->SetBranchAddress("mup_M", &mup_M, &b_mup_M);
   fChain->SetBranchAddress("mup_ID", &mup_ID, &b_mup_ID);
   fChain->SetBranchAddress("mup_PIDe", &mup_PIDe, &b_mup_PIDe);
   fChain->SetBranchAddress("mup_PIDmu", &mup_PIDmu, &b_mup_PIDmu);
   fChain->SetBranchAddress("mup_PIDK", &mup_PIDK, &b_mup_PIDK);
   fChain->SetBranchAddress("mup_PIDp", &mup_PIDp, &b_mup_PIDp);
   fChain->SetBranchAddress("mup_PIDd", &mup_PIDd, &b_mup_PIDd);
   fChain->SetBranchAddress("mup_ProbNNe", &mup_ProbNNe, &b_mup_ProbNNe);
   fChain->SetBranchAddress("mup_ProbNNk", &mup_ProbNNk, &b_mup_ProbNNk);
   fChain->SetBranchAddress("mup_ProbNNp", &mup_ProbNNp, &b_mup_ProbNNp);
   fChain->SetBranchAddress("mup_ProbNNpi", &mup_ProbNNpi, &b_mup_ProbNNpi);
   fChain->SetBranchAddress("mup_ProbNNmu", &mup_ProbNNmu, &b_mup_ProbNNmu);
   fChain->SetBranchAddress("mup_ProbNNd", &mup_ProbNNd, &b_mup_ProbNNd);
   fChain->SetBranchAddress("mup_ProbNNghost", &mup_ProbNNghost, &b_mup_ProbNNghost);
   fChain->SetBranchAddress("mup_hasMuon", &mup_hasMuon, &b_mup_hasMuon);
   fChain->SetBranchAddress("mup_isMuon", &mup_isMuon, &b_mup_isMuon);
   fChain->SetBranchAddress("mup_hasRich", &mup_hasRich, &b_mup_hasRich);
   fChain->SetBranchAddress("mup_UsedRichAerogel", &mup_UsedRichAerogel, &b_mup_UsedRichAerogel);
   fChain->SetBranchAddress("mup_UsedRich1Gas", &mup_UsedRich1Gas, &b_mup_UsedRich1Gas);
   fChain->SetBranchAddress("mup_UsedRich2Gas", &mup_UsedRich2Gas, &b_mup_UsedRich2Gas);
   fChain->SetBranchAddress("mup_RichAboveElThres", &mup_RichAboveElThres, &b_mup_RichAboveElThres);
   fChain->SetBranchAddress("mup_RichAboveMuThres", &mup_RichAboveMuThres, &b_mup_RichAboveMuThres);
   fChain->SetBranchAddress("mup_RichAbovePiThres", &mup_RichAbovePiThres, &b_mup_RichAbovePiThres);
   fChain->SetBranchAddress("mup_RichAboveKaThres", &mup_RichAboveKaThres, &b_mup_RichAboveKaThres);
   fChain->SetBranchAddress("mup_RichAbovePrThres", &mup_RichAbovePrThres, &b_mup_RichAbovePrThres);
   fChain->SetBranchAddress("mup_hasCalo", &mup_hasCalo, &b_mup_hasCalo);
   fChain->SetBranchAddress("mup_OWNPV_X", &mup_OWNPV_X, &b_mup_OWNPV_X);
   fChain->SetBranchAddress("mup_OWNPV_Y", &mup_OWNPV_Y, &b_mup_OWNPV_Y);
   fChain->SetBranchAddress("mup_OWNPV_Z", &mup_OWNPV_Z, &b_mup_OWNPV_Z);
   fChain->SetBranchAddress("mup_OWNPV_XERR", &mup_OWNPV_XERR, &b_mup_OWNPV_XERR);
   fChain->SetBranchAddress("mup_OWNPV_YERR", &mup_OWNPV_YERR, &b_mup_OWNPV_YERR);
   fChain->SetBranchAddress("mup_OWNPV_ZERR", &mup_OWNPV_ZERR, &b_mup_OWNPV_ZERR);
   fChain->SetBranchAddress("mup_OWNPV_CHI2", &mup_OWNPV_CHI2, &b_mup_OWNPV_CHI2);
   fChain->SetBranchAddress("mup_OWNPV_NDOF", &mup_OWNPV_NDOF, &b_mup_OWNPV_NDOF);
   fChain->SetBranchAddress("mup_OWNPV_COV_", mup_OWNPV_COV_, &b_mup_OWNPV_COV_);
   fChain->SetBranchAddress("mup_IP_OWNPV", &mup_IP_OWNPV, &b_mup_IP_OWNPV);
   fChain->SetBranchAddress("mup_IPCHI2_OWNPV", &mup_IPCHI2_OWNPV, &b_mup_IPCHI2_OWNPV);
   fChain->SetBranchAddress("mup_ORIVX_X", &mup_ORIVX_X, &b_mup_ORIVX_X);
   fChain->SetBranchAddress("mup_ORIVX_Y", &mup_ORIVX_Y, &b_mup_ORIVX_Y);
   fChain->SetBranchAddress("mup_ORIVX_Z", &mup_ORIVX_Z, &b_mup_ORIVX_Z);
   fChain->SetBranchAddress("mup_ORIVX_XERR", &mup_ORIVX_XERR, &b_mup_ORIVX_XERR);
   fChain->SetBranchAddress("mup_ORIVX_YERR", &mup_ORIVX_YERR, &b_mup_ORIVX_YERR);
   fChain->SetBranchAddress("mup_ORIVX_ZERR", &mup_ORIVX_ZERR, &b_mup_ORIVX_ZERR);
   fChain->SetBranchAddress("mup_ORIVX_CHI2", &mup_ORIVX_CHI2, &b_mup_ORIVX_CHI2);
   fChain->SetBranchAddress("mup_ORIVX_NDOF", &mup_ORIVX_NDOF, &b_mup_ORIVX_NDOF);
   fChain->SetBranchAddress("mup_ORIVX_COV_", mup_ORIVX_COV_, &b_mup_ORIVX_COV_);
   fChain->SetBranchAddress("mup_L0Global_Dec", &mup_L0Global_Dec, &b_mup_L0Global_Dec);
   fChain->SetBranchAddress("mup_L0Global_TIS", &mup_L0Global_TIS, &b_mup_L0Global_TIS);
   fChain->SetBranchAddress("mup_L0Global_TOS", &mup_L0Global_TOS, &b_mup_L0Global_TOS);
   fChain->SetBranchAddress("mup_Hlt1Global_Dec", &mup_Hlt1Global_Dec, &b_mup_Hlt1Global_Dec);
   fChain->SetBranchAddress("mup_Hlt1Global_TIS", &mup_Hlt1Global_TIS, &b_mup_Hlt1Global_TIS);
   fChain->SetBranchAddress("mup_Hlt1Global_TOS", &mup_Hlt1Global_TOS, &b_mup_Hlt1Global_TOS);
   fChain->SetBranchAddress("mup_Hlt1Phys_Dec", &mup_Hlt1Phys_Dec, &b_mup_Hlt1Phys_Dec);
   fChain->SetBranchAddress("mup_Hlt1Phys_TIS", &mup_Hlt1Phys_TIS, &b_mup_Hlt1Phys_TIS);
   fChain->SetBranchAddress("mup_Hlt1Phys_TOS", &mup_Hlt1Phys_TOS, &b_mup_Hlt1Phys_TOS);
   fChain->SetBranchAddress("mup_Hlt2Global_Dec", &mup_Hlt2Global_Dec, &b_mup_Hlt2Global_Dec);
   fChain->SetBranchAddress("mup_Hlt2Global_TIS", &mup_Hlt2Global_TIS, &b_mup_Hlt2Global_TIS);
   fChain->SetBranchAddress("mup_Hlt2Global_TOS", &mup_Hlt2Global_TOS, &b_mup_Hlt2Global_TOS);
   fChain->SetBranchAddress("mup_Hlt2Phys_Dec", &mup_Hlt2Phys_Dec, &b_mup_Hlt2Phys_Dec);
   fChain->SetBranchAddress("mup_Hlt2Phys_TIS", &mup_Hlt2Phys_TIS, &b_mup_Hlt2Phys_TIS);
   fChain->SetBranchAddress("mup_Hlt2Phys_TOS", &mup_Hlt2Phys_TOS, &b_mup_Hlt2Phys_TOS);
   fChain->SetBranchAddress("mup_L0MuonDecision_Dec", &mup_L0MuonDecision_Dec, &b_mup_L0MuonDecision_Dec);
   fChain->SetBranchAddress("mup_L0MuonDecision_TIS", &mup_L0MuonDecision_TIS, &b_mup_L0MuonDecision_TIS);
   fChain->SetBranchAddress("mup_L0MuonDecision_TOS", &mup_L0MuonDecision_TOS, &b_mup_L0MuonDecision_TOS);
   fChain->SetBranchAddress("mup_L0MuonEWDecision_Dec", &mup_L0MuonEWDecision_Dec, &b_mup_L0MuonEWDecision_Dec);
   fChain->SetBranchAddress("mup_L0MuonEWDecision_TIS", &mup_L0MuonEWDecision_TIS, &b_mup_L0MuonEWDecision_TIS);
   fChain->SetBranchAddress("mup_L0MuonEWDecision_TOS", &mup_L0MuonEWDecision_TOS, &b_mup_L0MuonEWDecision_TOS);
   fChain->SetBranchAddress("mup_L0DiMuonDecision_Dec", &mup_L0DiMuonDecision_Dec, &b_mup_L0DiMuonDecision_Dec);
   fChain->SetBranchAddress("mup_L0DiMuonDecision_TIS", &mup_L0DiMuonDecision_TIS, &b_mup_L0DiMuonDecision_TIS);
   fChain->SetBranchAddress("mup_L0DiMuonDecision_TOS", &mup_L0DiMuonDecision_TOS, &b_mup_L0DiMuonDecision_TOS);
   fChain->SetBranchAddress("mup_Hlt1SingleMuonHighPTDecision_Dec", &mup_Hlt1SingleMuonHighPTDecision_Dec, &b_mup_Hlt1SingleMuonHighPTDecision_Dec);
   fChain->SetBranchAddress("mup_Hlt1SingleMuonHighPTDecision_TIS", &mup_Hlt1SingleMuonHighPTDecision_TIS, &b_mup_Hlt1SingleMuonHighPTDecision_TIS);
   fChain->SetBranchAddress("mup_Hlt1SingleMuonHighPTDecision_TOS", &mup_Hlt1SingleMuonHighPTDecision_TOS, &b_mup_Hlt1SingleMuonHighPTDecision_TOS);
   fChain->SetBranchAddress("mup_Hlt2SingleMuonDecision_Dec", &mup_Hlt2SingleMuonDecision_Dec, &b_mup_Hlt2SingleMuonDecision_Dec);
   fChain->SetBranchAddress("mup_Hlt2SingleMuonDecision_TIS", &mup_Hlt2SingleMuonDecision_TIS, &b_mup_Hlt2SingleMuonDecision_TIS);
   fChain->SetBranchAddress("mup_Hlt2SingleMuonDecision_TOS", &mup_Hlt2SingleMuonDecision_TOS, &b_mup_Hlt2SingleMuonDecision_TOS);
   fChain->SetBranchAddress("mup_Hlt2SingleMuonLowPTDecision_Dec", &mup_Hlt2SingleMuonLowPTDecision_Dec, &b_mup_Hlt2SingleMuonLowPTDecision_Dec);
   fChain->SetBranchAddress("mup_Hlt2SingleMuonLowPTDecision_TIS", &mup_Hlt2SingleMuonLowPTDecision_TIS, &b_mup_Hlt2SingleMuonLowPTDecision_TIS);
   fChain->SetBranchAddress("mup_Hlt2SingleMuonLowPTDecision_TOS", &mup_Hlt2SingleMuonLowPTDecision_TOS, &b_mup_Hlt2SingleMuonLowPTDecision_TOS);
   fChain->SetBranchAddress("mup_Hlt2SingleMuonHighPTDecision_Dec", &mup_Hlt2SingleMuonHighPTDecision_Dec, &b_mup_Hlt2SingleMuonHighPTDecision_Dec);
   fChain->SetBranchAddress("mup_Hlt2SingleMuonHighPTDecision_TIS", &mup_Hlt2SingleMuonHighPTDecision_TIS, &b_mup_Hlt2SingleMuonHighPTDecision_TIS);
   fChain->SetBranchAddress("mup_Hlt2SingleMuonHighPTDecision_TOS", &mup_Hlt2SingleMuonHighPTDecision_TOS, &b_mup_Hlt2SingleMuonHighPTDecision_TOS);
   fChain->SetBranchAddress("mup_Hlt2EWSingleMuonHighPtDecision_Dec", &mup_Hlt2EWSingleMuonHighPtDecision_Dec, &b_mup_Hlt2EWSingleMuonHighPtDecision_Dec);
   fChain->SetBranchAddress("mup_Hlt2EWSingleMuonHighPtDecision_TIS", &mup_Hlt2EWSingleMuonHighPtDecision_TIS, &b_mup_Hlt2EWSingleMuonHighPtDecision_TIS);
   fChain->SetBranchAddress("mup_Hlt2EWSingleMuonHighPtDecision_TOS", &mup_Hlt2EWSingleMuonHighPtDecision_TOS, &b_mup_Hlt2EWSingleMuonHighPtDecision_TOS);
   fChain->SetBranchAddress("mup_Hlt2EWSingleMuonVHighPtDecision_Dec", &mup_Hlt2EWSingleMuonVHighPtDecision_Dec, &b_mup_Hlt2EWSingleMuonVHighPtDecision_Dec);
   fChain->SetBranchAddress("mup_Hlt2EWSingleMuonVHighPtDecision_TIS", &mup_Hlt2EWSingleMuonVHighPtDecision_TIS, &b_mup_Hlt2EWSingleMuonVHighPtDecision_TIS);
   fChain->SetBranchAddress("mup_Hlt2EWSingleMuonVHighPtDecision_TOS", &mup_Hlt2EWSingleMuonVHighPtDecision_TOS, &b_mup_Hlt2EWSingleMuonVHighPtDecision_TOS);
   fChain->SetBranchAddress("mup_TRACK_Type", &mup_TRACK_Type, &b_mup_TRACK_Type);
   fChain->SetBranchAddress("mup_TRACK_Key", &mup_TRACK_Key, &b_mup_TRACK_Key);
   fChain->SetBranchAddress("mup_TRACK_CHI2NDOF", &mup_TRACK_CHI2NDOF, &b_mup_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("mup_TRACK_PCHI2", &mup_TRACK_PCHI2, &b_mup_TRACK_PCHI2);
   fChain->SetBranchAddress("mup_TRACK_MatchCHI2", &mup_TRACK_MatchCHI2, &b_mup_TRACK_MatchCHI2);
   fChain->SetBranchAddress("mup_TRACK_GhostProb", &mup_TRACK_GhostProb, &b_mup_TRACK_GhostProb);
   fChain->SetBranchAddress("mup_TRACK_CloneDist", &mup_TRACK_CloneDist, &b_mup_TRACK_CloneDist);
   fChain->SetBranchAddress("mup_TRACK_Likelihood", &mup_TRACK_Likelihood, &b_mup_TRACK_Likelihood);
   fChain->SetBranchAddress("mum_MIPDV", &mum_MIPDV, &b_mum_MIPDV);
   fChain->SetBranchAddress("mum_P", &mum_P, &b_mum_P);
   fChain->SetBranchAddress("mum_PT", &mum_PT, &b_mum_PT);
   fChain->SetBranchAddress("mum_PE", &mum_PE, &b_mum_PE);
   fChain->SetBranchAddress("mum_PX", &mum_PX, &b_mum_PX);
   fChain->SetBranchAddress("mum_PY", &mum_PY, &b_mum_PY);
   fChain->SetBranchAddress("mum_PZ", &mum_PZ, &b_mum_PZ);
   fChain->SetBranchAddress("mum_M", &mum_M, &b_mum_M);
   fChain->SetBranchAddress("mum_ID", &mum_ID, &b_mum_ID);
   fChain->SetBranchAddress("mum_PIDe", &mum_PIDe, &b_mum_PIDe);
   fChain->SetBranchAddress("mum_PIDmu", &mum_PIDmu, &b_mum_PIDmu);
   fChain->SetBranchAddress("mum_PIDK", &mum_PIDK, &b_mum_PIDK);
   fChain->SetBranchAddress("mum_PIDp", &mum_PIDp, &b_mum_PIDp);
   fChain->SetBranchAddress("mum_PIDd", &mum_PIDd, &b_mum_PIDd);
   fChain->SetBranchAddress("mum_ProbNNe", &mum_ProbNNe, &b_mum_ProbNNe);
   fChain->SetBranchAddress("mum_ProbNNk", &mum_ProbNNk, &b_mum_ProbNNk);
   fChain->SetBranchAddress("mum_ProbNNp", &mum_ProbNNp, &b_mum_ProbNNp);
   fChain->SetBranchAddress("mum_ProbNNpi", &mum_ProbNNpi, &b_mum_ProbNNpi);
   fChain->SetBranchAddress("mum_ProbNNmu", &mum_ProbNNmu, &b_mum_ProbNNmu);
   fChain->SetBranchAddress("mum_ProbNNd", &mum_ProbNNd, &b_mum_ProbNNd);
   fChain->SetBranchAddress("mum_ProbNNghost", &mum_ProbNNghost, &b_mum_ProbNNghost);
   fChain->SetBranchAddress("mum_hasMuon", &mum_hasMuon, &b_mum_hasMuon);
   fChain->SetBranchAddress("mum_isMuon", &mum_isMuon, &b_mum_isMuon);
   fChain->SetBranchAddress("mum_hasRich", &mum_hasRich, &b_mum_hasRich);
   fChain->SetBranchAddress("mum_UsedRichAerogel", &mum_UsedRichAerogel, &b_mum_UsedRichAerogel);
   fChain->SetBranchAddress("mum_UsedRich1Gas", &mum_UsedRich1Gas, &b_mum_UsedRich1Gas);
   fChain->SetBranchAddress("mum_UsedRich2Gas", &mum_UsedRich2Gas, &b_mum_UsedRich2Gas);
   fChain->SetBranchAddress("mum_RichAboveElThres", &mum_RichAboveElThres, &b_mum_RichAboveElThres);
   fChain->SetBranchAddress("mum_RichAboveMuThres", &mum_RichAboveMuThres, &b_mum_RichAboveMuThres);
   fChain->SetBranchAddress("mum_RichAbovePiThres", &mum_RichAbovePiThres, &b_mum_RichAbovePiThres);
   fChain->SetBranchAddress("mum_RichAboveKaThres", &mum_RichAboveKaThres, &b_mum_RichAboveKaThres);
   fChain->SetBranchAddress("mum_RichAbovePrThres", &mum_RichAbovePrThres, &b_mum_RichAbovePrThres);
   fChain->SetBranchAddress("mum_hasCalo", &mum_hasCalo, &b_mum_hasCalo);
   fChain->SetBranchAddress("mum_OWNPV_X", &mum_OWNPV_X, &b_mum_OWNPV_X);
   fChain->SetBranchAddress("mum_OWNPV_Y", &mum_OWNPV_Y, &b_mum_OWNPV_Y);
   fChain->SetBranchAddress("mum_OWNPV_Z", &mum_OWNPV_Z, &b_mum_OWNPV_Z);
   fChain->SetBranchAddress("mum_OWNPV_XERR", &mum_OWNPV_XERR, &b_mum_OWNPV_XERR);
   fChain->SetBranchAddress("mum_OWNPV_YERR", &mum_OWNPV_YERR, &b_mum_OWNPV_YERR);
   fChain->SetBranchAddress("mum_OWNPV_ZERR", &mum_OWNPV_ZERR, &b_mum_OWNPV_ZERR);
   fChain->SetBranchAddress("mum_OWNPV_CHI2", &mum_OWNPV_CHI2, &b_mum_OWNPV_CHI2);
   fChain->SetBranchAddress("mum_OWNPV_NDOF", &mum_OWNPV_NDOF, &b_mum_OWNPV_NDOF);
   fChain->SetBranchAddress("mum_OWNPV_COV_", mum_OWNPV_COV_, &b_mum_OWNPV_COV_);
   fChain->SetBranchAddress("mum_IP_OWNPV", &mum_IP_OWNPV, &b_mum_IP_OWNPV);
   fChain->SetBranchAddress("mum_IPCHI2_OWNPV", &mum_IPCHI2_OWNPV, &b_mum_IPCHI2_OWNPV);
   fChain->SetBranchAddress("mum_ORIVX_X", &mum_ORIVX_X, &b_mum_ORIVX_X);
   fChain->SetBranchAddress("mum_ORIVX_Y", &mum_ORIVX_Y, &b_mum_ORIVX_Y);
   fChain->SetBranchAddress("mum_ORIVX_Z", &mum_ORIVX_Z, &b_mum_ORIVX_Z);
   fChain->SetBranchAddress("mum_ORIVX_XERR", &mum_ORIVX_XERR, &b_mum_ORIVX_XERR);
   fChain->SetBranchAddress("mum_ORIVX_YERR", &mum_ORIVX_YERR, &b_mum_ORIVX_YERR);
   fChain->SetBranchAddress("mum_ORIVX_ZERR", &mum_ORIVX_ZERR, &b_mum_ORIVX_ZERR);
   fChain->SetBranchAddress("mum_ORIVX_CHI2", &mum_ORIVX_CHI2, &b_mum_ORIVX_CHI2);
   fChain->SetBranchAddress("mum_ORIVX_NDOF", &mum_ORIVX_NDOF, &b_mum_ORIVX_NDOF);
   fChain->SetBranchAddress("mum_ORIVX_COV_", mum_ORIVX_COV_, &b_mum_ORIVX_COV_);
   fChain->SetBranchAddress("mum_L0Global_Dec", &mum_L0Global_Dec, &b_mum_L0Global_Dec);
   fChain->SetBranchAddress("mum_L0Global_TIS", &mum_L0Global_TIS, &b_mum_L0Global_TIS);
   fChain->SetBranchAddress("mum_L0Global_TOS", &mum_L0Global_TOS, &b_mum_L0Global_TOS);
   fChain->SetBranchAddress("mum_Hlt1Global_Dec", &mum_Hlt1Global_Dec, &b_mum_Hlt1Global_Dec);
   fChain->SetBranchAddress("mum_Hlt1Global_TIS", &mum_Hlt1Global_TIS, &b_mum_Hlt1Global_TIS);
   fChain->SetBranchAddress("mum_Hlt1Global_TOS", &mum_Hlt1Global_TOS, &b_mum_Hlt1Global_TOS);
   fChain->SetBranchAddress("mum_Hlt1Phys_Dec", &mum_Hlt1Phys_Dec, &b_mum_Hlt1Phys_Dec);
   fChain->SetBranchAddress("mum_Hlt1Phys_TIS", &mum_Hlt1Phys_TIS, &b_mum_Hlt1Phys_TIS);
   fChain->SetBranchAddress("mum_Hlt1Phys_TOS", &mum_Hlt1Phys_TOS, &b_mum_Hlt1Phys_TOS);
   fChain->SetBranchAddress("mum_Hlt2Global_Dec", &mum_Hlt2Global_Dec, &b_mum_Hlt2Global_Dec);
   fChain->SetBranchAddress("mum_Hlt2Global_TIS", &mum_Hlt2Global_TIS, &b_mum_Hlt2Global_TIS);
   fChain->SetBranchAddress("mum_Hlt2Global_TOS", &mum_Hlt2Global_TOS, &b_mum_Hlt2Global_TOS);
   fChain->SetBranchAddress("mum_Hlt2Phys_Dec", &mum_Hlt2Phys_Dec, &b_mum_Hlt2Phys_Dec);
   fChain->SetBranchAddress("mum_Hlt2Phys_TIS", &mum_Hlt2Phys_TIS, &b_mum_Hlt2Phys_TIS);
   fChain->SetBranchAddress("mum_Hlt2Phys_TOS", &mum_Hlt2Phys_TOS, &b_mum_Hlt2Phys_TOS);
   fChain->SetBranchAddress("mum_L0MuonDecision_Dec", &mum_L0MuonDecision_Dec, &b_mum_L0MuonDecision_Dec);
   fChain->SetBranchAddress("mum_L0MuonDecision_TIS", &mum_L0MuonDecision_TIS, &b_mum_L0MuonDecision_TIS);
   fChain->SetBranchAddress("mum_L0MuonDecision_TOS", &mum_L0MuonDecision_TOS, &b_mum_L0MuonDecision_TOS);
   fChain->SetBranchAddress("mum_L0MuonEWDecision_Dec", &mum_L0MuonEWDecision_Dec, &b_mum_L0MuonEWDecision_Dec);
   fChain->SetBranchAddress("mum_L0MuonEWDecision_TIS", &mum_L0MuonEWDecision_TIS, &b_mum_L0MuonEWDecision_TIS);
   fChain->SetBranchAddress("mum_L0MuonEWDecision_TOS", &mum_L0MuonEWDecision_TOS, &b_mum_L0MuonEWDecision_TOS);
   fChain->SetBranchAddress("mum_L0DiMuonDecision_Dec", &mum_L0DiMuonDecision_Dec, &b_mum_L0DiMuonDecision_Dec);
   fChain->SetBranchAddress("mum_L0DiMuonDecision_TIS", &mum_L0DiMuonDecision_TIS, &b_mum_L0DiMuonDecision_TIS);
   fChain->SetBranchAddress("mum_L0DiMuonDecision_TOS", &mum_L0DiMuonDecision_TOS, &b_mum_L0DiMuonDecision_TOS);
   fChain->SetBranchAddress("mum_Hlt1SingleMuonHighPTDecision_Dec", &mum_Hlt1SingleMuonHighPTDecision_Dec, &b_mum_Hlt1SingleMuonHighPTDecision_Dec);
   fChain->SetBranchAddress("mum_Hlt1SingleMuonHighPTDecision_TIS", &mum_Hlt1SingleMuonHighPTDecision_TIS, &b_mum_Hlt1SingleMuonHighPTDecision_TIS);
   fChain->SetBranchAddress("mum_Hlt1SingleMuonHighPTDecision_TOS", &mum_Hlt1SingleMuonHighPTDecision_TOS, &b_mum_Hlt1SingleMuonHighPTDecision_TOS);
   fChain->SetBranchAddress("mum_Hlt2SingleMuonDecision_Dec", &mum_Hlt2SingleMuonDecision_Dec, &b_mum_Hlt2SingleMuonDecision_Dec);
   fChain->SetBranchAddress("mum_Hlt2SingleMuonDecision_TIS", &mum_Hlt2SingleMuonDecision_TIS, &b_mum_Hlt2SingleMuonDecision_TIS);
   fChain->SetBranchAddress("mum_Hlt2SingleMuonDecision_TOS", &mum_Hlt2SingleMuonDecision_TOS, &b_mum_Hlt2SingleMuonDecision_TOS);
   fChain->SetBranchAddress("mum_Hlt2SingleMuonLowPTDecision_Dec", &mum_Hlt2SingleMuonLowPTDecision_Dec, &b_mum_Hlt2SingleMuonLowPTDecision_Dec);
   fChain->SetBranchAddress("mum_Hlt2SingleMuonLowPTDecision_TIS", &mum_Hlt2SingleMuonLowPTDecision_TIS, &b_mum_Hlt2SingleMuonLowPTDecision_TIS);
   fChain->SetBranchAddress("mum_Hlt2SingleMuonLowPTDecision_TOS", &mum_Hlt2SingleMuonLowPTDecision_TOS, &b_mum_Hlt2SingleMuonLowPTDecision_TOS);
   fChain->SetBranchAddress("mum_Hlt2SingleMuonHighPTDecision_Dec", &mum_Hlt2SingleMuonHighPTDecision_Dec, &b_mum_Hlt2SingleMuonHighPTDecision_Dec);
   fChain->SetBranchAddress("mum_Hlt2SingleMuonHighPTDecision_TIS", &mum_Hlt2SingleMuonHighPTDecision_TIS, &b_mum_Hlt2SingleMuonHighPTDecision_TIS);
   fChain->SetBranchAddress("mum_Hlt2SingleMuonHighPTDecision_TOS", &mum_Hlt2SingleMuonHighPTDecision_TOS, &b_mum_Hlt2SingleMuonHighPTDecision_TOS);
   fChain->SetBranchAddress("mum_Hlt2EWSingleMuonHighPtDecision_Dec", &mum_Hlt2EWSingleMuonHighPtDecision_Dec, &b_mum_Hlt2EWSingleMuonHighPtDecision_Dec);
   fChain->SetBranchAddress("mum_Hlt2EWSingleMuonHighPtDecision_TIS", &mum_Hlt2EWSingleMuonHighPtDecision_TIS, &b_mum_Hlt2EWSingleMuonHighPtDecision_TIS);
   fChain->SetBranchAddress("mum_Hlt2EWSingleMuonHighPtDecision_TOS", &mum_Hlt2EWSingleMuonHighPtDecision_TOS, &b_mum_Hlt2EWSingleMuonHighPtDecision_TOS);
   fChain->SetBranchAddress("mum_Hlt2EWSingleMuonVHighPtDecision_Dec", &mum_Hlt2EWSingleMuonVHighPtDecision_Dec, &b_mum_Hlt2EWSingleMuonVHighPtDecision_Dec);
   fChain->SetBranchAddress("mum_Hlt2EWSingleMuonVHighPtDecision_TIS", &mum_Hlt2EWSingleMuonVHighPtDecision_TIS, &b_mum_Hlt2EWSingleMuonVHighPtDecision_TIS);
   fChain->SetBranchAddress("mum_Hlt2EWSingleMuonVHighPtDecision_TOS", &mum_Hlt2EWSingleMuonVHighPtDecision_TOS, &b_mum_Hlt2EWSingleMuonVHighPtDecision_TOS);
   fChain->SetBranchAddress("mum_TRACK_Type", &mum_TRACK_Type, &b_mum_TRACK_Type);
   fChain->SetBranchAddress("mum_TRACK_Key", &mum_TRACK_Key, &b_mum_TRACK_Key);
   fChain->SetBranchAddress("mum_TRACK_CHI2NDOF", &mum_TRACK_CHI2NDOF, &b_mum_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("mum_TRACK_PCHI2", &mum_TRACK_PCHI2, &b_mum_TRACK_PCHI2);
   fChain->SetBranchAddress("mum_TRACK_MatchCHI2", &mum_TRACK_MatchCHI2, &b_mum_TRACK_MatchCHI2);
   fChain->SetBranchAddress("mum_TRACK_GhostProb", &mum_TRACK_GhostProb, &b_mum_TRACK_GhostProb);
   fChain->SetBranchAddress("mum_TRACK_CloneDist", &mum_TRACK_CloneDist, &b_mum_TRACK_CloneDist);
   fChain->SetBranchAddress("mum_TRACK_Likelihood", &mum_TRACK_Likelihood, &b_mum_TRACK_Likelihood);
   fChain->SetBranchAddress("Jet_MIPDV", &Jet_MIPDV, &b_Jet_MIPDV);
   fChain->SetBranchAddress("Jet_P", &Jet_P, &b_Jet_P);
   fChain->SetBranchAddress("Jet_PT", &Jet_PT, &b_Jet_PT);
   fChain->SetBranchAddress("Jet_PE", &Jet_PE, &b_Jet_PE);
   fChain->SetBranchAddress("Jet_PX", &Jet_PX, &b_Jet_PX);
   fChain->SetBranchAddress("Jet_PY", &Jet_PY, &b_Jet_PY);
   fChain->SetBranchAddress("Jet_PZ", &Jet_PZ, &b_Jet_PZ);
   fChain->SetBranchAddress("Jet_MM", &Jet_MM, &b_Jet_MM);
   fChain->SetBranchAddress("Jet_MMERR", &Jet_MMERR, &b_Jet_MMERR);
   fChain->SetBranchAddress("Jet_M", &Jet_M, &b_Jet_M);
   fChain->SetBranchAddress("Jet_ID", &Jet_ID, &b_Jet_ID);
   fChain->SetBranchAddress("Jet_Dtr_nrecodtr", &Jet_Dtr_nrecodtr, &b_Jet_Dtr_nrecodtr);
   fChain->SetBranchAddress("jet_XVTX", &jet_XVTX, &b_jet_XVTX);
   fChain->SetBranchAddress("jet_YVTX", &jet_YVTX, &b_jet_YVTX);
   fChain->SetBranchAddress("jet_ZVTX", &jet_ZVTX, &b_jet_ZVTX);
   fChain->SetBranchAddress("Jet_NDtr", &Jet_NDtr, &b_Jet_NDtr);
   fChain->SetBranchAddress("Jet_Dtr_IP", Jet_Dtr_IP, &b_Jet_Dtr_IP);
   fChain->SetBranchAddress("Jet_Dtr_IPCHI2", Jet_Dtr_IPCHI2, &b_Jet_Dtr_IPCHI2);
   fChain->SetBranchAddress("Jet_Dtr_ID", Jet_Dtr_ID, &b_Jet_Dtr_ID);
   fChain->SetBranchAddress("Jet_Dtr_ThreeCharge", Jet_Dtr_ThreeCharge, &b_Jet_Dtr_ThreeCharge);
   fChain->SetBranchAddress("Jet_Dtr_IsMeson", Jet_Dtr_IsMeson, &b_Jet_Dtr_IsMeson);
   fChain->SetBranchAddress("Jet_Dtr_IsBaryon", Jet_Dtr_IsBaryon, &b_Jet_Dtr_IsBaryon);
   fChain->SetBranchAddress("Jet_Dtr_IsStrange", Jet_Dtr_IsStrange, &b_Jet_Dtr_IsStrange);
   fChain->SetBranchAddress("Jet_Dtr_PIDe", Jet_Dtr_PIDe, &b_Jet_Dtr_PIDe);
   fChain->SetBranchAddress("Jet_Dtr_PIDmu", Jet_Dtr_PIDmu, &b_Jet_Dtr_PIDmu);
   fChain->SetBranchAddress("Jet_Dtr_PIDk", Jet_Dtr_PIDk, &b_Jet_Dtr_PIDk);
   fChain->SetBranchAddress("Jet_Dtr_PIDp", Jet_Dtr_PIDp, &b_Jet_Dtr_PIDp);
   fChain->SetBranchAddress("Jet_Dtr_PIDpi", Jet_Dtr_PIDpi, &b_Jet_Dtr_PIDpi);
   fChain->SetBranchAddress("Jet_Dtr_ProbNNe", Jet_Dtr_ProbNNe, &b_Jet_Dtr_ProbNNe);
   fChain->SetBranchAddress("Jet_Dtr_ProbNNmu", Jet_Dtr_ProbNNmu, &b_Jet_Dtr_ProbNNmu);
   fChain->SetBranchAddress("Jet_Dtr_ProbNNk", Jet_Dtr_ProbNNk, &b_Jet_Dtr_ProbNNk);
   fChain->SetBranchAddress("Jet_Dtr_ProbNNp", Jet_Dtr_ProbNNp, &b_Jet_Dtr_ProbNNp);
   fChain->SetBranchAddress("Jet_Dtr_ProbNNpi", Jet_Dtr_ProbNNpi, &b_Jet_Dtr_ProbNNpi);
   fChain->SetBranchAddress("Jet_Dtr_ProbNNghost", Jet_Dtr_ProbNNghost, &b_Jet_Dtr_ProbNNghost);
   fChain->SetBranchAddress("Jet_Dtr_PX", Jet_Dtr_PX, &b_Jet_Dtr_PX);
   fChain->SetBranchAddress("Jet_Dtr_PY", Jet_Dtr_PY, &b_Jet_Dtr_PY);
   fChain->SetBranchAddress("Jet_Dtr_PZ", Jet_Dtr_PZ, &b_Jet_Dtr_PZ);
   fChain->SetBranchAddress("Jet_Dtr_E", Jet_Dtr_E, &b_Jet_Dtr_E);
   fChain->SetBranchAddress("Jet_Dtr_P", Jet_Dtr_P, &b_Jet_Dtr_P);
   fChain->SetBranchAddress("Jet_Dtr_PT", Jet_Dtr_PT, &b_Jet_Dtr_PT);
   fChain->SetBranchAddress("Jet_Dtr_M", Jet_Dtr_M, &b_Jet_Dtr_M);
   fChain->SetBranchAddress("Jet_Dtr_PHI", Jet_Dtr_PHI, &b_Jet_Dtr_PHI);
   fChain->SetBranchAddress("Jet_Dtr_ETA", Jet_Dtr_ETA, &b_Jet_Dtr_ETA);
   fChain->SetBranchAddress("Jet_Dtr_XVTX", Jet_Dtr_XVTX, &b_Jet_Dtr_XVTX);
   fChain->SetBranchAddress("Jet_Dtr_YVTX", Jet_Dtr_YVTX, &b_Jet_Dtr_YVTX);
   fChain->SetBranchAddress("Jet_Dtr_ZVTX", Jet_Dtr_ZVTX, &b_Jet_Dtr_ZVTX);
   fChain->SetBranchAddress("Jet_Dtr_R", Jet_Dtr_R, &b_Jet_Dtr_R);
   fChain->SetBranchAddress("Jet_Dtr_JT", Jet_Dtr_JT, &b_Jet_Dtr_JT);
   fChain->SetBranchAddress("Jet_Dtr_Z", Jet_Dtr_Z, &b_Jet_Dtr_Z);
   fChain->SetBranchAddress("Jet_Dtr_TrackType", Jet_Dtr_TrackType, &b_Jet_Dtr_TrackType);
   fChain->SetBranchAddress("Jet_Dtr_TrackKey", Jet_Dtr_TrackKey, &b_Jet_Dtr_TrackKey);
   fChain->SetBranchAddress("Jet_Dtr_TrackChi2", Jet_Dtr_TrackChi2, &b_Jet_Dtr_TrackChi2);
   fChain->SetBranchAddress("Jet_Dtr_TrackNDF", Jet_Dtr_TrackNDF, &b_Jet_Dtr_TrackNDF);
   fChain->SetBranchAddress("Jet_Dtr_TrackPCHI2", Jet_Dtr_TrackPCHI2, &b_Jet_Dtr_TrackPCHI2);
   fChain->SetBranchAddress("Jet_Dtr_PFType", Jet_Dtr_PFType, &b_Jet_Dtr_PFType);
   fChain->SetBranchAddress("Jet_Dtr_PFDaughterType", Jet_Dtr_PFDaughterType, &b_Jet_Dtr_PFDaughterType);
   fChain->SetBranchAddress("Jet_Dtr_PFclustype", Jet_Dtr_PFclustype, &b_Jet_Dtr_PFclustype);
   fChain->SetBranchAddress("Jet_Dtr_PFclusE", Jet_Dtr_PFclusE, &b_Jet_Dtr_PFclusE);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_KEY", Jet_Dtr_TRUE_KEY, &b_Jet_Dtr_TRUE_KEY);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_ID", Jet_Dtr_TRUE_ID, &b_Jet_Dtr_TRUE_ID);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_ThreeCharge", Jet_Dtr_TRUE_ThreeCharge, &b_Jet_Dtr_TRUE_ThreeCharge);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_IsMeson", Jet_Dtr_TRUE_IsMeson, &b_Jet_Dtr_TRUE_IsMeson);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_IsBaryon", Jet_Dtr_TRUE_IsBaryon, &b_Jet_Dtr_TRUE_IsBaryon);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_IsStrange", Jet_Dtr_TRUE_IsStrange, &b_Jet_Dtr_TRUE_IsStrange);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_PX", Jet_Dtr_TRUE_PX, &b_Jet_Dtr_TRUE_PX);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_PY", Jet_Dtr_TRUE_PY, &b_Jet_Dtr_TRUE_PY);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_PZ", Jet_Dtr_TRUE_PZ, &b_Jet_Dtr_TRUE_PZ);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_E", Jet_Dtr_TRUE_E, &b_Jet_Dtr_TRUE_E);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_P", Jet_Dtr_TRUE_P, &b_Jet_Dtr_TRUE_P);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_PT", Jet_Dtr_TRUE_PT, &b_Jet_Dtr_TRUE_PT);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_M", Jet_Dtr_TRUE_M, &b_Jet_Dtr_TRUE_M);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_PHI", Jet_Dtr_TRUE_PHI, &b_Jet_Dtr_TRUE_PHI);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_ETA", Jet_Dtr_TRUE_ETA, &b_Jet_Dtr_TRUE_ETA);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_XVTX", Jet_Dtr_TRUE_XVTX, &b_Jet_Dtr_TRUE_XVTX);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_YVTX", Jet_Dtr_TRUE_YVTX, &b_Jet_Dtr_TRUE_YVTX);
   fChain->SetBranchAddress("Jet_Dtr_TRUE_ZVTX", Jet_Dtr_TRUE_ZVTX, &b_Jet_Dtr_TRUE_ZVTX);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("EventInSequence", &EventInSequence, &b_EventInSequence);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("BCID", &BCID, &b_BCID);
   fChain->SetBranchAddress("BCType", &BCType, &b_BCType);
   fChain->SetBranchAddress("OdinTCK", &OdinTCK, &b_OdinTCK);
   fChain->SetBranchAddress("L0DUTCK", &L0DUTCK, &b_L0DUTCK);
   fChain->SetBranchAddress("HLT1TCK", &HLT1TCK, &b_HLT1TCK);
   fChain->SetBranchAddress("HLT2TCK", &HLT2TCK, &b_HLT2TCK);
   fChain->SetBranchAddress("GpsTime", &GpsTime, &b_GpsTime);
   fChain->SetBranchAddress("Polarity", &Polarity, &b_Polarity);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVX", PVX, &b_PVX);
   fChain->SetBranchAddress("PVY", PVY, &b_PVY);
   fChain->SetBranchAddress("PVZ", PVZ, &b_PVZ);
   fChain->SetBranchAddress("PVXERR", PVXERR, &b_PVXERR);
   fChain->SetBranchAddress("PVYERR", PVYERR, &b_PVYERR);
   fChain->SetBranchAddress("PVZERR", PVZERR, &b_PVZERR);
   fChain->SetBranchAddress("PVCHI2", PVCHI2, &b_PVCHI2);
   fChain->SetBranchAddress("PVNDOF", PVNDOF, &b_PVNDOF);
   fChain->SetBranchAddress("PVNTRACKS", PVNTRACKS, &b_PVNTRACKS);
   fChain->SetBranchAddress("nPVs", &nPVs, &b_nPVs);
   fChain->SetBranchAddress("nTracks", &nTracks, &b_nTracks);
   fChain->SetBranchAddress("nLongTracks", &nLongTracks, &b_nLongTracks);
   fChain->SetBranchAddress("nDownstreamTracks", &nDownstreamTracks, &b_nDownstreamTracks);
   fChain->SetBranchAddress("nUpstreamTracks", &nUpstreamTracks, &b_nUpstreamTracks);
   fChain->SetBranchAddress("nVeloTracks", &nVeloTracks, &b_nVeloTracks);
   fChain->SetBranchAddress("nTTracks", &nTTracks, &b_nTTracks);
   fChain->SetBranchAddress("nBackTracks", &nBackTracks, &b_nBackTracks);
   fChain->SetBranchAddress("nRich1Hits", &nRich1Hits, &b_nRich1Hits);
   fChain->SetBranchAddress("nRich2Hits", &nRich2Hits, &b_nRich2Hits);
   fChain->SetBranchAddress("nVeloClusters", &nVeloClusters, &b_nVeloClusters);
   fChain->SetBranchAddress("nITClusters", &nITClusters, &b_nITClusters);
   fChain->SetBranchAddress("nTTClusters", &nTTClusters, &b_nTTClusters);
   fChain->SetBranchAddress("nOTClusters", &nOTClusters, &b_nOTClusters);
   fChain->SetBranchAddress("nSPDHits", &nSPDHits, &b_nSPDHits);
   fChain->SetBranchAddress("nMuonCoordsS0", &nMuonCoordsS0, &b_nMuonCoordsS0);
   fChain->SetBranchAddress("nMuonCoordsS1", &nMuonCoordsS1, &b_nMuonCoordsS1);
   fChain->SetBranchAddress("nMuonCoordsS2", &nMuonCoordsS2, &b_nMuonCoordsS2);
   fChain->SetBranchAddress("nMuonCoordsS3", &nMuonCoordsS3, &b_nMuonCoordsS3);
   fChain->SetBranchAddress("nMuonCoordsS4", &nMuonCoordsS4, &b_nMuonCoordsS4);
   fChain->SetBranchAddress("nMuonTracks", &nMuonTracks, &b_nMuonTracks);
   fChain->SetBranchAddress("StrippingZ02MuMuLineDecision", &StrippingZ02MuMuLineDecision, &b_StrippingZ02MuMuLineDecision);
   Notify();
}

Bool_t TZJetsData::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void TZJetsData::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t TZJetsData::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef TZJetsData_cxx
