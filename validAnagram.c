#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char * s, char * t){
  int length_str_1 = strlen(s);
  int length_str_2 = strlen(t);

  if(length_str_1 != length_str_2) {
    return false;
  };

  int s_count[26] = {0};
  int t_count[26] = {0};

  for (int i = 0; i < length_str_1; i++) {
    s_count[s[i] - 'a']++;
    t_count[t[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if(s_count[i] != t_count[i]) {
      return false;
    }
  }

  return true;
}


int main() {
  char *s = "ac";
  char *t = "bb";
  bool anagram = isAnagram(s, t);
  printf("%d\n", anagram);
  return 0;
}
