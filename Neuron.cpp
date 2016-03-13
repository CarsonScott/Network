#include "Neuron.h"

// Sets number of weights to match network size;
Neuron::Neuron(unsigned int net_size)
{
    for(int i = 0; i < net_size; i++)
    {
        weights.push_back(0);
    }
    charge = 0;
    threshold = 1;
    w_increase = 0.02;
    w_decrease = 0.01;
}

// Sets charge back to zero (presumably) after firing;
void Neuron::reset()
{
    charge = 0;
}

// Returns true if charge reaches threshold, otherwise returns false;
bool Neuron::firing()
{
    return charge >= threshold;
}

// Returns charge if firing, otherwise returns zero;
float Neuron::potential()
{
    if(firing())
        return charge;
    return 0;
}

// Multiplies given neuron's potential by it's corresponding weight, adds to charge;
void Neuron::update(Neuron& neuron, unsigned int index)
{
    charge += neuron.potential() * weights[index];
    if(neuron.firing())
        weights[index] += w_increase;
    weights[index] -= w_decrease;
}
