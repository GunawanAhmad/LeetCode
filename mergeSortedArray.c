#include <stdio.h>
#include <stdlib.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  int *tempArray = (int *)malloc(sizeof(int) * (m + n));
  int pointerNums1 = 0;
  int pointerNums2 = 0;
  for (int i = 0; i < m + n; i++) {
    if (pointerNums1 >= m && pointerNums2 < n) {
      tempArray[i] = nums2[pointerNums2];
      pointerNums2++;
    } else if (pointerNums2 >= n && pointerNums1 < m) {
      tempArray[i] = nums1[pointerNums1];
      pointerNums1++;
    } else {
      if (nums1[pointerNums1] < nums2[pointerNums2]) {
        tempArray[i] = nums1[pointerNums1];
        pointerNums1++;
      } else {
        tempArray[i] = nums2[pointerNums2];
        pointerNums2++;
      }
    }
  }

  for (int i; i < m + n; i++) {
    nums1[i] = tempArray[i];
  }

  free(tempArray);
}

void printArray(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", array[i]);
  }
}

int main() {
  int nums1[5] = {1, 2, 3, 4, 5};
  int nums2[3] = {6, 7, 8};
  merge(nums1, 5, 5, nums2, 3, 3);
  // printArray(nums1, 8);
}
