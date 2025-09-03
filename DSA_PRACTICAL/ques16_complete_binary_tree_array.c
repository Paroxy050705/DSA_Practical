#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// Random number generator between 1 and 100
int useRand() {
    return (rand() % 100) + 1;
}

// In-order traversal (array-based complete binary tree)
void inorder(int tree[], int index, int n) {
    if (index >= n) return;
    inorder(tree, 2 * index + 1, n); // left child
    printf("%d ", tree[index]);
    inorder(tree, 2 * index + 2, n); // right child
}

// Pre-order traversal
void preorder(int tree[], int index, int n) {
    if (index >= n) return;
    printf("%d ", tree[index]);
    preorder(tree, 2 * index + 1, n); // left child
    preorder(tree, 2 * index + 2, n); // right child
}

// Post-order traversal
void postorder(int tree[], int index, int n) {
    if (index >= n) return;
    postorder(tree, 2 * index + 1, n); // left child
    postorder(tree, 2 * index + 2, n); // right child
    printf("%d ", tree[index]);
}

// Level-order traversal (just array from index 0 to n-1)
void levelorder(int tree[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", tree[i]);
    printf("\n");
}

int main() {
    int tree[SIZE];
    srand(time(0));

    // Generate 20 random integers
    printf("Generated array (Complete Binary Tree representation):\n");
    for (int i = 0; i < SIZE; i++) {
        tree[i] = useRand();
        printf("%d ", tree[i]);
    }
    printf("\n\n");

    // Perform traversals
    printf("In-order traversal:\n");
    inorder(tree, 0, SIZE);
    printf("\n");

    printf("Pre-order traversal:\n");
    preorder(tree, 0, SIZE);
    printf("\n");

    printf("Post-order traversal:\n");
    postorder(tree, 0, SIZE);
    printf("\n");

    printf("Level-order traversal:\n");
    levelorder(tree, SIZE);

    return 0;
}
