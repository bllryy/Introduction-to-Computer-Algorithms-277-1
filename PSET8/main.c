/*
 * incriment a que from two stacks
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  Stack s1;
  Stack s2;
} Queue;

int pop(struct stack* s) 
{
	struct node* temp = s -> top; 
	int data = temp -> value;

	s -> top = s -> top -> next;
	free(temp);

	return data;
}

void push(struct stack* s, int data)
{
	struct node* newNode = malloc(sizeof(struct node));
  	newNode -> value = data;
  	if (s -> top == NULL)
	{
    		s -> top = newNode; 
        	newNode -> next = NULL;
   	} else {
        	newNode -> next = s -> top; 
        	s -> top = newNode;     
   	}
}


void enqueue(Queue* q, int value) 
{
    // push onto the first stack
    push(&(q->s1), value);
}

int deque(Queue* q) 
{
	if(isempty(&(q->s2)))
	{
		while(!isempty(&(q->s1))) 
		{
			
		}
	}
}


void enqueue(Queue* q, int val)
{
  push(&(q-> ))
}

int main() 
{
	struct stack *mystack = malloc(sizeof(struct stack));
	push	
}
