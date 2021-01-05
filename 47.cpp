Node* ReverseList(Node* head) {
  Node* p = head->next;
  Node* pre = nullptr;
  head->next = nullptr;
  while (p != nullptr) {
    pre = p->next;
    p->next = head;
    head = p;
    p = pre;
  }
  return head;
}