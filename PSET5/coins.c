#include <stdio.h>

int main()
{
    int denom[] = {25,10,5,1};
    int numDenom = sizeof(denom) / sizeof(denom[0]);

    int amount = 63;

    // store
    int coinCounts[numDenom];
    for (int i = 0; i < numDenom; i++)
    {
        coinCounts[i] = 0;
    }

    for (int i = 0; i < numDenom; i++)
    {
        coinCounts[i] = amount / denom[i]; // num of coins in cur denom 
        amount %= denom[i]; // remain
    }

    for (int i = 0; i < numDenom; i++) 
    {
        if (coinCounts[i] > 0) 
        {
            printf("%d x %d cent coin(s)\n", coinCounts[i], denom[i]);
        }
    }
    


    return 0;
}