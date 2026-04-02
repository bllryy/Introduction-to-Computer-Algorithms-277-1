#include <stdio.h>
#include <stdlib.h>

/*

gcc -Wall -Wextra -pedantic -std=c11 p0.c -o p0 && ./p0

 * https://www.geeksforgeeks.org/c/c-program-for-inserting-a-node-in-a-linked-list/
	Max nodes at level L (root at level 0): 3^L
	Min height for N nodes (height = number of edges on longest root→leaf path):
    For maximum branching (full tree), total nodes up to height H is (3^(H+1)-1)/2.
    Solve for H minimal given N: H_min = floor( log_base_3(  (2*N + 1) ) ) - 1
    (derive from N <= (3^(H+1)-1)/2 => 3^(H+1) >= 2N+1)
	Max total nodes at height H (levels 0..H inclusive): sum_{i=0..H} 3^i = (3^(H+1)-1)/2
 */

typedef struct TNode 
{
	int data;
	struct TNode *left;
	struct TNode *middle;
	struct TNode *right;
} TNode;

TNode* newNode(int data)
{
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = data;
	n->left = n->middle = n->right = NULL;
  return n;
}

void preorder(TNode* root)
{
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->middle);
  preorder(root->right);
}

void inorder(TNode* root)
{
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->middle);
  inorder(root->right);
}

void postorder(TNode* root)
{
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->middle);
  postorder(root->right);
  printf("%d ", root->data);
}

void inorder_like(TNode* root)
{
  if (root == NULL) {
    return;
  }
  if (root->left) {
    inorder_like(root->left);
  }
  printf("%d ", root->data);
  if (root->middle) {
    inorder_like(root->middle);
  }
  if (root->right) {
    inorder_like(root->right);
  }
}

int main() 
{
  /*
            1
          / | \
         2  3  4
        /|\     \
       5 6 7     8
  */
  TNode *root = newNode(1);
  root->left = newNode(2);
  root->middle = newNode(3);
  root->right = newNode(4);

  root->left->left = newNode(5);
  root->left->middle = newNode(6);
  root->left->right = newNode(7);

  root->right->right = newNode(8);

  printf("Preorder: ");
  preorder(root);
  printf("\n");

  printf("\"Inorder-like\": ");
  inorder_like(root);
  printf("\n");

  printf("Postorder: ");
  postorder(root);
  printf("\n");
  return 0;
}
