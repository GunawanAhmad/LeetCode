#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(char *s) {
  int i = 0, j = strlen(s) - 1;
  while (i < j) {
    while (!isalpha(s[i]) && !isdigit(s[i]) && i < j)
      i++;
    while (!isalpha(s[j]) && !isdigit(s[j]) && i < j)
      j--;

    if (tolower(s[i]) != tolower(s[j]) && i < j) {
      return false;
    };

    i++;
    j--;
  }
  return true;
}

int main(int argc, char *argv[]) {
  char s[] = ".";
  bool t = isPalindrome(s);
  printf("%d", t);
}
