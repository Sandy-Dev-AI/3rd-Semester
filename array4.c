// WAP using function to perform addition and multiplication of two polynomials
// using plain arrays and a menu-driven switch case.

#include <stdio.h>
#define MAX 50

// Function prototypes using 'n'
void inputPoly(int p[], int n);
void displayPoly(int p[], int n);
void addPoly(int p1[], int n1, int p2[], int n2);
void multiplyPoly(int p1[], int n1, int p2[], int n2);

int main() {
  setbuf(stdout, NULL); // Disable output buffering for smooth terminal display

  int p1[MAX] = {0}, p2[MAX] = {0};
  int n1, n2;
  int choice;

  // Read first polynomial
  printf("Enter highest degree of first polynomial: ");
  scanf("%d", &n1);
  printf("Enter coefficients for first polynomial:\n");
  inputPoly(p1, n1);

  // Read second polynomial
  printf("\nEnter highest degree of second polynomial: ");
  scanf("%d", &n2);
  printf("Enter coefficients for second polynomial:\n");
  inputPoly(p2, n2);

  // Menu-driven loop using switch-case
  do {
    printf("\n========== POLYNOMIAL MENU ==========\n");
    printf("1. Display both polynomials\n");
    printf("2. Add polynomials\n");
    printf("3. Multiply polynomials\n");
    printf("4. Exit\n");
    printf("======================================\n");
    printf("Enter your choice (1-4): ");
    if (scanf("%d", &choice) != 1) {
      break;
    }

    switch (choice) {
    case 1:
      printf("\nPolynomial 1: ");
      displayPoly(p1, n1);
      printf("Polynomial 2: ");
      displayPoly(p2, n2);
      break;

    case 2:
      printf("\n--- Addition Result ---\n");
      printf("Sum: ");
      addPoly(p1, n1, p2, n2);
      break;

    case 3:
      printf("\n--- Multiplication Result ---\n");
      printf("Product: ");
      multiplyPoly(p1, n1, p2, n2);
      break;

    case 4:
      printf("\nExiting program. Goodbye!\n");
      break;

    default:
      printf("\nInvalid choice! Please choose 1, 2, 3, or 4.\n");
    }
  } while (choice != 4);

  return 0;
}

// Function to take coefficient inputs from power 'n' down to 0
void inputPoly(int p[], int n) {
  for (int i = n; i >= 0; i--) {
    printf("  Coefficient of x^%d: ", i);
    scanf("%d", &p[i]);
  }
}

// Function to print a polynomial nicely: e.g. 3x^2 + 2x + 1
void displayPoly(int p[], int n) {
  int first = 1;
  for (int i = n; i >= 0; i--) {
    if (p[i] != 0) {
      if (!first && p[i] > 0) {
        printf(" + ");
      } else if (!first && p[i] < 0) {
        printf(" - ");
      }

      int val = (!first && p[i] < 0) ? -p[i] : p[i];

      if (i == 0) {
        printf("%d", val);
      } else if (i == 1) {
        printf("%dx", val);
      } else {
        printf("%dx^%d", val, i);
      }
      first = 0;
    }
  }
  if (first) {
    printf("0");
  }
  printf("\n");
}

// Function to add two polynomials
void addPoly(int p1[], int n1, int p2[], int n2) {
  int max_n = (n1 > n2) ? n1 : n2;
  int sum[MAX] = {0};

  // Simply add coefficients at each power index
  for (int i = 0; i <= max_n; i++) {
    sum[i] = p1[i] + p2[i];
  }

  displayPoly(sum, max_n);
}

// Function to multiply two polynomials
void multiplyPoly(int p1[], int n1, int p2[], int n2) {
  int prod_n = n1 + n2;
  int prod[MAX * 2] = {0};

  // Multiply every term and add power indices (i + j)
  for (int i = 0; i <= n1; i++) {
    for (int j = 0; j <= n2; j++) {
      prod[i + j] += p1[i] * p2[j];
    }
  }

  displayPoly(prod, prod_n);
}