// Program: Read two numbers and compare them using function call by address
#include <stdio.h> // Include standard I/O library for printf and scanf

// Function prototype: declares compare function that accepts two integer
// pointers (addresses)
void compare(int *x, int *y);

int main() {
  int a, b; // Declare two integer variables to store the user's numbers

  // Prompt the user to enter two numbers
  printf("Enter two numbers you want to compare: ");

  // Read two integers from standard input and store them at the memory
  // locations of a and b
  scanf("%d %d", &a, &b);

  // Call compare() by address: pass the memory addresses of a and b using the
  // '&' operator
  compare(&a, &b);

  return 0; // Return 0 to indicate successful program termination
}

// Function definition: receives memory addresses into pointer variables x and y
void compare(int *x, int *y) {
  // *x and *y dereference the pointers to access the actual values stored at
  // those addresses

  if (*x > *y) {
    printf("%d is greater than %d\n", *x, *y);
  } else if (*x < *y) {
    printf("%d is less than %d\n", *x, *y);
  } else {
    printf("%d is equal to %d\n", *x, *y);
  }
}
