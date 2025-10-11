#include <stdio.h>

int twoSum(int arr[], int target, int n) {
    int i = 0, j = n - 1;

    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == target) {
            return 1;
        }
        else if (sum < target) {
            i++;
        }
        else {
            j--;
        }
    }
    return 0;
}

int main(){
    int arr[] = {4,7,8,9,13,14,17,21,22,24,25,28,29,31,33,36,41,42,43,44,46,47,48,49,51,52,54,55,57,59,60,61,63,64,66,71,76,77,79,81,84,85,88,89,90,91,92,97,98,100};
    int target = 72;
    int n = sizeof(arr) / sizeof(arr[0]);

    if(twoSum (arr, target, n)) 
        printf("true\n");
    else 
        printf("false\n");
    
    return 0;

}

/*

TODO: print the index of where its at 

Problem 4: Two Sum
Given the array 
Arr = {4,7,8,9,13,14,17,21,22,24,25,28,29,31,33,36,41,42,43,44,46,47,48,49,51,52,54,55,57,59,60,61,63,64,66,71,76,77,79,81,84,85,88,89,90,91,92,97,98,100}
n log n 
Find the position of two elements in the array that sum to 72. Your program must run in O(log n) time. 
Hint: A two-pointer approach should be suitable here. https://www.geeksforgeeks.org/dsa/to-find-smallest-and-second-smallest-element-in-an-array/#
*/