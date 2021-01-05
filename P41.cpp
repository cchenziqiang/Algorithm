#include <iostream>

#include "List.h"
using namespace std;
void PrintCommon(Node* head1, Node* head2) {
  while (head1 != nullptr && head2 != nullptr) {
    if (head1->value > head2->value)
      head1 = head1->next;
    else if (head1->value < head2->value)
      head2 = head2->next;
    else {
      cout << head1->value << endl;
      head1 = head1->next;
      head2 = head2->next;
    }
  }
  return;
}

int main() {
  Node* pNode5 = new Node(3);
  Node* pNode4 = new Node(4, pNode5);
  Node* pNode3 = new Node(5, pNode4);
  Node* pNode2 = new Node(10, pNode3);
  Node* pNode1 = new Node(8, pNode3);
  Node* pNode0 = new Node(9, pNode1);
  PrintCommon(pNode0, pNode2);
}
