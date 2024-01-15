#include <stdio.h>
#include <stdlib.h>

struct Node {
  int key;
  int count;
  struct Node *left;
  struct Node *right;
};


struct Node* createNewNode(int value) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->key = value;
  node->count = 1;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct Node* searchNode(struct Node* root ,int targetValue) {
  if(root == NULL || root->key == targetValue) {
    return root;
  }

  if(targetValue < root->key) {
    return searchNode(root->left, targetValue);
  }

  return searchNode(root->right, targetValue);
}

struct Node* insertNode(struct Node* node, int value) {
  if (node == NULL) {
    return createNewNode(value);
  }

  if (value < node->key) {
    node->left = insertNode(node->left, value);
  } else if (value > node->key) {
    node->right = insertNode(node->right, value);
  } else {
    node->count = node->count + 1;
  }

  return node;  // Return the updated node
}



int majorityElement(int* nums, int numsSize) {
  if(numsSize < 1) {
    return -1;
  }
  
  struct Node* node = NULL;
  for(int i = 0; i < numsSize; i++) {
    node = insertNode(node, nums[i]);
    struct Node* curr = searchNode(node, nums[i]); 
    if(curr && curr-> count > numsSize / 2) {
      return curr->key;
    }
  }
  return -1;
}



int main() {
	int array[] = {6,5,5};
	int elm = majorityElement(array, 3);
  printf("%d", elm);
 	return 0;
}


