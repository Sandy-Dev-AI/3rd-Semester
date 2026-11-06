// WAP to implement binary search tree
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

Node *insert(Node *root, int data) {
  if (root == NULL) {
    root = createNode(data);
  } else if (data < root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

Node *search(Node *root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  }
  if (data < root->data) {
    return search(root->left, data);
  }
  return search(root->right, data);
}

void inorder(Node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main() {
  Node *root = NULL;
  int choice, data;
  do {
    printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      root = insert(root, data);
      break;
    case 2:
      printf("Enter data to search: ");
      scanf("%d", &data);
      Node *result = search(root, data);
      if (result != NULL) {
        printf("Element found\n");
      } else {
        printf("Element not found\n");
      }
      break;
    case 3:
      inorder(root);
      printf("\n");
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  } while (choice != 4);
  return 0;
}