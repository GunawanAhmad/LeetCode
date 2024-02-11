#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseWords(char *s) {
  int inputLen = strlen(s);
  char *result = (char *)malloc(sizeof(char) * (inputLen + 1));
  int index = 0;
  int resultCapacity = 0;
  result[0] = '\0';
  while (s[index] != '\0') {
    if (s[index] != ' ') {
      char *word = (char *)malloc(sizeof(char) * (inputLen + 1));
      int wordIndex = 0;

      while (s[index] != ' ' && s[index] != '\0') {
        word[wordIndex++] = s[index++];
      }
      word[wordIndex] = '\0';

      for (int i = wordIndex - 1; i >= 0; i--) {
        result[resultCapacity++] = word[i];
      }

      result[resultCapacity++] = ' ';

      free(word);
    } else {
      index++;
    }
  }

  if (result[resultCapacity - 1] == ' ') {
    result[resultCapacity - 1] = '\0';
    resultCapacity -= 1;
  } else {
    result[resultCapacity] = '\0';
  }

  for (int i = 0, j = resultCapacity - 1; i < j; i++, j--) {
    char temp = result[i];
    result[i] = result[j];
    result[j] = temp;
  }

  return result;
}

int main() {
  char *string = "                 gunawan  nur    ahmad          ";
  char *res = reverseWords(string);
  printf("%s", res);
}
