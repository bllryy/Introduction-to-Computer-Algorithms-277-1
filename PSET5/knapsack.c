#include <stdio.h>

int knapsack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    int pick = 0;

    // pick nth item if it dosent exceed our capacity
    if (wt[n-1] <= W) 
    {
        pick = val[n-1] + knapsack(W - wt[n-1], wt, val, n - 1);
    }

    // dont pick the nth item
    int dontPick = knapsack(W, wt, val, n - 1);
    return (pick > dontPick) ? pick : dontPick;
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(val) / sizeof(val[0]);
    
    printf("Max: %d\n", knapsack(capacity, wt, val, n));

    return 0;
}

/*
val/wt

pick item or not
then find which item gives you the max value
if pick it will be the value of the item plus whatever we can get
by subtracting from the total weight
or just dont pick item

https://www.youtube.com/watch?v=8LusJS5-AGo
https://www.geeksforgeeks.org/dsa/0-1-knapsack-problem-dp-10/

item1 alone: weight 10 = value 60
item2 alone: weight 20 = value 100
item3 alone: weight 30 = value 120
item1+item2: weight 30 = value 160
item1+item3: weight 40 = value 180
item2+item3: weight 50 = value 220 this fits exactly and is the best

*/