#include <stdio.h>
#include <stdlib.h>


/*
Linked list
malloc a new struct and have that point to the old first element
when alloc arr 

how does [] work
arr[0] <- ptr to the first element
*(arr)

arr[1] <- pointer to the second element
*(arr +1) <- "adding 1" to the mem address\

1 is close to 2 and 2 is close to 3, arrays are allocated contigously

[unknow arr alreadyd alloced value][arr] <- what do in this secnario

*/


struct node 
{
    int val;
    struct node *next;
};

struct node *createNode(int val) 
{
    struct node * newNode = malloc(sizeof(struct node));
    newNode -> val = value;
    // we some way for a linked list 
    newNode -> next = NULL; // we can use NULL as our terminaltion

    return newNode;

};

int main() 
{
    struct node *node1 = createNode(1);
    struct node *node2 = createNode(2);
    struct node *node3 = createNode(3);
    //struct node *node1 = createNode(1);

    node1 -> next = node2;
    node2 -> next = node3;
}