
#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
    int pos;
    int one;

    if (parkingRow == 0)
        return (-1);
    pos = 0;
    one = 1;
    while (!(parkingRow & one))
    {
        one = one << 1;
        pos++;
    }
    return (pos);
}