#include <stdio.h>


int main()
{
    int arr[] = {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,131,132,133,134,135,136,138,139,140,141,142,143,144,145,146,147,148,149,150};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 137;

    int i = 0;
    int j = size - 1;
    int mid;

    while (i <= j)
    {
        mid = i + (j - i) / 2;
        if (arr[mid] == target)
        {
            printf("Found %d at index %d\n", target, mid);
            return 0;
        }
        else
        {
            printf("%d not found in the array\n", target);
            printf("It should be at index %d\n", mid);
            return 0;
        }
    }
}

/*
 *
 Given the array
 Arr = {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,131,132,133,134,135,136,138,139,140,141,142,143,144,145,146,147,148,149,150}

 Find the position where 137 is, or if 137 is not in the list, find the position where 137 should be. Your program should run in O(log n) time.

*/
