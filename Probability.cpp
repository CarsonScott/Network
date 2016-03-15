#include "Probability.h"

Probability::Probability(unsigned int net_size)
{
    for(int i = 0; i < net_size; i++)
    {
        Distribution* d = new Distribution();
        dist.push_back(d);
    }
}

void Probability::add(float data, int id)
{
    dist[id]->add(data);
}

Distribution& Probability::distribution(unsigned int index)
{
    return *dist.at(index);
}

unsigned int Probability::size()
{
    return dist.size();
}
