#include "Memory.h"

void Memory::set_time(float t)
{
    t_limit = t;
}

bool Memory::add(Neuron* input, int id)
{
    for(int i = 0; i < fired.size(); i++)
    {
        if(fired[i].id() == id)
        {
            return false;
        }
    }
    fired.push_back(FiredInput(input, t_limit, id));
    return true;
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

void Memory::apply(Distribution* dist, int id)
{
    for(int i = 0; i < fired.size(); i++)
    {
        float data = abs(fired[id].time() - fired[i].time());
        dist->add(data);
    }
}

int Memory::size()
{
    return fired.size();
}
