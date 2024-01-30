#include <stdio.h>
#include <stdlib.h>

void printArray(int *nums, int numsSize) {
  for (int i = 0; i < numsSize; i++) {
    printf("%d", nums[i]);
  }
}

void rotate(int *nums, int numsSize, int k) {
  int sliceIndex;

  if (k <= numsSize) {
    sliceIndex = k;
  } else {
    sliceIndex = k - numsSize;
  }

  if (sliceIndex > numsSize / 2) {
    sliceIndex = sliceIndex % numsSize;
  }

  int *tempArray = (int *)malloc(sizeof(int) * (numsSize));

  for (int i = 0; i < numsSize; i++) {
    tempArray[i] = nums[i];
  }

  int counter = 0;
  for (int i = sliceIndex; i > 0; i--) {
    nums[i - 1] = tempArray[numsSize - 1 - counter];
    counter++;
  }

  for (int i = 0; i < numsSize - sliceIndex; i++) {
    nums[i + sliceIndex] = tempArray[i];
  }

  free(tempArray);

  printArray(nums, numsSize);
}

int main() {
  int size = 2;
  int nums[2] = {1, 2};
  rotate(nums, size, 5);
}
