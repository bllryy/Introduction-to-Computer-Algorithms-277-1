#include <stdio.h>

struct dog 
{
  char name[50];
  char type[50];
  int age[5];
};


void main() 
{
  struct dog dog1 = { "hello", "cuh", 1 };

  printf("Dogs name %s \n", dog1.name);
  printf("DOgs sage %d \n", dog1.age);

  return;
}
