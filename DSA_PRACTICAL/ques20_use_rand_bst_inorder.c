#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent; // optional for doubly-linked nature
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Insert node into BST
struct Node* insertBST(struct Node* root, int value, struct Node* parent) {
    if (root == NULL) {
        struct Node* newNode = createNode(value);
        newNode->parent = parent;
        return newNode;
    }
    if (value < root->data)
        root->left = insertBST(root->left, value, root);
    else
        root->right = insertBST(root->right, value, root);
    return root;
}

// In-order traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Free memory (post-order traversal)
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    srand(time(0));

    printf("Randomly generated 20 integers between 1 and 100:\n");
    for (int i = 0; i < 20; i++) {
        int value = (rand() % 100) + 1;
        printf("%d ", value);
        root = insertBST(root, value, NULL);
    }
    printf("\n\n");

    printf("In-order traversal of the BST (sorted order):\n");
    inorder(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}
