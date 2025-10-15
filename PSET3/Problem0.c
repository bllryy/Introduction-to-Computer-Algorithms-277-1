#include <stdio.h>

int linear_search_count(int arr[], int size, int target, int *count)
{
    *count = 0;
    for (int i = 0; i < size; i++)
    {
        (*count)++;
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binary_search_count(int arr[], int size, int target, int *count)
{
    int left = 0, right = size - 1;
    *count = 0;

    while (left <= right)
    {
        (*count)++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[100];
    for (int i = 0; i < 100; i++)
        arr[i] = i + 1; // fill 1–100

    int size = 100;
    int target = 73;

    int count_lin = 0, count_bin = 0;
    int result_lin = linear_search_count(arr, size, target, &count_lin);
    int result_bin = binary_search_count(arr, size, target, &count_bin);

    printf("Target: %d\n", target);
    printf("Linear Search -> Index: %d (Comparisons: %d)\n", result_lin, count_lin);
    printf("Binary Search -> Index: %d (Comparisons: %d)\n", result_bin, count_bin);

    return 0;
}
