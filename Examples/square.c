#include <stdio.h>

int square(int num)
{
  return num * num;
}

int mean(int size, int arr[]);


int main()
{
  int number = 5;
  printf("The square of %d is %d\n", number, square(number));

  int list[] = {1,2,3,4,5};
  int size = sizeof(list) / sizeof(list[0]);
  printf("Size of list: %d\n", size);
  printf("Square of size: %d\n", mean(size, list));

  return 0;
}

int mean(int size, int arr[])
{
  return square(size);
}
