#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// Node structure for doubly-linked binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent; // optional for doubly-linked nature
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

// Insert node in array-based complete binary tree manner
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

// In-order traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Pre-order traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Post-order traversal
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    srand(time(0));

    struct Node* nodes[SIZE];

    // Generate 20 random integers and create nodes
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

    // Perform traversals
    printf("In-order traversal:\n");
    inorder(root);
    printf("\n");

    printf("Pre-order traversal:\n");
    preorder(root);
    printf("\n");

    printf("Post-order traversal:\n");
    postorder(root);
    printf("\n");

    // Free memory
    for (int i = 0; i < SIZE; i++) {
        free(nodes[i]);
    }

    return 0;
}
