#include <stdio.h>

void rev(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;

    rev(arr,l + 1, r - 1);

}

int main() 
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    rev(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

// my goat 
//https://www.geeksforgeeks.org/c/c-reverse-array/