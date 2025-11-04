#include <stdio.h>

int main(void) 
{
    int arr[] = {0, 0, 0, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int left = 0;
    int right = n - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left) /2;

        if (arr[mid] == 1)
        {
            right = mid -1;
        } else {
            left = mid + 1;
        }
    }

    printf("count is: %d\n", n - left);
    return 0; 
        
}