#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
    int x = 5;
    int y = 10;

    printf("before swap %d, %d \n",x,y);
    swap(&x,&y);
    printf("after swap %d, %d \n",x,y);

    return 0;
}


/*
Pointers are are addresses in memory


    // data type of the var you want to point to *ptr  = &var

    int *ptr = &x;
    // gives the mem address of vars 
    // the * derefrences the pointer

    printf("%p \n", ptr);

    // %p for pointer
    
    printf("%d \n", ptr);

    ptr += 1;

    printf("%d \n", *ptr);

*/