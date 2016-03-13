#ifndef FIREDINPUT_H_INCLUDED
#define FIREDINPUT_H_INCLUDED

#include "Neuron.h"

class FiredInput
{
    Neuron* node;
    float timer;
    unsigned int index;
public:
    FiredInput(Neuron&, float, int);
    bool update(float);
    float time();
    unsigned int id();
};

#endif // FIREDINPUT_H_INCLUDED
