#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED

#include <iostream>
#include <fstream>
#include "Neuron.h"
#include "Memory.h"
#include "Probability.h"

#define NodePtrs std::vector<Neuron*>
#define Dist std::vector<Distribution>

class Network
{
    std::vector<Neuron*> nodes;
    std::vector<Probability*> prob;
    NodePtrs inputs;
    NodePtrs outputs;
    Memory memory;
    float timer;
    std::ofstream log;
public:
    Network(unsigned int, unsigned int, unsigned int);
    void update(float);
    bool firing_state(unsigned int);
    int total_activity();
};

#endif // NETWORK_H_INCLUDED
