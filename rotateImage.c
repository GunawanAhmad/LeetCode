#include <stdio.h>
#include <stdlib.h>
void rotate(int **matrix, int matrixSize, int *matrixColSize) {
  int l = 0;
  int r = matrixSize - 1;
  *matrixColSize = matrixSize;

  while (l < r) {
    for (int i = 0; i < r - l; i++) {
      int temp = matrix[l][l + i]; // Store top-left element

      // Move elements from top to right
      matrix[l][l + i] = matrix[r - i][l];

      // Move elements from right to bottom
      matrix[r - i][l] = matrix[r][r - i];

      // Move elements from bottom to left
      matrix[r][r - i] = matrix[l + i][r];

      // Move elements from left to top
      matrix[l + i][r] = temp;
    }

    l++;
    r--;
  }
}

void printMatrix(int **matrix, int matrixSize, int *matrixColSize) {
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Example matrix
  int matrixSize = 3;
  int matrixColSize = 3;

  // Allocate memory for the matrix
  int **matrix = (int **)malloc(matrixSize * sizeof(int *));
  for (int i = 0; i < matrixSize; i++) {
    matrix[i] = (int *)malloc(matrixColSize * sizeof(int));
  }

  // Initialize the matrix
  int count = 1;
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixColSize; j++) {
      matrix[i][j] = count++;
    }
  }

  // Print original matrix
  printf("Original matrix:\n");
  printMatrix(matrix, matrixSize, &matrixColSize);

  // Rotate the matrix
  rotate(matrix, matrixSize, &matrixColSize);

  // Print rotated matrix
  printf("\nRotated matrix:\n");
  printMatrix(matrix, matrixSize, &matrixColSize);

  return 0;
}
