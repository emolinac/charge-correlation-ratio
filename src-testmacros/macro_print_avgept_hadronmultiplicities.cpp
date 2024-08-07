#include <iostream>
#include "../include/analysis-constants.h"
#include "../include/kinematical-functions.h"
#include "../include/directories.h"
#include "../include/names.h"
#include "../include/utils-algorithms.h"
#include "../include/TZJetsData.h"
#include "../include/TZJetsData.C"

void macro_print_avgept_hadronmultiplicities()
{
    // Open data!
    TZJetsData* datatree = new TZJetsData();

    // Declare arrays
    double pt_array[datatree->Jet_NDtr];
    double multiplicity_array[datatree->Jet_NDtr];

    for(int evt = 0 ; evt < datatree->fChain->GetEntries() ; evt++)
    {
        // Access entry of tree
        datatree->GetEntry(evt);

        // Get the avge Pt in the lab frame
        double sum=0; int N=0;
        for(int entry = 0 ; entry < datatree->Jet_NDtr ; entry++)
        {
            if(datatree->Jet_Dtr_ID[entry]==0||datatree->Jet_Dtr_ThreeCharge[entry]==0) continue;

            sum += datatree->Jet_Dtr_PT[entry]/1000.; N++;
        }

        int nch_loop = N;

        // Assign values
        pt_array[nch_loop] += sum;
        multiplicity_array[nch_loop] += N;
    }

    // Assign point in graph
    TGraph* g = new TGraph();
    int point = 0;
    for(int nch = 0 ; nch < 50 ; nch++)
    {
        if(multiplicity_array[nch]==0) continue;

        double avge = pt_array[nch]/multiplicity_array[nch];

        g->SetPoint(point, nch+1, avge);
        point++;
    }

    g->Draw("AP");

    g->SetTitle(";n_{ch};<p_{t}>(GeV)");
    g->SetMarkerStyle(20);
    g->SetMarkerColor(kViolet);
}
