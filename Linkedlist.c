// Write a program to implement single linked list in C using structure Node
// a>Create a Linked list
// b>inserting node at beginning
// c>inserting node at end
// d>inserting node at specific postion
// e>display the linked list

#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure
struct Node {
    int data;
    struct Node *next;
};

// Global head pointer
struct Node *head = NULL;

// Function prototypes
struct Node *createNode(int data);
void createList(int n);
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int position);
void displayList();
void freeList();

int main() {
    int choice, data, n, pos;

    do {
        printf("\n========== SINGLY LINKED LIST MENU ==========\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");
        printf("=============================================\n");
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the number of nodes to create: ");
                scanf("%d", &n);
                createList(n);
                printf("List created successfully.\n");
                displayList();
                break;

            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                printf("Node inserted at beginning.\n");
                displayList();
                break;

            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                printf("Node inserted at end.\n");
                displayList();
                break;

            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at (1-based index): ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
                displayList();
                break;

            case 5:
                displayList();
                break;

            case 6:
                printf("Exiting and freeing memory...\n");
                freeList();
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// Helper function to dynamically allocate a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// a> Create a Linked list of 'n' nodes
void createList(int n) {
    if (n <= 0) {
        printf("Number of nodes must be greater than 0.\n");
        return;
    }

    // Free any existing list first
    freeList();

    int data;
    struct Node *temp = NULL;

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    temp = head;

    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        temp->next = newNode;
        temp = temp->next;
    }
}

// b> Inserting node at beginning
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// c> Inserting node at end
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    // Traverse until the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// d> Inserting node at specific position (1-based index)
void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position! Position must be >= 1.\n");
        return;
    }

    // If inserting at position 1, it's equivalent to inserting at beginning
    if (position == 1) {
        insertAtBeginning(data);
        printf("Node inserted at position 1.\n");
        return;
    }

    struct Node *temp = head;
    // Traverse to the (position - 1)th node
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is beyond (length + 1)
    if (temp == NULL) {
        printf("Position %d is out of range! Current list has fewer nodes.\n", position);
        return;
    }

    // Insert the new node
    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node with data %d inserted at position %d.\n", data, position);
}

// e> Display the linked list
void displayList() {
    if (head == NULL) {
        printf("\nLinked List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nCurrent Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free all allocated memory upon exit
void freeList() {
    struct Node *temp = head;
    while (temp != NULL) {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}
