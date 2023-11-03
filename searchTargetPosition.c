#include<stdio.h>

int searchInsert(int* nums, int numsSize, int target){
  int index = 0;
  bool found = false;
  for(int i = 0; i < numsSize; i++) {
    if(target == nums[i]) {
      index = i;
      found = true;
      break;
    }
    if(nums[i] > target) return i;
  }

  if(found) return index;
  return numsSize;
}

int main()
{
  int arr[4] = {1,3,5,6};
  int result = searchInsert(arr, 4, 7);
  printf("%d\n", result);
  return 0;
}



