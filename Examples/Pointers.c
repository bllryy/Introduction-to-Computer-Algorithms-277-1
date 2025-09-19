#include <stdio.h>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main() 
{
    int x = 5;
    int y = 10;

    // data type of the var you want to point to *ptr  = &var

    int *ptr = &x;
    // gives the mem address of vars 
    // the * derefrences the pointer

    printf("%p \n", ptr);

    // %p for pointer
    
    printf("%p \n", ptr);
    

    return 0;
}


/*
Pointers are are addresses in memory


*/