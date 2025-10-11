#include <stdio.h>

int main() {
    int arr[]  = {180, 181, 184, 185, 187, 188, 190, 192, 194, 196, 197, 199, 206, 208, 213, 214, 216, 217, 219, 223, 224, 225, 226, 227, 228, 230, 231, 232, 237, 239, 240, 244, 245, 246, 247, 250, 67, 69, 70, 72, 75, 78, 80, 84, 85, 86, 87, 91, 92, 93, 94, 97, 99, 100, 104, 105, 112, 115, 116, 118, 119, 120, 121, 123, 124, 125, 126, 127, 128, 129, 131, 132, 134, 135, 139, 141, 144, 145, 146, 149, 150, 152, 155, 157, 158, 159, 162, 163, 164, 165, 167, 170, 171, 172, 173, 174, 176, 177, 178, 179};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i = 0, j = n - 1;

    while (i < j) {
        int mid = (i + j) / 2;
        if (arr[mid] > arr[j]) {
            i = mid + 1;
        } else {
            j = mid;
        }
    }
    printf("%d\n", arr[i]);
    return 0;
}

/*
https://www.geeksforgeeks.org/dsa/to-find-smallest-and-second-smallest-element-in-an-array/#
https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
Given the array 
Arr = {180, 181, 184, 185, 187, 188, 190, 192, 194, 196, 197, 199, 206, 208, 213, 214, 216, 217, 219, 223, 224, 225, 226, 227, 228, 230, 231, 232, 237, 239, 240, 244, 245, 246, 247, 250, 67, 69, 70, 72, 75, 78, 80, 84, 85, 86, 87, 91, 92, 93, 94, 97, 99, 100, 104, 105, 112, 115, 116, 118, 119, 120, 121, 123, 124, 125, 126, 127, 128, 129, 131, 132, 134, 135, 139, 141, 144, 145, 146, 149, 150, 152, 155, 157, 158, 159, 162, 163, 164, 165, 167, 170, 171, 172, 173, 174, 176, 177, 178, 179}

Find the position of the SMALLEST element inside this array. Your program must run in O(log n) time. 
Hint: Binary Search ALSO works on rotated arrays.
*/