#include<stdio.h>

void shiftArray(int* nums, int numsSize, int skip, int startIndex) {
  // printf("skip: %d\n", nums[i + skip]);
  for(int i = startIndex; i < numsSize - skip; i++) {
      nums[i] = nums[i + skip];
  }
}

int removeDuplicates(int* nums, int numsSize){
  int length = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    int skip = 0;
    for (int j = i + 1; j < numsSize; j++) {
      if(nums[j] == nums[i]) {
        skip++;
      } else {
        length++;
        break;
      }
    }
    if(skip > 0) {
      shiftArray(nums, numsSize, skip, i);
      numsSize = numsSize - skip;
    }
  }

  return length + 1;
}

#define SIZE 4

int main() {
  int arr[SIZE] = {1,1,1,2};
  int length = removeDuplicates(arr, SIZE);
  for (int i = 0;i < SIZE;i++) {
    printf("%d\n", arr[i]);
  }

  printf("length: %d\n", length);
  return 0;
}



