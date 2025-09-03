#include <stdio.h>

int main()
{
    int x;
    int y;
    int z;

    // input
    //printf("Enter numbers: ");
    scanf("%d %d %d ", &x,&y,&z);

    // check inequality
    if (y + z < x || x + z < y || y + x < z)
    {
        printf("Impossible\n");
        return 0;
    }

    // are all equal
    if (x == y && z == x)
    {
        printf("Equalratial\n");
    }

    //
    else if (x==y || z==x || y==z)
    {
        printf("Isosceles\n");
    }

    // check if the sides are different
    else if (x != y && z != x)
    {
        printf("scalene\n");
    }

    return 0;
}
