#include <stdio.h>
#include <stdlib.h>

// just to print the subset out 
void printSubset(int subset[], int subsetSize)
{
  printf("[");
  for (int i = 0; i < subsetSize; i++)
  {
    printf("%d", subset[i]);
    if (i < subsetSize - 1)
      printf(", ");
  }
  printf("]");
}


void genPowerset(int arr[], int n, int index, int subset[], int subsetSize)
{
  if (index == n)
  {
    // base
    printSubset(subset, subsetSize);
    printf("\n");
    return; 
  }

  // execlude the current element 
  genPowerset(arr,n,index + 1, subset, subsetSize);

  // include the current element 
  subset[subsetSize] = arr[index];
  genPowerset(arr,n,index+1, subset, subsetSize +1);
}

int main(void)
{
  int arr[] = {1,2,3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int subset[n];

  printf("Powerset: \n");
  genPowerset(arr,  n,  0,  subset,  0);

  return 0;
}
