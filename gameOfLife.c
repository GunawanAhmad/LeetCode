#include <stdio.h>
#include <stdlib.h>

void gameOfLife(int **board, int boardSize, int *boardColSize) {

  int **boardCopy = (int **)malloc(sizeof(int *) * boardSize);

  for (int i = 0; i < boardSize; i++) {
    boardCopy[i] = (int *)malloc(sizeof(int) * (*boardColSize));
    for (int j = 0; j < *boardColSize; j++) {
      boardCopy[i][j] = board[i][j];
    }
  }

  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < *boardColSize; j++) {
      int totalAlive = 0;
      if (i > 0 && j > 0) {
        totalAlive += boardCopy[i - 1][j - 1];
      }
      if (i > 0 && j < *boardColSize - 1) {
        totalAlive += boardCopy[i - 1][j + 1];
      }
      if (i < boardSize - 1 && j < *boardColSize - 1) {
        totalAlive += boardCopy[i + 1][j + 1];
      }
      if (i < boardSize - 1 && j > 0) {
        totalAlive += boardCopy[i + 1][j - 1];
      }
      if (i > 0) {
        totalAlive += boardCopy[i - 1][j];
      }
      if (i < boardSize - 1) {
        totalAlive += boardCopy[i + 1][j];
      }
      if (j > 0) {
        totalAlive += boardCopy[i][j - 1];
      }
      if (j < *boardColSize - 1) {
        totalAlive += boardCopy[i][j + 1];
      }

      if (totalAlive < 2 || totalAlive > 3) {
        board[i][j] = 0;
      }
      if (totalAlive == 3 && board[i][j] == 0) {
        board[i][j] = 1;
      }
    }
  }
}

int main() {
  // Define the dimensions of the matrix
  int rows = 6;
  int cols = 6;

  // Allocate memory for the matrix
  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }

  // Initialize the matrix with the provided values
  int initial_values[6][6] = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};

  // Populate the matrix with initial values
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = initial_values[i][j];
    }
  }

  // Printing the initialized matrix
  printf("Initialized Matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Call the gameOfLife function
  gameOfLife(matrix, rows, &cols);

  // Printing the resulting matrix
  printf("Return Matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Free allocated memory
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}
