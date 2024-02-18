#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int val;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct {
  Node *top;
} Stack;

Stack *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

Node *createNode(int val) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void push(Stack *stack, int val) {
  Node *node = createNode(val);
  if (stack->top != NULL) {
    Node *topNode = stack->top;
    topNode->right = node;
    node->left = topNode;
    stack->top = node;
  } else {
    stack->top = node;
  }
}

int pop(Stack *stack) {
  Node *lastNode = stack->top;
  if (lastNode->left != NULL) {
    lastNode->left->right = NULL;
  }
  stack->top = lastNode->left;
  return lastNode->val;
}

int evalRPN(char **tokens, int tokensSize) {
  Stack *stack = createStack();
  for (int i = 0; i < tokensSize; i++) {
    bool isAddition = strcmp(tokens[i], "+") == 0;
    bool isSubtraction = strcmp(tokens[i], "-") == 0;
    bool isDivision = strcmp(tokens[i], "/") == 0;
    bool isMultiplication = strcmp(tokens[i], "*") == 0;
    while (!isDivision && !isAddition && !isSubtraction && !isMultiplication &&
           i < tokensSize) {
      int val = atoi(tokens[i]);
      push(stack, val);
      i++;
      if (i < tokensSize) {
        isAddition = strcmp(tokens[i], "+") == 0;
        isSubtraction = strcmp(tokens[i], "-") == 0;
        isDivision = strcmp(tokens[i], "/") == 0;
        isMultiplication = strcmp(tokens[i], "*") == 0;
      }
    }
    if (isAddition) {
      int num2 = pop(stack);
      int num1 = pop(stack);
      int res = num1 + num2;
      push(stack, res);
    } else if (isMultiplication) {
      int num2 = pop(stack);
      int num1 = pop(stack);
      int res = num1 * num2;
      push(stack, res);
    } else if (isSubtraction) {
      int num2 = pop(stack);
      int num1 = pop(stack);
      int res = num1 - num2;
      push(stack, res);
    } else if (isDivision) {
      int num2 = pop(stack);
      int num1 = pop(stack);
      int res = num1 / num2;
      push(stack, res);
    }
  }

  return stack->top->val;
}

int main() {
  char *string[] = {"10", "6", "9",  "3", "+", "-11", "*",
                    "/",  "*", "17", "+", "5", "+"};
  int res = evalRPN(string, 13);
  printf("%d", res);
}
