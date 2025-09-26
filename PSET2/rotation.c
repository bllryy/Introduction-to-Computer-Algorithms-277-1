#include <stdio.h>

/*
  Many problems in DSA involve an ordered list of numbers but rotated.
  For example, given an index n = 2 and an array {1,2,3,4,5}, rotated the array
  about the index n = 2 gives the result
  Original array: 1 2 3 4 5
  Rotated array: 3 4 5 1 2
  Your goal is to write a function that rotates any arbitrary array.
  Your function header is as follows:int main()
*/

int main()
{
  int arr[100], n, size, i, temp[100];

  printf("Enter the size of the array: \n");
  scanf("%d", &size);

  printf("Enter the elements of the array: \n");
  for (i = 0; i < size; i++)
    {
      scanf("%d", &arr[i]);
    }

  printf("Enter the index to rotate about: \n");
  scanf("%d", &n);

  // Store the elements from index n to end in temp array
  // copy elements from index n to the end
  for (i = n; i < size; i++)
    {
      temp[i - n] = arr[i];
    }

  // Store the elements from index 0 to n-1 in temp array
  for (i = 0; i < n; i++)
    {
      temp[size - n + i] = arr[i];
    }

  // copy back
  for (i = 0; i < size; i++)
    {
      arr[i] = temp[i];
    }

  // TODO: Print the rotated array
  printf("rotated \n");
  for (i = 0; i < size; i++)
    {
      printf("%d ", arr[i]);
    }
  
  printf("\n");
  return 0;
}
