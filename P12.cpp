#include <exception>
#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &Sint) {
  stack<int> help;
  while (!Sint.empty()) {
    int val = Sint.top();
    Sint.pop();

    while (!help.empty() && val > help.top()) {
      Sint.push(help.top());
      help.pop();
    }
    help.push(val);
  }

  while (!help.empty()) {
    Sint.push(help.top());
    help.pop();
  }
}
int main() {
  stack<int> orignal;
  orignal.push(1);
  orignal.push(2);
  orignal.push(3);
  orignal.push(4);
  sortStack(orignal);
  while (!orignal.empty()) {
    cout << orignal.top() << endl;
    orignal.pop();
  }
}
