
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void addInorder(struct TreeNode* node, int* returnArr, int *index) {
  if(node == NULL) {
    return;
  }
  addInorder(node->left, returnArr, index);
  returnArr[*index] = node->val;
  (*index)++;
  addInorder(node->right, returnArr, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
  int* returnArr = (int*)malloc(sizeof(int) * 100);
  *returnSize = 0;
  addInorder(root, returnArr, returnSize);
  return returnArr;
}

struct TreeNode *createNode(int val) {
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}


void print(int* arr, int *len) {
  for(int i = 0; i < (*len); i++) {
    printf("%d\n", arr[i]);
  }
}

int main() {
  struct TreeNode *a = createNode(1);
  struct TreeNode *a_2 = createNode(2);
  struct TreeNode *a_3 = createNode(3);

  a->left = NULL;
  a->right = a_2;
  a_2->left = NULL;
  a_2->left = a_3;

//  b->left = b_2;
//  b->right = b_3;
  int returnSize = 0;
  int *res = inorderTraversal(a, &returnSize);
  print(res, &returnSize);

  return 0;
}
