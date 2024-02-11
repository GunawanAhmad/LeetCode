#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isSubsequence(char *s, char *t) {
  int indexS = 0, indexT = 0;

  while(s[indexS] != '\0' && t[indexT] != '\0') {
    if(s[indexS] == t[indexT]) {
      indexS++;
    }

    indexT++;
  }

  return s[indexS] == '\0';
}

int main() {
  char *s = "ab";
  char *t = "baab";
  bool check = isSubsequence(s, t);
  printf("%d\n", check);
}
