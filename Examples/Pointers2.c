#include <stdio.h>
#include <stdlib.h>


/*
how to make a pointer a type integer: int *ptr = &var;

how do i get a value from a pointer: *ptr


arrys are sorted in a contiguous block of memory

arrays are a cheatcode for ptrs

when we pass a variable to a function it is

*/

int add0(int a)
{
    return a;
}

int add1(int a)
{
    int one = 1;
}

int add2(int a)
{
    int two = 2;
    return a + two;
}

int add3(int a)
{
    int three = 3;
    return a + three;
}



int add4(int a)
{
    int four = 4;
    return a + four;
}




int add5(int a)
{
    int five = 5;
    // wastful b/c when add5 passes control to the main the var still exists bit we cant access it
    // we can use malloc to allocate memory on the heap that will persist after the function ends
    // but its our obligation to free
    return a + five;
}
    int main()
    {
        int arr[] = {1,2,3,4,5};

        int b = 10;
        int sum = add5(b);
        printf("sum: %d \n", sum);

        // arrays are pointers to contious blocks of memory
        // the name is "arr" is a pointer to the first element in the array
        // if we add 1 to the pointer then it will point to the next element in the array

        return 0;
    }

    /*
      deleting things
      sadly we dont have auto garbage collection in C
      that means we have to do it manually

      recall that functions have their own stack frame
      when a function ends the stack frame is deleted
      or their own local scope
      functions cant communicate with each other unless we ret a value

    */
