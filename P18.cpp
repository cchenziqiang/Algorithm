#include <deque>
#include <iostream>
#include <vector>
using namespace std;

vector<int>& getMax(vector<int>& arr, int w) {
  vector<int> res;
  if (arr.size() == 0 || w < 1 || arr.size() < w) {
    return res;
  }
  deque<int> qmax;
  for (int i = 0; i < arr.size(); ++i) {
    while (!qmax.empty() && arr[qmax.back()] <= arr[i]) qmax.pop_back();
    qmax.push_back(i);
    if (qmax.front() == i - w) qmax.pop_front();
    if (i >= w - 1) res.push_back(arr[qmax.front()]);
  }
  return res;
}
int main() {
  vector<int> orignal;
  orignal.push_back(4);
  orignal.push_back(3);
  orignal.push_back(5);
  orignal.push_back(4);
  orignal.push_back(3);
  orignal.push_back(3);
  orignal.push_back(6);
  orignal.push_back(7);

  vector<int> res;
  res = getMax(orignal, 3);
  for (int i = 0; i < res.size(); ++i) cout << res[i] << endl;
}
