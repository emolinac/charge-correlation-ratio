#ifndef DECAY_FUNCTIONS_H
#define DECAY_FUNCTIONS_H

#include "analysis-constants.h"

// Convention: first particles had to be a hadron

int check_rho_decay(int pid_a, int pid_b, double mass)
{
    int pip_counter = 0; int pim_counter = 0;

    // Check final state pions
    if(pid_a==pip_id) pip_counter++;
    if(pid_b==pip_id) pip_counter++;
    if(pid_a==pim_id) pim_counter++;
    if(pid_b==pim_id) pim_counter++;

    // Check decay content
    if(pip_counter!=1||pim_counter!=1) return 0;

    // Check mass window of the rho zero meson
    if((mass>(rho_mass-mass_res))&&(mass<(rho_mass+mass_res))) {std::cout<<"Rho found! "<<pid_a<<", "<<pid_b<<" , m="<<mass<<std::endl; return 1;}

    return 0;
}

int check_kaon0s_decay(int pid_a, int pid_b, double mass)
{
    int pip_counter = 0; int pim_counter = 0;

    // Check final state pions
    if(pid_a==pip_id) pip_counter++;
    if(pid_b==pip_id) pip_counter++;
    if(pid_a==pim_id) pim_counter++;
    if(pid_b==pim_id) pim_counter++;

    // Check decay content
    if(pip_counter!=1||pim_counter!=1) return 0;
    
    // Check mass window of the kaon zero short meson
    if((mass>(kaon_mass-mass_res))&&(mass<(kaon_mass+mass_res))){std::cout<<"K0short found! "<<pid_a<<", "<<pid_b<<" , m="<<mass<<std::endl; return 1;}

    return 0;
}

int check_rhopm_decay(int pid_a, int pid_b, int pid_c, double mass)
{
    int pi_counter = 0; int gamma_counter = 0;

    // Check final state pions
    if(pid_a==pip_id||pid_a==pim_id) pi_counter++;
    if(pid_b==pip_id||pid_b==pim_id) pi_counter++;
    if(pid_c==pip_id||pid_c==pim_id) pi_counter++;

    // Check final state photons
    if(pid_a==gamma_id) gamma_counter++;
    if(pid_b==gamma_id) gamma_counter++;
    if(pid_c==gamma_id) gamma_counter++;
    
    // Check decay content
    if(pi_counter!=1||gamma_counter!=2) return 0;
    
    // Check mass window of the rhop/rhom meson
    if((mass>(rho_mass-mass_res))&&(mass<(rho_mass+mass_res))) {std::cout<<"Rhopm found! "<<pid_a<<", "<<pid_b<<", "<<pid_c<<" , m="<<mass<<std::endl; return 1;}

    return 0;
}

int check_kaonpm_decay(int pid_a, int pid_b, int pid_c, double mass)
{
    int pi_counter = 0; int gamma_counter = 0;

    // Check final state pions
    if(pid_a==pip_id||pid_a==pim_id) pi_counter++;
    if(pid_b==pip_id||pid_b==pim_id) pi_counter++;
    if(pid_c==pip_id||pid_c==pim_id) pi_counter++;

    // Check final state photons
    if(pid_a==gamma_id) gamma_counter++;
    if(pid_b==gamma_id) gamma_counter++;
    if(pid_c==gamma_id) gamma_counter++;
    
    // Check decay content
    if(pi_counter!=1||gamma_counter!=2) return 0;
    
    // Check mass window of the charged kaon meson
    if((mass>(kaonm_mass-mass_res))&&(mass<(kaonm_mass+mass_res))) {std::cout<<"Kaonpm found! "<<pid_a<<", "<<pid_b<<", "<<pid_c<<" , m="<<mass<<std::endl; return 1;}

    return 0;
}

int check_kaon0s_decay(int pid_a, int pid_b, int pid_c, int pid_d, double mass)
{
    int gamma_counter = 0;

    // Check final state photons
    if(pid_a==gamma_id) gamma_counter++;
    if(pid_b==gamma_id) gamma_counter++;
    if(pid_c==gamma_id) gamma_counter++;
    if(pid_d==gamma_id) gamma_counter++;
    
    // Check decay content
    if(gamma_counter!=4) return 0;
    
    // Check mass window of the kaon zero short meson
    if((mass>(kaon_mass-mass_res))&&(mass<(kaon_mass+mass_res))) {std::cout<<"K0short found! "<<pid_a<<", "<<pid_b<<", "<<pid_c<<", "<<pid_d<<" , m="<<mass<<std::endl; return 1;}

    return 0;
}

int check_eta_decay(int pid_a, int pid_b, int pid_c, int pid_d, double mass)
{
    int pip_counter = 0; int pim_counter = 0; int gamma_counter = 0;

    // Check final state positive pions
    if(pid_a==pip_id) pip_counter++;
    if(pid_b==pip_id) pip_counter++;
    if(pid_c==pip_id) pip_counter++;
    if(pid_d==pip_id) pip_counter++;
    
    // Check final state negative pions
    if(pid_a==pim_id) pim_counter++;
    if(pid_b==pim_id) pim_counter++;
    if(pid_c==pim_id) pim_counter++;
    if(pid_d==pim_id) pim_counter++;
    
    // Check final state photons
    if(pid_a==gamma_id) gamma_counter++;
    if(pid_b==gamma_id) gamma_counter++;
    if(pid_c==gamma_id) gamma_counter++;
    if(pid_d==gamma_id) gamma_counter++;

    // Check decay content
    if(pip_counter!=1||pim_counter!=1||gamma_counter!=2) return 0;
    
    // Check mass window of the eta meson
    if((mass>(eta_mass-mass_res))&&(mass<(eta_mass+mass_res))) {std::cout<<"Eta found! "<<pid_a<<", "<<pid_b<<", "<<pid_c<<", "<<pid_d<<" , m="<<mass<<std::endl; return 1;}

    return 0;
}

int check_omega_decay(int pid_a, int pid_b, int pid_c, int pid_d, double mass)
{
    int pip_counter = 0; int pim_counter = 0; int gamma_counter = 0;

    // Check final state positive pions
    if(pid_a==pip_id) pip_counter++;
    if(pid_b==pip_id) pip_counter++;
    if(pid_c==pip_id) pip_counter++;
    if(pid_d==pip_id) pip_counter++;
    
    // Check final state negative pions
    if(pid_a==pim_id) pim_counter++;
    if(pid_b==pim_id) pim_counter++;
    if(pid_c==pim_id) pim_counter++;
    if(pid_d==pim_id) pim_counter++;
    
    // Check final state photons
    if(pid_a==gamma_id) gamma_counter++;
    if(pid_b==gamma_id) gamma_counter++;
    if(pid_c==gamma_id) gamma_counter++;
    if(pid_d==gamma_id) gamma_counter++;

    // Check decay content
    if(pip_counter!=1||pim_counter!=1||gamma_counter!=2) return 0;
    
    // Check mass window of the eta meson
    if((mass>(omega_mass-mass_res))&&(mass<(omega_mass+mass_res))) {std::cout<<"Omega found! "<<pid_a<<", "<<pid_b<<", "<<pid_c<<", "<<pid_d<<" , m="<<mass<<std::endl; return 1;}

    return 0;
}

#endif