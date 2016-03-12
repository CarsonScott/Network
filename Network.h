#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED

#include "Neuron.h"

class Network
{
    std::vector<Neuron> nodes;
public:
    Network(unsigned int);
    void update();
    bool get_firing_state(unsigned int);
};

#endif // NETWORK_H_INCLUDED
