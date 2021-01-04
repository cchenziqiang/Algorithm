#include <iostream>
#include <stack>
using namespace std;

int getAndRemoveLast(stack<int> &orignal) {
  int result = orignal.top();
  orignal.pop();
  if (orignal.empty())
    return result;
  else {
    int last = getAndRemoveLast(orignal);
    orignal.push(result);
    return last;
  }
}

void rever(stack<int> &orignal) {
  if (orignal.empty()) return;
  int val = getAndRemoveLast(orignal);
  rever(orignal);
  orignal.push(val);
}
