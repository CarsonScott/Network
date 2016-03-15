#include "FiredInput.h"

FiredInput::FiredInput(Neuron* input, float t_limit, int id)
{
    node = input;
    timer = t_limit;
    index = id;
}

bool FiredInput::update(float dt)
{
    timer -= dt;
    if(timer <= 0)
        return false;
    return true;
}

float FiredInput::time()
{
    return timer;
}

unsigned int FiredInput::id()
{
    return index;
}
