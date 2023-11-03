#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char * s, char * t){
  int length = strlen(s);
  bool valid = true;

  for (int i = 0; i < length; i++) {
    if(s[i] != t[i]) {
      printf("%c\n", s[i]);
      valid = false;
    }
  }

  return valid;
}


int main() {
  char *s = "anagram";
  char *t = "nagaram";
  bool anagram = isAnagram(s, t);
  printf("%d\n", anagram);
  return 0;
}
