#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 100
int useRand() {
    return (rand() % 100) + 1;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[20];
    int n = 20;

    srand(time(0)); // Seed RNG

    // Generate 20 random integers
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = useRand();
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform quick sort
    quickSort(arr, 0, n - 1);

    // Display sorted array
    printf("\nSorted array (Quick Sort):\n");
    displayArray(arr, n);

    return 0;
}
