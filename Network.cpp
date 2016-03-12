#include "Network.h"

// Sets number of neurons to given network size;
Network::Network(unsigned int size)
{
    for(int i = 0; i < size; i++)
    {
        nodes.push_back(Neuron(size));
    }
}

// Passes each neuron to the update function of every other neuron;
void Network::update()
{
    for(int i = 0; i < nodes.size(); i++)
    {
        if(nodes[i].is_firing())
            nodes[i].reset();
        for(int j = 0; j < nodes.size(); j++)
        {
            if(i != j)
                nodes[i].update(nodes[j], j);
        }
    }
}

// Returns firing state of given neuron;
bool Network::get_firing_state(unsigned int neuron)
{
    return nodes[neuron].is_firing();
}
