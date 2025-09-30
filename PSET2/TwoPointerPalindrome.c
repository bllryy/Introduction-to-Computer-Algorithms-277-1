#include <stdio.h>
#include <string.h>


int main()
{
    char input[100];
    printf("Enter a string: \n");
    scanf("%s", input);
    int left = 0;
    int right = strlen( input) - 1;

    while (left < right)
    {
    if (input[left] != input[right])
    {
        printf("True \n"); // false
    }
        left++;
        right--;
    }
    printf("False \n"); // true
}
