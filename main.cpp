#include <iostream>
#include "Network.h"

int main()
{

    Network net(500, 10, 10);
    for(int i = 0; i < 100; i++)
    {
        net.update(i);
    }
}
