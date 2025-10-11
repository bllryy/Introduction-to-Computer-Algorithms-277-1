#include <stdio.h>

int linear_search(int arr[], int size, int target) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == target) 
        {
            return i;
        }
    }
    return -1; 
}

int binary_search(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) 
        {
            return mid; 
        }
        else if (arr[mid] < target) 
        {
            left = mid + 1; 
        }
        else 
        {
            right = mid - 1; 
        }

    }
    return -1;
}

int main() 
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, choice;
    
    printf("Array contains numbers from 1 to 100\n");
    printf("Enter a number to search for: ");
    scanf("%d", &target);
    
    printf("\nChoose a search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Both (for comparison)\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    if (choice == 1) 
    {
        printf("Linear Search\n");
        int result = linear_search(arr, size, target);
        if (result != -1) 
        {
            printf("Linear Search: Found %d at index %d\n", target, result);
        } else 
        {
            return 0;
        }
    }
    else if (choice == 2) 
    {
        printf("Binary Search\n");
        int result = binary_search(arr, size, target);
        if (result != -1) 
        {
            printf("Binary Search: Found %d at index %d\n", target, result);
        } else 
        {
            return 0;
        }
    }
    return 0;
}

/*
Problem 0: Comparison Between Binary Search and Linear Search
Given the array 
Arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100}
Implement Binary Search and Linear Search as two separate functions. 
*/
