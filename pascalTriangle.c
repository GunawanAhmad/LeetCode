#include <stdio.h>
#include <stdlib.h>

int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
  *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
  int **result = (int **)malloc(sizeof(int *) * numRows);
  *returnSize = numRows;
  for (int n = 0; n < numRows; n++) {
    int *cols = (int *)malloc(sizeof(int) * (n + 1));
    for (int k = 0; k <= n; k++) {
      if(k == 0 || k == n) {
        cols[k] = 1;
      } else {
        cols[k] = result[n - 1][k - 1] + result[n - 1][k];
      }
    }
    result[n] = cols;
    (*returnColumnSizes)[n] = n + 1;
  }
  return result;
}

int main() {
    int numRows = 14; // Adjust this as needed
    int returnSize;
    int *returnColumnSizes;
    
    int **triangle = generate(numRows, &returnSize, &returnColumnSizes);
    
    // Printing the Pascal's triangle
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
    
    // Free memory
    for (int i = 0; i < returnSize; i++) {
        free(triangle[i]);
    }
    free(triangle);
    free(returnColumnSizes);
    
    return 0;
}

