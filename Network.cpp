#include "Network.h"

// Sets number of neurons to given network size;
Network::Network(unsigned int size, unsigned int in, unsigned int out)
{
    for(int i = 0; i < size; i++)
    {
        nodes.push_back(Neuron(size));
        if(i < in)
        {
            inputs.push_back(&nodes.back());
        }
        else if(i < out)
        {
            outputs.push_back(&nodes.back());
        }
        prob.push_back(Probability(size));
    }
}

// Passes each neuron to the update function of every other neuron;
void Network::update(float dt)
{
    for(int i = 0; i < nodes.size(); i++)
    {
        if(nodes[i].firing())
        {
            memory.add(nodes[i], i);
            nodes[i].reset();
        }
    }

    for(int i = 0; i < nodes.size(); i++)
    {
        for(int j = 0; j < nodes.size(); j++)
        {
            if(i != j)
                nodes[i].update(nodes[j], j);
        }
    }
}

// Returns firing state of given neuron;
bool Network::firing_state(unsigned int neuron)
{
    return nodes[neuron].firing();
}
