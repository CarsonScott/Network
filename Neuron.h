#ifndef NEURON_H_INCLUDED
#define NEURON_H_INCLUDED

#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

class Neuron
{
    float charge;
    float limit;
    float threshold;
    float w_increase;
    float w_decrease;
    std::vector<float> weights;
public:
    Neuron(unsigned int);
    void reset();
    bool firing();
    float potential();
    void update(Neuron*, unsigned int);
    void activate();
};

#endif // NEURON_H_INCLUDED
