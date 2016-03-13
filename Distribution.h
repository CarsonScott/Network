#ifndef DISTRIBUTION_H_INCLUDED
#define DISTRIBUTION_H_INCLUDED

#include <vector>
#include <cmath>

#include "FiredInput.h"

class Distribution
{
    float expected;
    std::vector<float> data;
public:
    float mean();
    float variance();
    float deviation();
    void add(float);
};

#endif // DISTRIBUTION_H_INCLUDED
