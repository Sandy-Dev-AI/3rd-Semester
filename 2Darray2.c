// Write a program for the addition of two sparse matrices and representing them
// in triplet form

#include <stdio.h>

#define MAX 100

// Function prototypes
void readSparse(int s[][3], const char *name);
void displaySparse(int s[][3], const char *name);
int addSparse(int a[][3], int b[][3], int result[][3]);

int main() {
  int s1[MAX][3], s2[MAX][3], result[MAX][3];

  printf("=== SPARSE MATRIX ADDITION (TRIPLET FORM) ===\n\n");

  // 1. Read first sparse matrix in triplet form
  readSparse(s1, "Matrix 1");

  // 2. Read second sparse matrix in triplet form
  readSparse(s2, "Matrix 2");

  // 3. Display both input sparse matrices
  printf("\n--- Input Matrices in Triplet Form ---");
  displaySparse(s1, "Matrix 1");
  displaySparse(s2, "Matrix 2");

  // 4. Perform addition
  if (addSparse(s1, s2, result)) {
    printf("\n--- Addition Result in Triplet Form ---");
    displaySparse(result, "Resultant Matrix (Matrix 1 + Matrix 2)");
  }

  return 0;
}

// Function to read a sparse matrix directly in triplet format
void readSparse(int s[][3], const char *name) {
  int rows, cols, numNonZero;

  printf("Enter number of rows, columns, and non-zero elements for %s: ", name);
  scanf("%d %d %d", &rows, &cols, &numNonZero);

  // Header row: [Total Rows, Total Columns, Total Non-Zero Elements]
  s[0][0] = rows;
  s[0][1] = cols;
  s[0][2] = numNonZero;

  printf("Enter triplets (Row Col Value) in row-major order for %s:\n", name);
  for (int i = 1; i <= numNonZero; i++) {
    scanf("%d %d %d", &s[i][0], &s[i][1], &s[i][2]);
  }
  printf("\n");
}

// Function to display a sparse matrix in triplet table format
void displaySparse(int s[][3], const char *name) {
  int nonZero = s[0][2];

  printf("\n%s:\n", name);
  printf("---------------------------\n");
  printf(" Row   Col   Value\n");
  printf("---------------------------\n");
  printf(" %3d   %3d   %5d   (Header: %d x %d with %d non-zeros)\n", s[0][0],
         s[0][1], s[0][2], s[0][0], s[0][1], s[0][2]);
  printf("---------------------------\n");

  for (int i = 1; i <= nonZero; i++) {
    printf(" %3d   %3d   %5d\n", s[i][0], s[i][1], s[i][2]);
  }
  printf("---------------------------\n");
}

// Function to add two sparse matrices represented in triplet form
// Returns 1 on success, 0 if dimensions do not match
int addSparse(int a[][3], int b[][3], int result[][3]) {
  // Check dimension compatibility: rows and columns must match
  if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
    printf("\nError: Matrix dimensions do not match (%dx%d vs %dx%d). Cannot "
           "add!\n",
           a[0][0], a[0][1], b[0][0], b[0][1]);
    return 0;
  }

  // Result header initialization
  result[0][0] = a[0][0]; // Total rows
  result[0][1] = a[0][1]; // Total columns

  int i = 1; // Index pointer for matrix a
  int j = 1; // Index pointer for matrix b
  int k = 1; // Index pointer for result matrix

  int t1 = a[0][2]; // Number of non-zero elements in a
  int t2 = b[0][2]; // Number of non-zero elements in b

  // Merge-like traversal: compare positions (row, col) of both matrices
  while (i <= t1 && j <= t2) {
    // Case 1: Row of 'a' comes before Row of 'b'
    // OR Same row, but Column of 'a' comes before Column of 'b'
    if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
      result[k][0] = a[i][0];
      result[k][1] = a[i][1];
      result[k][2] = a[i][2];
      i++;
      k++;
    }
    // Case 2: Row of 'b' comes before Row of 'a'
    // OR Same row, but Column of 'b' comes before Column of 'a'
    else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
      result[k][0] = b[j][0];
      result[k][1] = b[j][1];
      result[k][2] = b[j][2];
      j++;
      k++;
    }
    // Case 3: Both elements are at the same (Row, Column) position
    else {
      int sumVal = a[i][2] + b[j][2];
      // Only add to result if sum is non-zero
      if (sumVal != 0) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = sumVal;
        k++;
      }
      i++;
      j++;
    }
  }

  // Copy any remaining elements from matrix 'a'
  while (i <= t1) {
    result[k][0] = a[i][0];
    result[k][1] = a[i][1];
    result[k][2] = a[i][2];
    i++;
    k++;
  }

  // Copy any remaining elements from matrix 'b'
  while (j <= t2) {
    result[k][0] = b[j][0];
    result[k][1] = b[j][1];
    result[k][2] = b[j][2];
    j++;
    k++;
  }

  // Set total non-zero elements in result header
  result[0][2] = k - 1;

  return 1;
}
