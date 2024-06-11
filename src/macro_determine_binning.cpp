#include "../include/analysis-constants.h"
#include "../include/names.h"
#include "../include/utils.h"

void macro_determine_binning()
{
    // Open data file 
    TFile* f = new TFile((output_folder+namef_ntuple_dihadron).c_str());

    // Get TNtuple from file
    TNtuple* ntuple = (TNtuple*) f->Get(name_ntuple_data.c_str());

    // Declare the histos to use
    TH1F* h_z     = new TH1F("h_z"    ,"",200,z_min     ,z_max     );
    TH1F* h_kt    = new TH1F("h_kt"   ,"",200,kt_min    ,kt_max    );
    TH1F* h_jetpt = new TH1F("h_jetpt","",200,jet_pt_min,jet_pt_max);

    // Put the data into the histos and get the cumulative distributions
    ntuple->Project("h_z"    ,"nlh_pz/(nlh_pz+lh_pz)",jet_cuts+track_cuts+topological_cuts+Zboson_cuts);
    ntuple->Project("h_kt"   ,"dh_kt"                ,jet_cuts+track_cuts+topological_cuts+Zboson_cuts);
    ntuple->Project("h_jetpt","jet_pt"               ,jet_cuts+track_cuts+topological_cuts+Zboson_cuts);

    TH1F* h_z_cumul     = (TH1F*) h_z->GetCumulative();
    TH1F* h_kt_cumul    = (TH1F*) h_kt->GetCumulative();
    TH1F* h_jetpt_cumul = (TH1F*) h_jetpt->GetCumulative();

    // Determine binning in z
    double entries_bin_z = h_z->Integral()/Nbin_z;
    std::cout<<"The number of entries for z is "<<entries_bin_z<<std::endl;
    std::cout<<"Binning in z : {z_min";
    int counter_z = 1;
    for(int bin = 1 ; bin <= h_z->GetNbinsX() ; bin++)
    {
        double q = h_z_cumul->GetBinContent(bin);

        // Exit when determined last bin
        if(counter_z==Nbin_z) 
        {
            std::cout<<", z_max }"<<std::endl;
            break;
        }
        // Condition to determine limit
        if(q>entries_bin_z*counter_z) 
        {
            counter_z++;

            // Print limits
            std::cout<<", "<<h_z_cumul->GetBinCenter(bin-1);
        }
    }

    // Determine binning in kt
    double entries_bin_kt = h_kt->Integral()/Nbin_kt;
    std::cout<<"The number of entries for kt is "<<entries_bin_kt<<std::endl;
    std::cout<<"Binning in kt : {kt_min";
    int counter_kt = 1;
    for(int bin = 1 ; bin <= h_kt->GetNbinsX() ; bin++)
    {
        double q = h_kt_cumul->GetBinContent(bin);

        // Exit when determined last bin
        if(counter_kt==Nbin_kt) 
        {
            std::cout<<", kt_max}"<<std::endl;
            break;
        }
        // Condition to determine limit
        if(q>entries_bin_kt*counter_kt) 
        {
            counter_kt++;

            // Print limits
            std::cout<<", "<<h_kt_cumul->GetBinCenter(bin-1);
        }
    }
    
    // Close file
    f->Close();

    return 0;
}