#include <iostream>
#include "../include/analysis-constants.h"
#include "../include/directories.h"
#include "../include/names.h"
#include "../include/utils-algorithms.h"
#include "../include/utils-visual.h"

void macro_calculate_originpercentage()
{
    // Open the file with the ntuples
    TFile* fdecay = new TFile((output_folder+namef_ntuple_decays).c_str());

    // Get the dihadron and decay ntuples
    TNtuple* ntuple_decay = (TNtuple*) fdecay->Get((name_ntuple_decays).c_str());
    
    
    // Get the string breaking fraction NOTE: Most event with parton mothers have the same mother tey are not complementary
    TCut parton_cut = "(lh_motherid<22&&lh_motherid>-10&&nlh_motherid<22&&nlh_motherid>-10)&&(lh_motherid!=0&&nlh_motherid!=0)&&(lh_motherid==nlh_motherid)";

    double lh_pip  = ntuple_decay->GetEntries(parton_cut+"lh_id==211");
    double lh_pim  = ntuple_decay->GetEntries(parton_cut+"lh_id==-211");
    double nlh_pip = ntuple_decay->GetEntries(parton_cut+"nlh_id==211");
    double nlh_pim = ntuple_decay->GetEntries(parton_cut+"nlh_id==-211");

    std::cout<<"Events coming from the same mother ="<<ntuple_decay->GetEntries(parton_cut)<<std::endl;
    std::cout<<"Leading Pi + coming from the same mother = "<<lh_pip<<std::endl;
    std::cout<<"Leading Pi - coming from the same mother = "<<lh_pim<<std::endl;
    std::cout<<"Subleading Pi + coming from the same mother = "<<nlh_pip<<std::endl;
    std::cout<<"Subleading Pi - coming from the same mother = "<<nlh_pim<<std::endl;
    std::cout<<"Pi+ Pi+ coming from the same mother ="<<ntuple_decay->GetEntries(parton_cut+"lh_id==211&&nlh_id==211")<<std::endl;
    std::cout<<"Pi- Pi- coming from the same mother ="<<ntuple_decay->GetEntries(parton_cut+"lh_id==-211&&nlh_id==-211")<<std::endl;
    std::cout<<"Pi+ Pi- coming from the same mother ="<<ntuple_decay->GetEntries(parton_cut+"lh_id==211&&nlh_id==-211")<<std::endl;
    std::cout<<"Pi- Pi+ coming from the same mother ="<<ntuple_decay->GetEntries(parton_cut+"lh_id==-211&&nlh_id==211")<<std::endl;
    
    std::cout<<"---------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"Leading Pi + coming from u fragmentation "<<ntuple_decay->GetEntries(parton_cut+"lh_id==211&&lh_motherid==2")*100./lh_pip<<"\%"<<std::endl;
    std::cout<<"Leading Pi + coming from d fragmentation "<<ntuple_decay->GetEntries(parton_cut+"lh_id==211&&lh_motherid==1")*100./lh_pip<<"\%"<<std::endl;
    std::cout<<"Leading Pi + coming from g fragmentation "<<ntuple_decay->GetEntries(parton_cut+"lh_id==211&&lh_motherid==21")*100./lh_pip<<"\%"<<std::endl;
    std::cout<<"---------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"Leading Pi - coming from u fragmentation "<<ntuple_decay->GetEntries(parton_cut+"lh_id==-211&&lh_motherid==2")*100./lh_pim<<"\%"<<std::endl;
    std::cout<<"Leading Pi - coming from d fragmentation "<<ntuple_decay->GetEntries(parton_cut+"lh_id==-211&&lh_motherid==1")*100./lh_pim<<"\%"<<std::endl;
    std::cout<<"Leading Pi - coming from g fragmentation "<<ntuple_decay->GetEntries(parton_cut+"lh_id==-211&&lh_motherid==21")*100./lh_pim<<"\%"<<std::endl;
    std::cout<<"---------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"Subleading Pi + coming from u fragmentation "<<ntuple_decay->GetEntries(parton_cut+"nlh_id==211&&nlh_motherid==2")*100./nlh_pip<<"\%"<<std::endl;
    std::cout<<"Subleading Pi + coming from d fragmentation "<<ntuple_decay->GetEntries(parton_cut+"nlh_id==211&&nlh_motherid==1")*100./nlh_pip<<"\%"<<std::endl;
    std::cout<<"Subleading Pi + coming from g fragmentation "<<ntuple_decay->GetEntries(parton_cut+"nlh_id==211&&nlh_motherid==21")*100./nlh_pip<<"\%"<<std::endl;
    std::cout<<"---------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"Subleading Pi - coming from u fragmentation "<<ntuple_decay->GetEntries(parton_cut+"nlh_id==-211&&nlh_motherid==2")*100./nlh_pim<<"\%"<<std::endl;
    std::cout<<"Subleading Pi - coming from d fragmentation "<<ntuple_decay->GetEntries(parton_cut+"nlh_id==-211&&nlh_motherid==1")*100./nlh_pim<<"\%"<<std::endl;
    std::cout<<"Subleading Pi - coming from g fragmentation "<<ntuple_decay->GetEntries(parton_cut+"nlh_id==-211&&nlh_motherid==21")*100./nlh_pim<<"\%"<<std::endl;
}