#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for linked list
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

// Generate random number 1-100
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

// Selection sort on linked list
void selectionSort(struct Node* head) {
    struct Node* i;
    struct Node* j;

    for (i = head; i != NULL; i = i->next) {
        struct Node* min = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->data < min->data) {
                min = j;
            }
        }
        // Swap data
        if (min != i) {
            int temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
    }
}

int main() {
    struct Node* head = NULL;
    srand(time(0)); // Seed RNG

    // Generate 20 random numbers and insert into linked list
    printf("Generated 20 random numbers:\n");
    for (int i = 0; i < 20; i++) {
        int num = useRand();
        insertEnd(&head, num);
    }

    // Display original list
    displayList(head);

    // Perform selection sort
    selectionSort(head);

    printf("\nSorted list (Selection Sort):\n");
    displayList(head);

    return 0;
}
