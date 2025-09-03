#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers in range [1,100]
int useRand() {
    return (rand() % 100) + 1;
}

// Bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;  // found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}

int main() {
    int arr[20];
    int n = 20;

    // Seed random number generator
    srand(time(0));

    // Generate random numbers
    printf("Generated numbers:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = useRand();
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort array
    bubbleSort(arr, n);

    printf("\nSorted numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // User input for search
    int key;
    printf("\nEnter a number to search (1-100): ");
    scanf("%d", &key);

    // Binary search
    int pos = binarySearch(arr, n, key);
    if (pos != -1)
        printf("%d found at position %d (0-based index).\n", key, pos);
    else
        printf("%d not found in the array.\n", key);

    return 0;
}
