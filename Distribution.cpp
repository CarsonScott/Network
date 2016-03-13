#include "Distribution.h"

float Distribution::mean()
{
    float m = 0;
    for(int i = 0; i < data.size(); i++)
    {
        m += data[i];
    }
    return m/data.size();
}

float Distribution::variance()
{
    float v = 0;
    for(int i = 0; i < data.size(); i++)
    {
        v += pow(data[i] - mean(), 2);
    }
    return v/data.size() -1;
}

float Distribution::deviation()
{
    return sqrt(variance());
}

void Distribution::add(float v)
{
    data.push_back(v);
    expected = mean();
}
