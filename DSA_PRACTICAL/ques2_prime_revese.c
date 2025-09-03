#include <stdio.h>

// Recursive function to check prime
int isPrimeRecursive(int n, int i) {
    if (n <= 2)
        return (n == 2) ? 1 : 0;
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
    return isPrimeRecursive(n, i + 1);
}

// Recursive function to reverse number
int reverseRecursive(int n, int rev) {
    if (n == 0)
        return rev;
    return reverseRecursive(n / 10, rev * 10 + n % 10);
}

int main() {
    int n;

    // Input
    printf("Enter a natural number: ");
    scanf("%d", &n);

    // Prime check
    if (isPrimeRecursive(n, 2))
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    // Reverse number
    printf("Reverse of %d is %d\n", n, reverseRecursive(n, 0));

    return 0;
}
