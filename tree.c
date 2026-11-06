// WAP to implement binary tree using linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *left, *right;
} Node;

Node *createNode(int data) {
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  return newnode;
}

void inorder(Node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void preorder(Node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(Node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

int main() {
  Node *root = NULL;
  root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  printf("Inorder: ");
  inorder(root);
  printf("\nPreorder: ");
  preorder(root);
  printf("\nPostorder: ");
  postorder(root);
  printf("\n");
  return 0;
}