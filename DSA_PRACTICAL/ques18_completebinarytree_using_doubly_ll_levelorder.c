#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// Node structure for doubly linked binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent; // optional
};

// Random number generator between 1 and 100
int useRand() {
    return (rand() % 100) + 1;
}

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Build complete binary tree using array of nodes
void buildCompleteBinaryTree(struct Node* nodes[], int n) {
    for (int i = 0; i < n; i++) {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        if (leftIndex < n) {
            nodes[i]->left = nodes[leftIndex];
            nodes[leftIndex]->parent = nodes[i];
        }
        if (rightIndex < n) {
            nodes[i]->right = nodes[rightIndex];
            nodes[rightIndex]->parent = nodes[i];
        }
    }
}

// Queue node for level-order traversal
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

// Enqueue
void enqueue(struct QueueNode** front, struct QueueNode** rear, struct Node* treeNode) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Dequeue
struct Node* dequeue(struct QueueNode** front, struct QueueNode** rear) {
    if (*front == NULL) return NULL;
    struct QueueNode* temp = *front;
    struct Node* treeNode = temp->treeNode;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return treeNode;
}

// Level-order traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;

    enqueue(&front, &rear, root);

    printf("Level-order traversal:\n");
    while (front != NULL) {
        struct Node* curr = dequeue(&front, &rear);
        printf("%d ", curr->data);
        if (curr->left != NULL) enqueue(&front, &rear, curr->left);
        if (curr->right != NULL) enqueue(&front, &rear, curr->right);
    }
    printf("\n");
}

int main() {
    srand(time(0));

    struct Node* nodes[SIZE];

    // Generate 20 random integers
    printf("Generated nodes:\n");
    for (int i = 0; i < SIZE; i++) {
        int value = useRand();
        nodes[i] = createNode(value);
        printf("%d ", value);
    }
    printf("\n\n");

    // Build complete binary tree
    buildCompleteBinaryTree(nodes, SIZE);
    struct Node* root = nodes[0];

    // Perform level-order traversal
    levelOrder(root);

    // Free memory
    for (int i = 0; i < SIZE; i++) free(nodes[i]);

    return 0;
}
