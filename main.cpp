#include <iostream>
#include "Network.h"

int main()
{
    srand(time(NULL));

    Network net(100, 10, 5);
    float counter = 0;
    while(counter < 1000)
    {

        net.update(.1);
        counter += 1;
    }
}
