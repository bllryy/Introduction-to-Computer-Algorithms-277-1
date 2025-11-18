#include <stdio.h>
#include <limits.h>  //INT_MAX 
// https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://www.geeksforgeeks.org/cpp/int_max-int_min-cc-applications/&ved=2ahUKEwjpk_bfr_mQAxXZFlkFHXDUO-8QFnoECBgQAQ&usg=AOvVaw1oXBb3wFFIg_0hlEWuSh1M

int cost(int arr[], int n) {
    int min_element = INT_MAX;  

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min_element)
        {
            min_element = arr[i];
        }
    }

    return (n - 1) * min_element;
}

int main() {
    int arr[] = {4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("minimum cost: %d\n", cost(arr, n));  // Output the total cost

    return 0;
}
