#include <stdio.h>


int getSecondLargest(int arr[], int n) 
{
    int largest = -1, secondLarget = -1;

    // largest element
    for (int i = 0;  i < n; i++)
    {
      if (arr[i] > largest)
        largest = arr[i];
    }

    // find the second largest
    for(int i = 0; i < n; i++)
    {
      if(arr[i] > secondLarget && arr[i] != largest)
      {
        secondLarget = arr[i];
      }
    }
    return secondLarget;
}

int main()
{
    int arr[] = {1,22,58,92,78,16,10,9,86,57,62,50,20,34,29,87,55,47,31,90,70,96,85,41,63,51,43,64,81,3,53,82,35,24,99,83,67,54,79,6,11,91,66,27,73,74,17,80,69,75};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%d\n", getSecondLargest(arr, n)); 
    return 0;
}



/*
Problem 3: Find Second Largest Element
Given the Array
Arr = {1,22,58,92,78,16,10,9,86,57,62,50,20,34,29,87,55,47,31,90,70,96,85,41,63,51,43,64,81,3,53,82,35,24,99,83,67,54,79,6,11,91,66,27,73,74,17,80,69,75}
Find the Second largest number. Your program should run in O(n) time. 
*/
