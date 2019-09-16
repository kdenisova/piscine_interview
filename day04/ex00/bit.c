
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getSum(char *a, char *b)
{
    int i;
    int left;
    int res;

    i = strlen(a) - 1;
    left = 0;
    while (i >= 0)
    {
        res = (a[i] - '0') + (b[i] - '0') + left;
        if (res >= 2)
        {
            res = res % 2;
            left = 1;
        }
        else
            left = 0;
        a[i] = res + '0';
        i--;
    }
    a[6] = '\0';//DELETE
    return (a);
}

int toInt(char *bits)
{
    int i;
    int d;
    int sum;

    i = 0;
    d = strlen(bits) - 1;
    sum = 0;
    while (d >= 0)
    {
        sum += (bits[i] - '0') * pow(2, d);
        i++;
        d--;
    }
    return (sum);
}

int main(void)
{
    char a[6] = "000010";
    char b[6] = "000010";
    char *c = getSum(a, b);
    printf("%s\n", c);
    printf("%d\n", toInt(c));
}