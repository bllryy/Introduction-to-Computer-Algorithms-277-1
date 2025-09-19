#include <stdio.h>

int add(int a, int b)
{
  int sum = a + b;
  return sum;
}


int main()
{
  int x = 5;
  int y = 10;
  int sum = add(x,y);
  printf("%d \n", sum);

  int num = 5;
  printf("the squre of num %d is %d\n", num, sqrt(num));
  return 0;
}

int sqrt(int x)
{
  return x * x;
}
