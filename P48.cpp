#include <iostream>

#include "List.h"
using namespace std;
Node* reverstPart(Node* head, int from, int to) {
  int len = 0;
  Node* node1 = head;
  Node* fpre = nullptr;
  Node* fPos = nullptr;
  while (node1) {
    ++len;
    fpre = (len == from - 1) ? node1 : fpre;
    fPos = (len == to + 1) ? node1 : fPos;
    node1 = node1->next;
  }

  if (from > to || from < 1 || to > len) return head;

  node1 = fpre == nullptr ? head : fpre->next;
  Node* node2 = node1->next;
  node1->next = fPos;
  Node* next = nullptr;
  while (node2 != fPos) {
    next = node2->next;
    node2->next = node1;
    node1 = node2;
    node2 = next;
  }
  if (fpre) {
    fpre->next = node1;
    return head;
  }
  return node1;
}

int main() {
  Node* pNode0 = new Node(0);
  Node* pNode1 = new Node(1, pNode0);
  Node* pNode2 = new Node(2, pNode1);
  Node* pNode3 = new Node(3, pNode2);
  Node* pNode4 = new Node(4, pNode3);

  Print(pNode4);
  cout << "======================" << endl;
  pNode4 = reverstPart(pNode4, 2, 4);
  Print(pNode4);
  DesList(pNode4);
}
