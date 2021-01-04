#include <exception>
#include <iostream>
#include <stack>
using namespace std;
class TwoQue {
 public:
  void add(int num) { stackPush.push(num); }
  int poll() {
    if (stackPop.empty() && stackPush.empty())
      throw new exception();
    else if (stackPop.empty()) {
      while (!stackPush.empty()) {
        int val = stackPush.top();
        stackPop.push(val);
        stackPush.pop();
      }
    }
    int val = stackPop.top();
    stackPop.pop();
    return val;
  }

  int top() {
    if (stackPop.empty() && stackPush.empty())
      throw new exception();
    else if (stackPop.empty()) {
      while (!stackPush.empty()) {
        int val = stackPush.top();
        stackPop.push(val);
        stackPush.pop();
      }
    }
    return stackPop.top();
  }

 private:
  stack<int> stackPush;
  stack<int> stackPop;
};
