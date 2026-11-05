// Write a program to create a linked list in C and perform the following operations:
// a> Create a linked list
// b> Deleting node at beginning
// c> Deleting node at end
// d> Deleting node at specific position
// e> Display the linked list

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
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int position);
void displayList();
void freeList();

int main() {
    int choice, n, pos;

    do {
        printf("\n========== LINKED LIST DELETION MENU ==========\n");
        printf("1. Create Linked List\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete at End\n");
        printf("4. Delete at Specific Position\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");
        printf("===============================================\n");
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
                deleteAtBeginning();
                displayList();
                break;

            case 3:
                deleteAtEnd();
                displayList();
                break;

            case 4:
                printf("Enter position to delete (1-based index): ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
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

// Helper function to create a new node
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

// a> Create a linked list of 'n' nodes
void createList(int n) {
    if (n <= 0) {
        printf("Number of nodes must be greater than 0.\n");
        return;
    }

    freeList(); // Clean old list if any

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

// b> Deleting node at beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("Underflow! List is already empty.\n");
        return;
    }

    struct Node *temp = head;  // 1. Point temp to node to delete
    head = head->next;         // 2. Move head to the 2nd node
    printf("Deleted node with data: %d from beginning.\n", temp->data);
    free(temp);                // 3. Free memory
}

// c> Deleting node at end
void deleteAtEnd() {
    if (head == NULL) {
        printf("Underflow! List is already empty.\n");
        return;
    }

    // Corner case: list has only 1 node
    if (head->next == NULL) {
        printf("Deleted node with data: %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Traverse to the second-to-last node (where temp->next->next is NULL)
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // temp is at 2nd-to-last node; temp->next is the last node
    printf("Deleted node with data: %d from end.\n", temp->next->data);
    free(temp->next);     // Free the last node
    temp->next = NULL;    // Set second-to-last node as the new end
}

// d> Deleting node at specific position (1-based index)
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("Underflow! List is already empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position! Position must be >= 1.\n");
        return;
    }

    // Position 1 is deleting at beginning
    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node *temp = head;
    // Traverse to the node immediately before the one to delete (position - 1)
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is out of range! Current list has fewer nodes.\n", position);
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next; // Bypass the node to delete
    printf("Deleted node with data: %d from position %d.\n", nodeToDelete->data, position);
    free(nodeToDelete);             // Free from memory
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
