#include "Memory.h"

void Memory::add(Neuron& input, int id)
{
    fired.push_back(FiredInput(input, t_limit, id));
}

void Memory::update(float dt)
{
    for(int i = 0; i < fired.size(); i++)
    {
        if(!fired[i].update(dt))
        {
            fired.erase(fired.begin() + i);
        }
    }
}

void Memory::apply(Distribution& dist, int id)
{
    for(int i = 0; i < fired.size(); i++)
    {
        if(i != id)
        {
            float data = std::abs(fired[i].time() - fired[id].time());
            dist.add(fired[i].time());
        }
    }
}
