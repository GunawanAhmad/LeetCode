#include<stdio.h>
#include<stdlib.h>
#define N 100000

typedef struct entry {
  int key;
  int value;
} entry;


int hash(int key, int value, int numsSize, Hash* hash_table) {
  entry* new_item = (entry*) malloc(sizeof(entry));
  new_item->key = key;
  new_item->value = value;
  int index = key % numsSize;
  hash_table[index] = new_item;
  return key % numsSize;
}

bool checkHash(int val, Hash* hash_table) {
  if(hash_table[val] != NULL) {
    return true;
  } else {
    return false;
  }
}

bool containsDuplicate(int* nums, int numsSize) {
  struct Hash hash_table[numsSize];
}


int main() {
  printf("%d\n", hash(10, 10, 3));
  printf("%d\n", hash_table[0]->value);
  int arr[3] = {1,2,3};
  containsDuplicate(arr, 3);
  return 0;
}



