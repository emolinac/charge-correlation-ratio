BIN   := ./bin
INC   := ./include
SRC   := ./src
SRC_P := ./src-purity

CXX    := g++ -std=c++11
CFLAGS := -Wall -g

ROOTCFLAGS  := $(shell root-config --cflags)
ROOTLDFLAGS := $(shell root-config --ldflags)
ROOTINCDIR  := $(shell root-config --incdir)
ROOTLIBS    := $(shell root-config --libs) -lEG

all: ${BIN}/create_ntuples \
	 ${BIN}/calculate_cuts_impact ${BIN}/calculate_rc_z ${BIN}/calculate_rc_jt ${BIN}/calculate_rc_jet_pt \
	 ${BIN}/create_purity_ntuple ${BIN}/calculate_rc_jet_pt_purity ${BIN}/calculate_rc_z_purity

${BIN}/calculate_cuts_impact: ${SRC}/calculate_cuts_impact.cpp
	${CXX} ${ROOTCFLAGS} ${SRC}/calculate_cuts_impact.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_cuts_impact

${BIN}/create_ntuples: ${SRC}/create_ntuples.cpp
	${CXX} ${ROOTCFLAGS} ${SRC}/create_ntuples.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/create_ntuples

${BIN}/create_purity_ntuple: ${SRC_P}/create_purity_ntuple.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_P}/create_purity_ntuple.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/create_purity_ntuple

${BIN}/calculate_rc_z: ${SRC}/calculate_rc_z.cpp
	${CXX} ${ROOTCFLAGS} ${SRC}/calculate_rc_z.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_z

${BIN}/calculate_rc_jt: ${SRC}/calculate_rc_jt.cpp
	${CXX} ${ROOTCFLAGS} ${SRC}/calculate_rc_jt.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_jt

${BIN}/calculate_rc_jet_pt: ${SRC}/calculate_rc_jet_pt.cpp
	${CXX} ${ROOTCFLAGS} ${SRC}/calculate_rc_jet_pt.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_jet_pt

${BIN}/calculate_rc_jet_pt_purity: ${SRC_P}/calculate_rc_jet_pt_purity.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_P}/calculate_rc_jet_pt_purity.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_jet_pt_purity

${BIN}/calculate_rc_z_purity: ${SRC_P}/calculate_rc_z_purity.cpp
	${CXX} ${ROOTCFLAGS} ${SRC_P}/calculate_rc_z_purity.cpp -I${INC} ${ROOTLIBS} -o ${BIN}/calculate_rc_z_purity

clean:
	rm ${BIN}/*
