
#include "header.h"

int longestSequence(unsigned int parkingRow)
{
    int count;

    count = 0;
    while (parkingRow)
    {
        parkingRow &= (parkingRow << 1);
        count++;
    }
    return (count);
}