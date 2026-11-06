// WAP to implement priority queue using linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data, priority;
  struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int data, int priority) {
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->data = data;
  newnode->priority = priority;
  newnode->next = NULL;
  if (front == NULL || priority < front->priority) {
    newnode->next = front;
    front = newnode;
  } else {
    Node *temp = front;
    while (temp->next != NULL && temp->next->priority <= priority)
      temp = temp->next;
    newnode->next = temp->next;
    temp->next = newnode;
  }
}

void dequeue() {
  if (front == NULL) {
    printf("Priority queue is empty\n");
  } else {
    Node *temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;
    free(temp);
  }
}

void display() {
  if (front == NULL) {
    printf("Priority queue is empty\n");
  } else {
    Node *temp = front;
    printf("Priority queue: ");
    while (temp != NULL) {
      printf("(%d, %d) ", temp->data, temp->priority);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  int choice, data, priority;
  do {
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      printf("Enter priority: ");
      scanf("%d", &priority);
      enqueue(data, priority);
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