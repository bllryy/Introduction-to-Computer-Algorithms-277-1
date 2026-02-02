/*
 *
 * malloc(size_t) <- basically we need to pass the sizeof(data type)
 *
 * Heap - dynamic
 * Stack - fixed
 *
 * allocating structs to the heap is important b/c we can hundreds of member vars inside of a struct so structs can get very big i
 * in terms of memory
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


struct test
{
    int a;
    int b;
};

struct test* createTest(int x, int y)
{
    newtest -> a = x;
    newtest -> b = y;

    return newtest;
}

int main()
{
    struct test *mytest = malloc(sizeof(struct test));

    printf("%d \n", mytest->a);
    printf("%d \n", mytest->b);

    return 0;
}
