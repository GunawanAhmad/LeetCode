#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int lengthOfLastWord(char * s){
  int strLength = strlen(s);
  int length = 0;
  bool charFound = false;
  for (int i = strLength; i >= 0; i--) {
    if(s[i] != ' ' && s[i] != '\0') {
      charFound = true;
      length = length + 1;
    } else if(s[i] == ' ' && charFound) {
      break;
    }
  }
  return length;
}

int main() {
  char *str = "   fly me   to   the moon  ";
  int lastWordLength = lengthOfLastWord(str);
  printf("%d\n", lastWordLength);
}


