#include <iostream>

#include "List.h"
using namespace std;
Node* Printknode(Node* head, int k) {
  Node* p = head;
  while (p->next != nullptr) {
    p = p->next;
    k--;
  }
  if (k == 0) {
    head = head->next;
  }
  if (k < 0) {
    p = head;
    while (++k != 0) {
      p = p->next;
    }
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
  Node* res = Printknode(pNode0, 2);
  Node* p = pNode0;
  while (p != nullptr) {
    cout << p->value << endl;
    p = p->next;
  }
}
