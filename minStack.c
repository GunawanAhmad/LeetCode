
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int val) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->val = val;
  node->left = NULL;
  node->right = NULL;

  return node;
}

typedef struct {
  Node *node;
  Node *min;
} MinStack;

MinStack *minStackCreate() {
  MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
  stack->min = NULL;
  stack->node = NULL;
  return stack;
}

void minStackPush(MinStack *obj, int val) {
  Node *node = createNode(val);
  if (obj->node == NULL) {
    Node *min = createNode(val);
    obj->node = node;
    obj->min = min;
  } else {
    node->left = obj->node;
    obj->node->right = node;
    obj->node = node;
    if (val <= obj->min->val) {
      Node *min = createNode(val);
      obj->min->right = min;
      min->left = obj->min;
      obj->min = min;
    }
  }
}

void minStackPop(MinStack *obj) {
  Node *lastNode = obj->node;
  Node *newLastNode = lastNode->left;
  if (newLastNode != NULL) {
    newLastNode->right = NULL;
  }
  if (lastNode->val == obj->min->val) {
    Node *min = obj->min;
    obj->min = min->left;
    if(obj->min != NULL) {
      obj->min->right = NULL;
    }
    free(min);
  }
  free(lastNode);
  obj->node = newLastNode;
}

int minStackTop(MinStack *obj) { return obj->node->val; }

int minStackGetMin(MinStack *obj) { return obj->min->val; }

void minStackFree(MinStack *obj) { free(obj); }

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/

int main() {
  MinStack *stack = minStackCreate();
  minStackPush(stack, 214748364);
  minStackPush(stack, 214748364);
  minStackPush(stack, 214748364);
  printf("%d\n", minStackTop(stack));
  minStackPop(stack);
  minStackPop(stack);
  minStackPop(stack);
  minStackPush(stack, 214748364);
}
