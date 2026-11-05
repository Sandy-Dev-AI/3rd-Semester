// write a C program to dynamically allocate memory for an m x n 2D matrix using
// an array of pointers (malloc), read values, print the matrix, and properly
// free all allocated memory.
#include <stdio.h>
#include <stdlib.h>
int main() {
  int m, n;
  printf("Enter the number of rows and columns : ");
  scanf("%d %d", &m, &n);
  int **matrix = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    matrix[i] = (int *)malloc(n * sizeof(int));
  }
  printf("Enter the matrix elements :\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("The matrix is :\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < m; i++) {
    free(matrix[i]);
  }
  free(matrix);
  return 0;
}