#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

bool canConstruct(char *ransomNote, char *magazine) {
  bool constructable = true;
  int *hash = (int *)malloc(sizeof(int) * strlen(magazine));
  for (int i = 0; i < strlen(magazine); i++) {
    hash[i] = -1;
  }
  for (int i = 0; i < strlen(ransomNote); i++) {
    bool tempCheck = false;
    for (int j = 0; j < strlen(magazine); j++) {
      if (hash[j] == 1) {
        continue;
      }
      if (ransomNote[i] == magazine[j]) {
        hash[j] = 1;
        tempCheck = true;
        break;
      }
    }
    if (!tempCheck) {
      constructable = false;
      break;
    }
  }

  //printArr(hash, strlen(magazine));

  free(hash);

  return constructable;
}

int main() {
  char *ransom = "aa";
  char *magazine = "aab";
  bool check = canConstruct(ransom, magazine);
  printf("%d", check);
}
