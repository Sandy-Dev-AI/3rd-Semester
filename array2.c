// WAP to create an array of n elements using dynamic memory allocation.
// Calculate Sum of all the prime elements of the array using function call and deallocate the memory.

#include <stdio.h>  // Standard I/O library for printf and scanf
#include <stdlib.h> // Standard library for malloc and free

// Function to check whether a number is prime
// Returns 1 if prime, 0 if not prime
int isPrime(int num) {
    if (num < 2) {
        return 0; // Numbers less than 2 (negative, 0, 1) are not prime
    }
    // Check divisibility up to sqrt(num) using i * i <= num
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Found a factor, so not prime
        }
    }
    return 1; // No factors found, number is prime
}

// Function to calculate the sum of all prime elements in the dynamically allocated array
int sumOfPrimes(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        // If current element is prime, add it to sum
        if (isPrime(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int n;

    // 1. Read the number of elements
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    // 2. Allocate memory dynamically using malloc
    int *arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 3. Read elements into the dynamically allocated array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 4. Calculate the sum of prime elements via function call
    int primeSum = sumOfPrimes(arr, n);

    // Display the result
    printf("Sum of all prime elements: %d\n", primeSum);

    // 5. Deallocate the dynamically allocated memory
    free(arr);
    arr = NULL; // Prevents dangling pointer

    return 0;
}