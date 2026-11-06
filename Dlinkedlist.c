// WAP to perform insertion and deletion in a double linked list

#include <stdio.h>
#include <stdlib.h>

// Definition of Doubly Linked List Node structure
struct Node {
    int data;
    struct Node *prev; // Pointer to previous node
    struct Node *next; // Pointer to next node
};

// Global head pointer
struct Node *head = NULL;

// Function prototypes
struct Node *createNode(int data);
void createList(int n);
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int position);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int position);
void displayList();
void displayBackward();
void freeList();

int main() {
    int choice, data, n, pos;

    do {
        printf("\n========== DOUBLY LINKED LIST MENU ==========\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Specific Position\n");
        printf("8. Display List (Forward)\n");
        printf("9. Display List (Backward)\n");
        printf("10. Exit\n");
        printf("=============================================\n");
        printf("Enter your choice (1-10): ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter number of nodes to create: ");
                scanf("%d", &n);
                createList(n);
                printf("Doubly Linked List created successfully.\n");
                displayList();
                break;

            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                displayList();
                break;

            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                displayList();
                break;

            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (1-based index): ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
                displayList();
                break;

            case 5:
                deleteAtBeginning();
                displayList();
                break;

            case 6:
                deleteAtEnd();
                displayList();
                break;

            case 7:
                printf("Enter position to delete (1-based index): ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                displayList();
                break;

            case 8:
                displayList();
                break;

            case 9:
                displayBackward();
                break;

            case 10:
                printf("Exiting and freeing memory...\n");
                freeList();
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 10.\n");
        }
    } while (choice != 10);

    return 0;
}

// Helper function to create a new doubly linked list node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL; // Initially disconnected
    newNode->next = NULL;
    return newNode;
}

// Create an initial list of 'n' nodes
void createList(int n) {
    if (n <= 0) {
        printf("Number of nodes must be greater than 0.\n");
        return;
    }

    freeList(); // Clear previous list if any

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

        temp->next = newNode; // Forward link
        newNode->prev = temp; // Backward link
        temp = temp->next;    // Advance temp to the new tail
    }
}

// 1. Insertion at Beginning
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        printf("Node inserted as head.\n");
        return;
    }

    newNode->next = head; // 1. newNode points forward to old head
    head->prev = newNode; // 2. Old head points backward to newNode
    head = newNode;       // 3. head moves to newNode
    printf("Node with data %d inserted at beginning.\n", data);
}

// 2. Insertion at End
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        printf("Node inserted as head.\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) { // Walk to the last node
        temp = temp->next;
    }

    temp->next = newNode; // 1. Last node points forward to newNode
    newNode->prev = temp; // 2. newNode points backward to last node
    printf("Node with data %d inserted at end.\n", data);
}

// 3. Insertion at Specific Position (1-based index)
void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position! Position must be >= 1.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node *temp = head;
    // Walk to node (position - 1)
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of range!\n", position);
        return;
    }

    // If inserting after the last node
    if (temp->next == NULL) {
        insertAtEnd(data);
        return;
    }

    struct Node *newNode = createNode(data);

    // 4 pointer connections:
    newNode->next = temp->next;     // 1. newNode forward link
    newNode->prev = temp;           // 2. newNode backward link
    temp->next->prev = newNode;     // 3. Next node backward link to newNode
    temp->next = newNode;           // 4. Current node forward link to newNode

    printf("Node with data %d inserted at position %d.\n", data, position);
}

// 4. Deletion from Beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("Underflow! List is already empty.\n");
        return;
    }

    struct Node *temp = head;

    // If there is only 1 node
    if (head->next == NULL) {
        head = NULL;
    } else {
        head = head->next;   // Move head forward
        head->prev = NULL;   // Disconnect backward link to deleted node
    }

    printf("Deleted node with data: %d from beginning.\n", temp->data);
    free(temp);
}

// 5. Deletion from End
void deleteAtEnd() {
    if (head == NULL) {
        printf("Underflow! List is already empty.\n");
        return;
    }

    struct Node *temp = head;

    // If there is only 1 node
    if (head->next == NULL) {
        head = NULL;
        printf("Deleted node with data: %d from end.\n", temp->data);
        free(temp);
        return;
    }

    // Walk to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL; // Disconnect the 2nd-to-last node's forward link
    printf("Deleted node with data: %d from end.\n", temp->data);
    free(temp);
}

// 6. Deletion from Specific Position (1-based index)
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("Underflow! List is already empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position! Position must be >= 1.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node *temp = head;
    // Walk to the exact node to be deleted (at 'position')
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of range!\n", position);
        return;
    }

    // Bypass 'temp' from both directions
    temp->prev->next = temp->next; // Left neighbour points past temp

    if (temp->next != NULL) {      // If temp is not the last node
        temp->next->prev = temp->prev; // Right neighbour points back past temp
    }

    printf("Deleted node with data: %d from position %d.\n", temp->data, position);
    free(temp);
}

// 7. Display Forward
void displayList() {
    if (head == NULL) {
        printf("\nDoubly Linked List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nDoubly Linked List (Forward): NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 8. Display Backward (Shows the power of the 'prev' pointer)
void displayBackward() {
    if (head == NULL) {
        printf("\nDoubly Linked List is empty.\n");
        return;
    }

    struct Node *temp = head;
    // Walk all the way to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nDoubly Linked List (Backward): NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev; // Walk backwards!
    }
    printf("NULL\n");
}

// Clean up memory
void freeList() {
    struct Node *temp = head;
    while (temp != NULL) {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}
