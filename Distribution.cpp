#include "Distribution.h"

float Distribution::mean()
{
    float m = 0;
    for(int i = 0; i < data.size(); i++)
    {
        m += data[i];
    }
    m /= data.size();
    return m;
}

float Distribution::variance()
{
    float v = 0;
    for(int i = 0; i < data.size(); i++)
    {
        v += pow(data[i] - mean(), 2);
    }
    v /= data.size()-1;
    return v;
}

float Distribution::deviation()
{
    float d = sqrt(variance());
    return d;
}

void Distribution::add(float v)
{
    data.push_back(v);
}
