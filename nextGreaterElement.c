/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size,
                        int *returnSize) {
  int *result = (int *)malloc(sizeof(int) * nums1Size);
  *returnSize = nums1Size;

  for (int i = 0; i < nums1Size; i++) {
    int greaterElement = -1;
    bool found = false;

    for (int j = 0; j < nums2Size; j++) {
      if (nums1[i] == nums2[j]) {
        found = true;
      }
      if (nums2[j] > nums1[i] && found) {
        greaterElement = nums2[j];
        break;
      }
    }
    result[i] = greaterElement;
  }

  return result;
}

void print(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

int main(int argc, char *argv[]) {
  int nums1[] = {1, 3, 5, 2, 4};
  int nums2[] = {6, 5, 4, 3, 2, 1, 6, 7};
  int returnSize = 0;

  int *result = nextGreaterElement(nums1, 5, nums2, 8, &returnSize);

  print(result, returnSize);

  return EXIT_SUCCESS;
}
