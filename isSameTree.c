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

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {

  if (p == NULL && q == NULL) {
    return true;
  }

  if (p == NULL || q == NULL) {
    return false;
  }

  if (p->val != q->val) {
    return false;
  }

  bool left = isSameTree(p->left, q->left);
  bool right = isSameTree(p->right, q->right);

  return left && right;
}

struct TreeNode *createNode(int val) {
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->val = val;
  node->left = NULL;
  node->right = NULL;

  return node;
}

int main() {
  struct TreeNode *a = createNode(1);
  struct TreeNode *b = createNode(1);
  struct TreeNode *a_2 = createNode(2);
  struct TreeNode *a_3 = createNode(3);
  struct TreeNode *b_2 = createNode(2);
  struct TreeNode *b_3 = createNode(3);

  a->left = a_2;
  a->right = a_3;

  b->left = b_2;
  b->right = b_3;

  bool isSame = isSameTree(a, b);

  printf("%d", isSame);

  return 0;
}
