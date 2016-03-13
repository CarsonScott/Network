#ifndef PROBABILITY_H_INCLUDED
#define PROBABILITY_H_INCLUDED

#include <vector>
#include "Distribution.h"

class Probability
{
    std::vector<Distribution> dist;
public:
    Probability(unsigned int);
    void add(float, int);
};

#endif // PROBABILITY_H_INCLUDED
