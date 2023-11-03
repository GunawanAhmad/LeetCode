#include<stdio.h>
#define N 6

void shift(int* nums, int index, int numsSize) {
  for (int i = index; i < numsSize; i++) {
    int replace;
    if(i + 1 == numsSize) {
      replace = -1;
    } else {
      replace = nums[i + 1];
    }
    nums[i] = replace;
  }
}

int removeElement(int* nums, int numsSize, int val){
  int elmWithoutVal = numsSize;
  for (int i = 0; i < numsSize; i++) {
    if(nums[i] == val) {
      elmWithoutVal = elmWithoutVal - 1;
      shift(nums, i, numsSize);
      i = i - 1;
    }
  }

  return elmWithoutVal;
}


int main()
{
  int a[N] = {4,4,0,1,0,2};
  int ret = removeElement(a, N, 0);
  printf("%d\n\n", ret);

  for (int i = 0; i < N; i++) {
    printf("%d\n", a[i]);
  }


  return 0;
}
