#include <stdio.h>

// Recursive function for factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Recursive function for Fibonacci
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n, i;

    // Input validation
    printf("Enter a natural number (1 to 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid input! Please enter a number between 1 and 10.\n");
        return 0;
    }

    // Factorial
    printf("Factorial of %d = %d\n", n, factorial(n));

    // Fibonacci series
    printf("Fibonacci series of %d terms:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
