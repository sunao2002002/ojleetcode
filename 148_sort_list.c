#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

static struct ListNode *merge(struct ListNode *a, struct ListNode *b) {

  struct ListNode head, *tail;
  tail = &head;
  while (a && b) {
    if ((a->val <= b->val)) {
      tail->next = a;
      a = a->next;
    } else {
      tail->next = b;
      b = b->next;
    }
    tail = tail->next;
  }
  tail->next = a ?: b;
  return head.next;
}
#define MAX_LIST_LENGTH_BITS 31

struct ListNode *sortList(struct ListNode *head) {
  struct ListNode *part[MAX_LIST_LENGTH_BITS + 1];
  int lev;
  int max_lev = 0;
  struct ListNode *bnode;

  if (head == NULL || head->next == NULL)
    return head;
  memset(part, 0, sizeof(part));
  bnode = head;

  while (bnode) {
    struct ListNode *cur = bnode;
    bnode = bnode->next;
    cur->next = NULL;

    for (lev = 0; part[lev]; lev++) {
      cur = merge(part[lev], cur);
      part[lev] = NULL;
    }
    if (lev > max_lev) {
      if ((lev >= MAX_LIST_LENGTH_BITS)) {
        lev--;
      }
      max_lev = lev;
    }
    part[lev] = cur;
  }

  for (lev = 0; lev < max_lev; lev++)
    if (part[lev])
      bnode = merge(part[lev], bnode);

  bnode = merge(part[max_lev], bnode);

  return bnode;
}
