#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<vector<int>> getmax(vector<int>& arr) {
  stack<int> vmin;
  vector<vector<int>> res(arr.size(), vector<int>(2, 0));
  for (int i = 0; i < arr.size(); i++) {
    while (!vmin.empty() && arr[vmin.top()] > arr[i]) {
      int temp = vmin.top();
      vmin.pop();
      res[temp][1] = i;
      res[temp][0] = vmin.empty() ? -1 : vmin.top();
    }
    vmin.push(i);
  }
  while (!vmin.empty()) {
    int temp = vmin.top();
    vmin.pop();
    res[temp][1] = -1;
    res[temp][0] = vmin.empty() ? -1 : vmin.top();
  }
  return res;
}

int main() {
  vector<int> ans = {3, 4, 1, 5, 6, 2, 7};
  vector<vector<int>> res = getmax(ans);
  for (int i = 0; i < ans.size(); i++) {
    cout << "{" << res[i][0] << "," << res[i][1] << "}" << endl;
  }
}