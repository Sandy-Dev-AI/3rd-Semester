// Write a menu driven program to create a structure to represent complex number
// and perform the addition and multiplication of the two complex numbers.

#include <stdio.h>

// 1. Structure definition to represent a complex number: (real + imag * i)
struct Complex {
  float real;
  float imag;
};

// Function prototypes
struct Complex add(struct Complex c1, struct Complex c2);
struct Complex multiply(struct Complex c1, struct Complex c2);
void display(struct Complex c);

int main() {
  struct Complex c1, c2, result;
  int choice;

  do {
    // Display the menu
    printf("\n========== COMPLEX NUMBER MENU ==========\n");
    printf("1. Add two complex numbers\n");
    printf("2. Multiply two complex numbers\n");
    printf("3. Exit\n");
    printf("=========================================\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    // Process choice
    switch (choice) {
    case 1:
      printf("\nEnter real and imaginary part of first complex number: ");
      scanf("%f %f", &c1.real, &c1.imag);

      printf("Enter real and imaginary part of second complex number: ");
      scanf("%f %f", &c2.real, &c2.imag);

      result = add(c1, c2);

      printf("\nFirst Number:  ");
      display(c1);
      printf("\nSecond Number: ");
      display(c2);
      printf("\n------------------------------");
      printf("\nSum:           ");
      display(result);
      printf("\n");
      break;

    case 2:
      printf("\nEnter real and imaginary part of first complex number: ");
      scanf("%f %f", &c1.real, &c1.imag);

      printf("Enter real and imaginary part of second complex number: ");
      scanf("%f %f", &c2.real, &c2.imag);

      result = multiply(c1, c2);

      printf("\nFirst Number:  ");
      display(c1);
      printf("\nSecond Number: ");
      display(c2);
      printf("\n------------------------------");
      printf("\nProduct:       ");
      display(result);
      printf("\n");
      break;

    case 3:
      printf("\nExiting program. Goodbye!\n");
      break;

    default:
      printf("\nInvalid choice! Please enter 1, 2, or 3.\n");
    }
  } while (choice != 3);

  return 0;
}

// Function to add two complex numbers:
// (a + bi) + (c + di) = (a + c) + (b + d)i
struct Complex add(struct Complex c1, struct Complex c2) {
  struct Complex temp;
  temp.real = c1.real + c2.real; // Add real parts
  temp.imag = c1.imag + c2.imag; // Add imaginary parts
  return temp;
}

// Function to multiply two complex numbers:
// (a + bi) * (c + di) = (a*c - b*d) + (a*d + b*c)i
struct Complex multiply(struct Complex c1, struct Complex c2) {
  struct Complex temp;
  temp.real = (c1.real * c2.real) - (c1.imag * c2.imag); // Real part
  temp.imag = (c1.real * c2.imag) + (c1.imag * c2.real); // Imaginary part
  return temp;
}

// Function to display complex numbers in standard a + bi or a - bi form
void display(struct Complex c) {
  if (c.imag >= 0) {
    printf("%.2f + %.2fi", c.real, c.imag);
  } else {
    // If imag is negative, print minus sign cleanly without "+ -"
    printf("%.2f - %.2fi", c.real, -c.imag);
  }
}
