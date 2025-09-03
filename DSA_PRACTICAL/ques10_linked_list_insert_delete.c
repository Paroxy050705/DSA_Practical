#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Display list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at a given position (1-based)
void insertAtPosition(struct Node** head, int value, int pos) {
    struct Node* newNode = createNode(value);
    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete node by value
void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node needs to be deleted
    if (temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("%d deleted.\n", value);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("%d deleted.\n", value);
}

// Random number generator between 1 and 100
int useRand() {
    return (rand() % 100) + 1;
}

int main() {
    struct Node* head = NULL;
    srand(time(0));

    // Generate 20 random numbers
    for (int i = 0; i < 20; i++)
        insertEnd(&head, useRand());

    int choice, value, pos;

    do {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Display List\n");
        printf("2. Insert Number at Position\n");
        printf("3. Delete Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList(head);
                break;
            case 2:
                printf("Enter number to insert: ");
                scanf("%d", &value);
                printf("Enter position (1-based): ");
                scanf("%d", &pos);
                insertAtPosition(&head, value, pos);
                break;
            case 3:
                printf("Enter number to delete: ");
                scanf("%d", &value);
                deleteByValue(&head, value);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    // Free memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
