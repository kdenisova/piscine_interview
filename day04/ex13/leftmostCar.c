
#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
    int pos;

    pos = -1;
    while (parkingRow)
    {
        parkingRow = parkingRow >> 1;
        pos++;
    }
    return (pos);
}