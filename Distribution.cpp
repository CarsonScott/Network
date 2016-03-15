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
    if(data.size() > 3)
    {
        variation = (variation*(data.size()-2) + pow(data.back() - expected, 2)) / (data.size() -1);
    }
    else
    {
        float v = 0;
        for(int i = 0; i < data.size(); i++)
        {
            v += pow(data[i] - expected, 2);
        }
        variation = v / (data.size()-1);
    }
    return variation;
}

float Distribution::deviation()
{
    float d = sqrt(variance());
    return d;
}

void Distribution::add(float v)
{
    data.push_back(v);

    if(data.size() > 1)
    {
        expected = (expected*(data.size()-1) + v)/data.size();
    }
    else
    {
        expected = mean();
    }
}
