#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b) {
  int resultLength = 0;
  int strLenA = strlen(a);
  int strLenB = strlen(b);

  if (strLenA > strLenB) {
    resultLength = strLenA;
  } else {
    resultLength = strLenB;
  }

  char *result = (char *)malloc(sizeof(char) * (resultLength + 2));
  result[resultLength + 1] = '\0';
  int carry = 0;
  int indexForA = strLenA - 1;
  int indexForB = strLenB - 1;

  for (int i = resultLength; i >= 0; i--) {
    int numberA = 0;
    int numberB = 0;
    if (indexForA >= 0) {
      numberA = a[indexForA] - '0';
    }
    if (indexForB >= 0) {
      numberB = b[indexForB] - '0';
    }

    indexForA--;
    indexForB--;
    int tempResult = numberA + numberB + carry;
    if (tempResult == 3) {
      carry = 1;
      tempResult = 1;
    } else if (tempResult == 2) {
      tempResult = 0;
      carry = 1;
    } else if (tempResult == 1) {
      tempResult = 1;
      carry = 0;
    } else {
      tempResult = 0;
      carry = 0;
    }

    result[i] = tempResult + '0';
  }

  if (result[0] == '0') {
    for (int i = 0; i < resultLength; i++) {
      result[i] = result[i + 1];
    }

    result[resultLength] = '\0';
  }

  return result;
}

int main() {
  char *a = "100";
  char *b = "100110";
  char *res = addBinary(a, b);
  printf("%s\n", res);
}
