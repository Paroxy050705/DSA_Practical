#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 100
int useRand() {
    return (rand() % 100) + 1;
}

// Merge function for merge sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

// Merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n = 20;
    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand(time(0)); // Seed random number generator

    // Generate 20 random integers between 1 and 100
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = useRand();
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform merge sort
    mergeSort(arr, 0, n - 1);

    printf("\nSorted array (Merge Sort):\n");
    displayArray(arr, n);

    free(arr); // Free allocated memory
    return 0;
}
