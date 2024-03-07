#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head) {
  if (head->next == NULL) {
    return head;
  }
  struct ListNode *slow = head;
  struct ListNode *fast = head->next;
  int counter = 2;

  while (slow && fast) {
    if (fast->next == NULL) {
      if (counter % 2 == 0) {
        return slow->next;
      }
      return slow;
    }
    slow = slow->next;
    fast = fast->next->next;
    counter += 2;
  }

  return slow;
}
