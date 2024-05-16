#include <iostream>
#include "TFile.h"
#include "TNtuple.h"
#include "analysis-constants.h"
#include "names.h"

int main()
{
    // Display message
    std::cout<<"--------------------------------------------------------------"<<std::endl;
    std::cout<<"This code displays the percentage of data removed by the respective set of cuts"<<std::endl;

    // Open dihadron TNtuple
    TFile* f = new TFile((output_folder+namef_ntuple_dihadron).c_str());
    TNtuple* ntuple_data   = (TNtuple*) f->Get(name_ntuple_data.c_str());
    TNtuple* ntuple_mc     = (TNtuple*) f->Get(name_ntuple_mc.c_str());
    TNtuple* ntuple_mcreco = (TNtuple*) f->Get(name_ntuple_mcreco.c_str());

    double nentries_data   = ntuple_data->GetEntries();
    double nentries_mc     = ntuple_mc->GetEntries();
    double nentries_mcreco = ntuple_mcreco->GetEntries();

    // Calculate stats for data
    std::cout<<"--------------------------DATA--------------------------------"<<std::endl;
    double data_jetcuts         = ntuple_data->GetEntries(jet_cuts);
    double data_trackcuts       = ntuple_data->GetEntries(track_cuts);
    double data_topologicalcuts = ntuple_data->GetEntries(topological_cuts);
    double data_zboson          = ntuple_data->GetEntries(Zboson_cuts);
    double data_all             = ntuple_data->GetEntries(Zboson_cuts&&topological_cuts&&track_cuts&&jet_cuts);

    std::cout<<"jetcuts   : "<<100.-data_jetcuts*100./nentries_data<<std::endl;
    std::cout<<"trackcuts : "<<100.-data_trackcuts*100./nentries_data<<std::endl;
    std::cout<<"topocuts  : "<<100.-data_topologicalcuts*100./nentries_data<<std::endl;
    std::cout<<"Zbosoncuts: "<<100.-data_zboson*100./nentries_data<<std::endl;
    std::cout<<"All cuts  : "<<100.-data_all*100./nentries_data<<std::endl;

    std::cout<<"Jet remaining";

    // Calculate stats for mc
    std::cout<<"--------------------------MC--------------------------------"<<std::endl;
    double mc_jetcuts         = ntuple_mc->GetEntries(jet_cuts);
    double mc_trackcuts       = ntuple_mc->GetEntries(trackmc_cuts);
    double mc_topologicalcuts = ntuple_mc->GetEntries(topological_cuts);
    double mc_zboson          = ntuple_mc->GetEntries(Zbosonmc_cuts);

    std::cout<<"jetcuts   : "<<100.-mc_jetcuts*100./nentries_mc<<std::endl;
    std::cout<<"trackcuts : "<<100.-mc_trackcuts*100./nentries_mc<<std::endl;
    std::cout<<"topocuts  : "<<100.-mc_topologicalcuts*100./nentries_mc<<std::endl;
    std::cout<<"Zbosoncuts: "<<100.-mc_zboson*100./nentries_mc<<std::endl;

    // Calculate stats for mcreco
    std::cout<<"--------------------------MCRECO--------------------------------"<<std::endl;
    double mcreco_jetcuts         = ntuple_mcreco->GetEntries(jet_cuts);
    double mcreco_trackcuts       = ntuple_mcreco->GetEntries(track_cuts);
    double mcreco_topologicalcuts = ntuple_mcreco->GetEntries(topological_cuts);
    double mcreco_zboson          = ntuple_mcreco->GetEntries(Zboson_cuts);

    std::cout<<"jetcuts   : "<<100.-mcreco_jetcuts*100./nentries_mcreco<<std::endl;
    std::cout<<"trackcuts : "<<100.-mcreco_trackcuts*100./nentries_mcreco<<std::endl;
    std::cout<<"topocuts  : "<<100.-mcreco_topologicalcuts*100./nentries_mcreco<<std::endl;
    std::cout<<"Zbosoncuts: "<<100.-mcreco_zboson*100./nentries_mcreco<<std::endl;

    return 0;
}