#ifndef KINEMATICAL_FUNCTIONS_H
#define KINEMATICAL_FUNCTIONS_H

#include "TVector3.h"
#include <iostream>

// Return the relative transverse momentum in GeV
double calculate_kt(TVector3* h1_momentum, TVector3* h2_momentum)
{
    return h2_momentum->Mag()*sin(h1_momentum->Angle(*h2_momentum))/1000.;
}

double calculate_z_lh(TVector3* h1_momentum, TVector3* h2_momentum)
{
    return h1_momentum->Z()/(h1_momentum->Z() + h2_momentum->Z());
}

double calculate_z_nlh(TVector3* h1_momentum, TVector3* h2_momentum)
{
    return h2_momentum->Z()/(h1_momentum->Z() + h2_momentum->Z());
}

#endif