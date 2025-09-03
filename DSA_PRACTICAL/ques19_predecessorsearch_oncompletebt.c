#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// Node structure for doubly linked binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

// Random number generator
int useRand() {
    return (rand() % 100) + 1;
}

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Build a complete binary tree from an array of nodes
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

// Find node by value (simple tree traversal)
struct Node* findNode(struct Node* root, int key) {
    if (root == NULL) return NULL;
    if (root->data == key) return root;
    struct Node* leftSearch = findNode(root->left, key);
    if (leftSearch != NULL) return leftSearch;
    return findNode(root->right, key);
}

// Find in-order predecessor of a node
struct Node* inorderPredecessor(struct Node* node) {
    if (node == NULL) return NULL;

    // Case 1: If left subtree exists, predecessor is rightmost node of left subtree
    if (node->left != NULL) {
        struct Node* temp = node->left;
        while (temp->right != NULL)
            temp = temp->right;
        return temp;
    }

    // Case 2: Go up using parent pointer until we find a node which is right child of its parent
    struct Node* temp = node->parent;
    while (temp != NULL && node == temp->left) {
        node = temp;
        temp = temp->parent;
    }
    return temp;
}

int main() {
    srand(time(0));
    struct Node* nodes[SIZE];

    // Generate random integers and create nodes
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

    int key;
    printf("Enter a value to find its in-order predecessor: ");
    scanf("%d", &key);

    struct Node* target = findNode(root, key);
    if (target == NULL) {
        printf("Value %d not found in the tree.\n", key);
    } else {
        struct Node* pred = inorderPredecessor(target);
        if (pred != NULL)
            printf("In-order predecessor of %d is %d.\n", key, pred->data);
        else
            printf("%d has no in-order predecessor (it is the first in in-order traversal).\n", key);
    }

    // Free memory
    for (int i = 0; i < SIZE; i++) free(nodes[i]);

    return 0;
}
