#include "Network.h"

// Sets number of neurons to given network size;
Network::Network(unsigned int size, unsigned int in, unsigned int out)
{
    memory.set_time(50);
    for(int i = 0; i < size; i++)
    {
        Neuron* n = new Neuron(size);
        nodes.push_back(n);
        if(i < in)
        {
            inputs.push_back(n);
        }
        else if(i < out)
        {
            outputs.push_back(n);
        }

        Probability* p = new Probability(size);
        prob.push_back(p);
    }
    timer = 0;
    log.open("log.txt");
}

// Passes each neuron to the update function of every other neuron;
void Network::update(float dt)
{
    for(int i = 0; i < nodes.size(); i++)
    {
        if(nodes[i]->firing())
        {
            nodes[i]->reset();
        }
    }

    memory.update(dt);

    if(timer = inputs.size())
    {
        timer = 0;
    }
    timer++;
    inputs[timer]->activate();

    for(int i = 0; i < nodes.size(); i++)
    {
        for(int j = 0; j < nodes.size(); j++)
        {
            nodes[i]->update(nodes[j], j);
        }
        if(nodes[i]->firing())
        {
            memory.add(nodes[i], i);
        }

        log << "\n";
        for(int j = 0; j < prob[i]->size(); j++)
        {
            memory.apply(&prob[i]->distribution(j), j);
            if(prob[i]->size())
            {
                float variance = prob[i]->distribution(j).deviation();
                log << variance << ", ";
            }
        }

    }
}

// Returns firing state of given neuron;
bool Network::firing_state(unsigned int neuron)
{
    return nodes[neuron]->firing();
}

int Network::total_activity()
{
    return memory.size();
}
