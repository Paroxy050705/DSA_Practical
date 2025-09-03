#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent; // optional for doubly-linked feature
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

int main() {
    struct Node* root = NULL;
    int value;

    printf("Enter 20 integers between 1 and 100:\n");
    for (int i = 0; i < 20; i++) {
        do {
            printf("Enter integer %d: ", i + 1);
            scanf("%d", &value);
            if (value < 1 || value > 100)
                printf("Invalid input! Please enter a number between 1 and 100.\n");
        } while (value < 1 || value > 100);
        root = insertBST(root, value, NULL);
    }

    printf("\nIn-order traversal of the BST:\n");
    inorder(root);
    printf("\n");

    // Free memory using post-order traversal
    struct Node* stack[20]; // simple stack for nodes
    int top = -1;
    struct Node* curr = root;
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        struct Node* right = curr->right;
        free(curr);
        curr = right;
    }

    return 0;
}
