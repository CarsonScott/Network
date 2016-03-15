#ifndef PROBABILITY_H_INCLUDED
#define PROBABILITY_H_INCLUDED

#include <vector>
#include "Distribution.h"

class Probability
{
    std::vector<Distribution*> dist;
public:
    Probability(unsigned int);
    void add(float, int);

    Distribution& distribution(unsigned int);
    unsigned int size();
};

#endif // PROBABILITY_H_INCLUDED
