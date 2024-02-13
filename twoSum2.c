/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
  int i = 0, j = numbersSize - 1;

  int *sum = (int *)malloc(sizeof(int) * 2);

  while (i < j) {
    int addResult = numbers[i] + numbers[j];
    if (addResult == target) {
      sum[0] = i + 1;
      sum[1] = j + 1;
      break;
    } else if (addResult >= target) {
      j--;
    } else {
      i++;
    }
  }

  *returnSize = 2;
  return sum;
}

void printResult(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d", arr[i]);
  }
}

int main() {
  int numbers[] = {2, 7, 11, 15};
  int *ret = (int *)malloc(sizeof(int));
  int *result = twoSum(numbers, 4, 9, ret);
  printResult(result, 2);
}
