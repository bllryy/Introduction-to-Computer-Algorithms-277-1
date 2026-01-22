#include <stdio.h>
#include <stdlib.h>

/*
 *
 *
 * Make a function call control program
 * things are created inside of said function those will get destroyed after
 * the functions passes control back to main, this iss basically why
 * we return values when we want to remember those things
 *  if we created a int x in some function called foo
 *    if we tried to return the pointer to somehign random because x
 *    will get deallocated after the function ends
 */

// we need a way of dynamic allocate memory
// allocate on the heap not the stack
// malloc 
// void malloc 
// malloc(sizeof(int[69]));
// void pointer of the size specified in param list
// some things we returna a size_t
// 

//int* foo() 
//{
//  int x = 5;
//  return &x;
//}

int bar() 
{
  int *x = malloc(sizeof(int));
  *x = 5;
  return x;
}

int* fizz()
{
  int size = 5;
  int arr* = malloc(sizeof(int) *5);
  for (int i = 0; i < 5; i++)
  {
    arr[i] = i+1;
  }
return arr;
}

int main() 
{
  int *p = bar();
  pritnf("we expect 5 here: %d \n", *p); // when we try to de ref here x is destoryed so the pointer is at nothiign now
  free(p);

  int *myarr = fizz();
  printf("%d \n", myarr);
}


