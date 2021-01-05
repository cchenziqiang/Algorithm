#include <cmath>
#include <iostream>

#include "List.h"
using namespace std;
Node* RemoveMidNode(Node* head) {
  if (head == nullptr || head->next == nullptr) return head;
  if (head->next->next == nullptr) return head->next;
  Node* pre = head;
  Node* cur = head->next->next;
  while (cur->next != nullptr && cur->next->next != nullptr) {
    pre = pre->next;
    cur = cur->next->next;
  }
  pre->next = pre->next->next;
  return head;
}

Node* RemoveabNode(Node* head, int a, int b) {
  int n = 0;
  Node* p = head;
  if (a < 1 || a > b) return head;
  while (p != nullptr) {
    p = p->next;
    n++;
  }
  int k = (int)ceil((double)(a * n) / (double)b);

  if (k == 1) return head->next;
  if (k > 1) {
    p = head;
    while (--k != 1) p = p->next;
    p->next = p->next->next;
  }
  return head;
}
int main() {
  Node* pNode5 = new Node(3);
  Node* pNode4 = new Node(4, pNode5);
  Node* pNode3 = new Node(5, pNode4);
  Node* pNode1 = new Node(8, pNode3);
  Node* pNode0 = new Node(9, pNode1);
  Node* res = RemoveMidNode(pNode0);
  Node* p = pNode0;
  while (p != nullptr) {
    cout << p->value << endl;
    p = p->next;
  }
}
