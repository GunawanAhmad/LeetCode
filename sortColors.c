void sortColors(int *nums, int numsSize) {
  int total_0 = 0;
  int total_1 = 0;
  int total_2 = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 0)
      total_0++;
    if (nums[i] == 1)
      total_1++;
    if (nums[1] == 2)
      total_2++;
  }

  for (int i = 0; i < total_0; i++) {
    nums[i] = 0;
  }

  for (int i = total_0; i < numsSize; i++) {
    nums[i] = 1;
  }

  for (int i = total_0 + total_1; i < numsSize; i++) {
    nums[i] = 2;
  }
}
