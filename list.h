
class Node {
 private:
 public:
  int value;
  Node* next;
  Node(int n) {
    value = n;
    next = nullptr;
  }
  Node(int n, Node* m) {
    value = n;
    next = m;
  }
};