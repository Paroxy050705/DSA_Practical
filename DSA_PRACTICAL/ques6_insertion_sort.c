#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
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

// Insert node at end
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

// Function to generate random number between 1 and 100
int useRand() {
    return (rand() % 100) + 1;
}

// Display linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Insert node into sorted list (helper for insertion sort)
void sortedInsert(struct Node** sorted, struct Node* newNode) {
    if (*sorted == NULL || (*sorted)->data >= newNode->data) {
        newNode->next = *sorted;
        *sorted = newNode;
    } else {
        struct Node* current = *sorted;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Insertion sort on linked list
void insertionSort(struct Node** headRef) {
    struct Node* sorted = NULL;
    struct Node* current = *headRef;
    while (current != NULL) {
        struct Node* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *headRef = sorted;
}

int main() {
    struct Node* head = NULL;
    srand(time(0)); // Seed random numbers

    // Generate and insert 20 random integers
    printf("Generated 20 random numbers:\n");
    for (int i = 0; i < 20; i++) {
        int num = useRand();
        insertEnd(&head, num);
    }

    // Display original list
    displayList(head);

    // Sort list using insertion sort
    insertionSort(&head);

    printf("\nSorted list (Insertion Sort):\n");
    displayList(head);

    return 0;
}
