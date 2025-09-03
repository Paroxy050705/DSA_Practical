#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
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

// Bubble sort on linked list
void bubbleSort(struct Node* head) {
    if (head == NULL) return;
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
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

    // Sort list
    bubbleSort(head);

    printf("\nSorted list (Bubble Sort):\n");
    displayList(head);

    return 0;
}
