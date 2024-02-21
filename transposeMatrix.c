/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
  if(matrixSize == 0) {
    return NULL;
  }
  int newRows = *matrixColSize;
  int newCols = matrixSize;
  *returnColumnSizes = (int*)malloc(sizeof(int) * newRows);
  int **result = (int**)malloc(sizeof(int*) * newRows);
  for (int i = 0; i < newRows; i++) {
    result[i] = (int*)malloc(sizeof(int) * newCols);
    (*returnColumnSizes)[i] = newCols;
  }

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < *matrixColSize; j++) {
      result[j][i] = matrix[i][j];
    }
  }
  *returnSize = newRows;
  return result;    
}


int main() {
    // Create a sample input matrix
    int rows = 3;
    int cols = 3;
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1; // Fill with consecutive numbers
        }
    }

    // Call the transpose function
    int returnSize;
    int* returnColumnSizes;
    int** transposedMatrix = transpose(matrix, rows, &cols, &returnSize, &returnColumnSizes);

    // Print the original matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Print the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", transposedMatrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < cols; i++) {
        free(transposedMatrix[i]);
    }
    free(transposedMatrix);
    free(returnColumnSizes);

    return 0;
}
