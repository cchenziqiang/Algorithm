#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int maxRecFromBottom(vector<int> height) {
  int maxArea;
  stack<int> stk;
  for (int i = 0; i < height.size(); i++) {
    while (!stk.empty() && height[i] <= height[stk.top()]) {
      int j = stk.top();
      int k = stk.empty() ? -1 : stk.top();
      int curArea = (i - k - 1) * height[j];
      stk.pop();
      maxArea = max(maxArea, curArea);
    }
    stk.push(i);
  }
  while (!stk.empty()) {
    int j = stk.top();
    stk.pop();
    int k = stk.empty() ? -1 : stk.top();
    int curArea = (height.size() - k - 1) * height[j];
    maxArea = max(maxArea, curArea);
  }
  return maxArea;
}

int maxRecSize(vector<vector<int>> map) {
  int maxArea;
  vector<int> height(map[0].size(), 0);
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[0].size(); j++) {
      height[j] = (map[i][j] == 0 ? height[j] : height[j] + 1);
    }
  }
  maxArea = max(maxRecFromBottom(height), maxArea);
  return maxArea;
}

int main() {
  vector<vector<int>> orignal;
  int a[] = {1, 0, 1, 1};
  vector<int> res(a, a + 4);
  int b[] = {1, 1, 1, 1};
  vector<int> res2(b, b + 4);
  int c[] = {1, 1, 1, 0};
  vector<int> res3(c, c + 4);
  orignal.push_back(res);
  orignal.push_back(res2);
  orignal.push_back(res3);
  cout << maxRecSize(orignal) << endl;
}