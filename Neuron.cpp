#include "Neuron.h"

// Sets number of weights to match network size;
Neuron::Neuron(unsigned int net_size)
{
    for(int i = 0; i < net_size; i++)
    {
        weights.push_back(rand()%100/100);
    }

    threshold = 0;
    charge = -1;
    limit = 1;
    w_increase = 1/net_size;
    w_decrease = 1/pow(net_size, 2);
}

// Sets charge back to zero (presumably) after firing;
void Neuron::reset()
{
    charge = -1;
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
    else
        return 0;
}

// Multiplies given neuron's potential by it's corresponding weight, adds to charge;
void Neuron::update(Neuron* neuron, unsigned int index)
{
    charge += neuron->potential() * weights[index];
    if(charge < -1)
        charge = -1;
    if(charge > 1)
        charge = 1;

    if(neuron->firing()){
        weights[index] += w_increase;
        if(weights[index] > 1)
            weights[index] = 1;
    }
    else
    {
        weights[index] -= w_decrease;
        if(weights[index] < 0)
            weights[index] = 0;
    }
}

void Neuron::activate()
{
    charge = limit;
}
