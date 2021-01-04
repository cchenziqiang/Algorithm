#include <exception>
#include <iostream>
#include <stack>
using namespace std;
class StaMin {
 public:
  void push(int newNum) {
    if (stackMin.empty())
      stackMin.push(newNum);
    else if (newNum <= stackMin.top())
      stackMin.push(newNum);

    stackDate.push(newNum);
  }

  int pop() {
    if (stackDate.empty()) throw new exception();
    int value = stackDate.top();
    stackDate.pop();
    if (value == stackMin.top()) stackMin.pop();
    return value;
  }
  int getMin() {
    if (stackMin.empty())
      throw new exception();
    else
      return stackMin.top();
  }

 private:
  stack<int> stackDate;
  stack<int> stackMin;
};