#include <iostream>
#include "Network.h"

int main()
{
    srand(time(NULL));

    std::vector<float> potentials;

    Network net(50, 5, 3);
    float counter = 0;
    while(counter < 100000)
    {
        net.update(.1);
        counter += 1;
    }
}
