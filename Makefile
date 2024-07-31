BIN   := ./bin
INC   := ./include
SRC   := ./src
SRC_MU:= ./src-effmuons
SRC_P := ./src-purity
SRC_R := ./src-resolution
SRC_D := ./src-decays
SRC_U := ./src-unfold

CXX    := g++ -std=c++11
CFLAGS := -Wall -g

ROOTCFLAGS  := $(shell root-config --cflags)
ROOTLDFLAGS := $(shell root-config --ldflags)
ROOTINCDIR  := $(shell root-config --incdir)
ROOTLIBS    := $(shell root-config --libs) -lEG

all: ${BIN}/create_ntuples \
	 ${BIN}/calculate_cuts_impact ${BIN}/calculate_rc_z ${BIN}/calculate_rc_kt ${BIN}/calculate_rc_jet_pt \
	 ${BIN}/create_purity_ntuple ${BIN}/calculate_rc_jet_pt_purity ${BIN}/calculate_rc_z_purity ${BIN}/calculate_rc_kt_purity \
	 ${BIN}/create_decays_ntuple ${BIN}/create_resolution_ntuple ${BIN}/create_invmass_ntuple \
	 ${BIN}/create_invmasstrio_ntuple ${BIN}/create_datadecays_ntuple ${BIN}/calculate_rc_z_datadecays ${BIN}/calculate_rc_kt_datadecays ${BIN}/calculate_rc_jet_pt_datadecays

${BIN}/calculate_cuts_impact: ${SRC}/calculate_cuts_impact.cpp
	${CXX} ${ROOTCFLAGS} ${SRC}/calculate_cuts_impact.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_cuts_impact

${BIN}/calculate_rc_z_datadecays: ${SRC_D}/calculate_rc_z_datadecays.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_D}/calculate_rc_z_datadecays.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_z_datadecays

${BIN}/calculate_rc_kt_datadecays: ${SRC_D}/calculate_rc_kt_datadecays.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_D}/calculate_rc_kt_datadecays.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_kt_datadecays

${BIN}/calculate_rc_jet_pt_datadecays: ${SRC_D}/calculate_rc_jet_pt_datadecays.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_D}/calculate_rc_jet_pt_datadecays.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_jet_pt_datadecays

${BIN}/create_invmass_ntuple: ${SRC_D}/create_invmass_ntuple.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_D}/create_invmass_ntuple.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/create_invmass_ntuple

${BIN}/create_invmasstrio_ntuple: ${SRC_D}/create_invmasstrio_ntuple.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_D}/create_invmasstrio_ntuple.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/create_invmasstrio_ntuple

${BIN}/create_ntuples: ${SRC}/create_ntuples.cpp
	${CXX} ${ROOTCFLAGS} ${SRC}/create_ntuples.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/create_ntuples

${BIN}/create_purity_ntuple: ${SRC_P}/create_purity_ntuple.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_P}/create_purity_ntuple.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/create_purity_ntuple

${BIN}/create_resolution_ntuple: ${SRC_R}/create_resolution_ntuple.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_R}/create_resolution_ntuple.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/create_resolution_ntuple

${BIN}/create_decays_ntuple: ${SRC_D}/create_decays_ntuple.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_D}/create_decays_ntuple.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/create_decays_ntuple

${BIN}/create_datadecays_ntuple: ${SRC_D}/create_datadecays_ntuple.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_D}/create_datadecays_ntuple.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/create_datadecays_ntuple

${BIN}/calculate_rc_z: ${SRC}/calculate_rc_z.cpp
	${CXX} ${ROOTCFLAGS} ${SRC}/calculate_rc_z.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_z

${BIN}/calculate_rc_kt: ${SRC}/calculate_rc_kt.cpp
	${CXX} ${ROOTCFLAGS} ${SRC}/calculate_rc_kt.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_kt

${BIN}/calculate_rc_jet_pt: ${SRC}/calculate_rc_jet_pt.cpp
	${CXX} ${ROOTCFLAGS} ${SRC}/calculate_rc_jet_pt.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_jet_pt

${BIN}/calculate_rc_jet_pt_purity: ${SRC_P}/calculate_rc_jet_pt_purity.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_P}/calculate_rc_jet_pt_purity.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_jet_pt_purity

${BIN}/calculate_rc_z_purity: ${SRC_P}/calculate_rc_z_purity.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_P}/calculate_rc_z_purity.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_z_purity

${BIN}/calculate_rc_kt_purity: ${SRC_P}/calculate_rc_kt_purity.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_P}/calculate_rc_kt_purity.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_kt_purity

clean:
	rm ${BIN}/*
