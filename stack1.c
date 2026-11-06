// WAP to implement stack and perform push,pop and display (using array)
#include <stdio.h>
#include <stdlib.h>
int stack[100], top = -1, size;

void push() {
  if (top == size - 1) {
    printf("Stack overflow\n");
  } else {
    printf("Enter element: ");
    scanf("%d", &stack[++top]);
  }
}
void pop() {
  if (top == -1) {
    printf("Stack underflow\n");
  } else {
    printf("Element %d popped\n", stack[top--]);
  }
}
void display() {
  if (top == -1) {
    printf("Stack is empty\n");
  } else {
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
      printf("%d ", stack[i]);
    }
    printf("\n");
  }
}
int main() {
  int choice;
  printf("Enter size of stack: ");
  scanf("%d", &size);
  do {
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  } while (choice != 4);
  return 0;
}