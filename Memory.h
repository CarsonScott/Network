#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

#include <vector>
#include <cmath>
#include "FiredInput.h"
#include "Distribution.h"

#define NodePtrs std::vector<Neuron*>

class Memory
{
    float t_limit;
    std::vector<FiredInput> fired;
public:
    void add(NodePtrs&);
    void add(Neuron&, int);
    void update(float);
    void apply(Distribution&, int);
};

#endif // MEMORY_H_INCLUDED
