#ifndef DECAY_FUNCTIONS_H
#define DECAY_FUNCTIONS_H

// Two-body decays
int check_rho_decay(int pid_a, int pid_b, double mass);
int check_kaon0s_decay(int pid_a, int pid_b, double mass);

// Three-body decays
int check_rhopm_decay(int pid_a, int pid_b, int pid_c, double mass);
int check_kaonpm_decay(int pid_a, int pid_b, int pid_c, double mass);

// Four-body decays
int check_kaon0s_decay(int pid_a, int pid_b, int pid_c, int pid_d, double mass);
int check_eta_decay(int pid_a, int pid_b, int pid_c, int pid_d, double mass);
int check_omega_decay(int pid_a, int pid_b, int pid_c, int pid_d, double mass);

#endif