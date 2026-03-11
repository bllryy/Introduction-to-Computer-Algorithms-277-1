#include <stdio.h>
#include <stdlib.h>

/*
 *
 * LIFO = last in first out
 * backtracking algo
 */


struct node {
  int value;
  struct node *next;
}; // remember this from linked list
  //
struct stack {
  struct node *top;
};

void push(struct stack* s, int data) {
  // make the new node: malloc the new node and assign the data to its value member var


  struct node* newNode = malloc(sizeof(struct node));
  newNode -> value = data;

  if (s -> top == NULL) {
    s -> top = newNode;
    newNode -> next = NULL;
  } else {
    newNode -> next = s -> top;
    s -> top = newNode;
  }

  int pop(struct stack* s) {
   struct node* temp = s -> top;
   int data -> value = data;

   s -> top = s -> top -> next;
   free(temp);
   return data;
  }

  int main() {
    struct stack *mystack = malloc(sizeof(struct stack));

    push(mystack,1);
    push(mystack,2);
    push(mystack,3);

    printf("top value %d\n", mystack -> top -> value);
    int data = pop(mystack);
    printf("%s\n");
}
