#include <stdio.h>

int minJumps(int arr[], int n)
{
    if (arr[0] == 0) return -1;

    int jumps = 0;
    int currReacy = 0;
    int maxReach = 0;

    
    for (int i = 0; i < n - 1; i++)
    {
        maxReach = (maxReach > i + arr[i]) ? maxReach : (i + arr[i]);

        if (maxReach >= n - 1)
        {
            return jumps + 1;
        }

        // Current Reachable index increment the Jump as we reached the reach able index 
        if (i == currReacy)
        {
            return  -1;
        }

        else {
            jumps++;
            currReacy = maxReach;
        }
    }
    return -1;

}



int main()
{
    int arr[] = {1, 3, 2, 2, 1, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", minJumps(arr, n));
    return 0;
}
/*
https://www.geeksforgeeks.org/dsa/minimum-number-jumps-reach-endset-2on-solution/


*/