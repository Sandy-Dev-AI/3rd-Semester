// WAP to implement queue using array
#include <stdio.h>
#include <stdlib.h>
int queue[100], front = -1, rear = -1, size;

void enqueue() {
  if (rear == size - 1) {
    printf("Queue overflow\n");
  } else {
    printf("Enter element: ");
    scanf("%d", &queue[++rear]);
  }
}
void dequeue() {
  if (front == -1) {
    printf("Queue underflow\n");
  } else {
    printf("Element %d dequeued\n", queue[front++]);
  }
}
void display() {
  if (front == -1) {
    printf("Queue is empty\n");
  } else {
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}
int main() {
  int choice;
  printf("Enter size of queue: ");
  scanf("%d", &size);
  do {
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
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