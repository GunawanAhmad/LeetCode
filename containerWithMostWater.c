#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
  if (a < b)
    return a;
  return b;
}

int maxArea(int *height, int heightSize) {
  int max = 0;

  int l = 0;
  int r = heightSize - 1;

  while(l < r) {
    int length = r - l;
    int height_min = min(height[l], height[r]);
    int area = length * height_min;
    if(area > max) {
      max = area;
    }
    if(height[l] < height[r]) {
      l++;
    } else {
      r--;
    }
  }

  return max;
}

int main(int argc, char *argv[]) {
  int height[] = {1,8,6,2,5,4,8,3,7};
  int size = 9;

  int test = maxArea(height, size);

  printf("%d\n", test);

  return EXIT_SUCCESS;
}
