// Write a program to create a sparse matrix
#include <stdio.h>

#define MAX 50

int main() {
  int m, n;
  int a[MAX][MAX];
  int nonZeroCount = 0;

  // 1. Read dimensions of the matrix
  printf("Enter number of rows and columns: ");
  scanf("%d %d", &m, &n);

  // 2. Read matrix elements and count non-zero elements
  printf("Enter the elements of the matrix (%d x %d):\n", m, n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] != 0) {
        nonZeroCount++;
      }
    }
  }

  // 3. Display the original matrix
  printf("\nOriginal Matrix:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%4d", a[i][j]);
    }
    printf("\n");
  }

  // Check if the matrix is sparse (zeros exceed non-zeros)
  int totalElements = m * n;
  if (nonZeroCount <= totalElements / 2) {
    printf("\nIt is a Sparse Matrix! (Non-zero elements: %d out of %d)\n",
           nonZeroCount, totalElements);
  } else {
    printf("\nNotice: Not strictly sparse (Non-zero elements: %d out of %d), "
           "but converting anyway...\n",
           nonZeroCount, totalElements);
  }

  // 4. Create the 3-Tuple (Triplet) representation
  // Size is (nonZeroCount + 1) rows and 3 columns
  int sparse[MAX][3];

  // Row 0 stores metadata: [Total Rows, Total Columns, Total Non-Zero Elements]
  sparse[0][0] = m;
  sparse[0][1] = n;
  sparse[0][2] = nonZeroCount;

  // Populate remaining rows with (Row, Column, Value) of each non-zero element
  int k = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != 0) {
        sparse[k][0] = i;       // row index
        sparse[k][1] = j;       // column index
        sparse[k][2] = a[i][j]; // value
        k++;
      }
    }
  }

  // 5. Display the Sparse Matrix (Triplet Representation)
  printf("\nSparse Matrix (Triplet Representation):\n");
  printf("---------------------------\n");
  printf(" Row   Col   Value\n");
  printf("---------------------------\n");
  for (int i = 0; i <= nonZeroCount; i++) {
    printf(" %3d   %3d   %5d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
  }
  printf("---------------------------\n");

  return 0;
}
