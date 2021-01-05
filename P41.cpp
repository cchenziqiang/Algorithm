#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct Node {
  int value;
  Node* next;
};

void PrintCommonpart(Node* head1, Node* head2) {
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
