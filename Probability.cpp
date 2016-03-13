#include "Probability.h"

Probability::Probability(unsigned int net_size)
{
    for(int i = 0; i < net_size; i++)
    {
        dist.push_back(Distribution());
    }
}

void Probability::add(float data, int id)
{
    dist[id].add(data);
}
