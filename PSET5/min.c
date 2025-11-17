#include <stdio.h>

long long int findMinProduct(int arr[], int n)
{
    if (n == 0) 
    {
        return  0;
    }

    int min_val = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i]<min_val)
        {
            min_val = arr[i];
        }
    }

    return min_val;
}

int main()
{

    int arr[] = {3,4,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minProduct = findMinProduct(arr, n);
    printf("The minimum product of two elements is: %d\n", minProduct);
    return 0;

/*
    int arr[] = {-3, -4, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minProduct = findMinProduct(arr, n);
    printf("The minimum product of two elements is: %d\n", minProduct);
    return 0; 
*/
}


/*
    Counting negative numbers, zeros, and finding the largest negative number (closest to zero).
    Handling the all-positive case.
    Handling the all-zero or positive-and-zero cases.
    Handling negative number cases based on their count. 
*/