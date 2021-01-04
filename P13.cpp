#include <climits>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
 *  用递归解法解汉诺塔问题
 *
 */
/*
int process(int num, string left, string mid, string right,
            string from, string to)
            {
                if(num == 1)
                {
                    if(from == mid || to == mid)
                    {
                        cout << "move 1 from " << from << " to " << to << endl;
                        return 1;
                    }

                    else
                    {
                        cout << "move 1 from" << from << " to " << mid << "\n"
                        << "move 1 from " << mid << " to " << to << endl;
                        return 2;
                    }
                }

                if(from == mid || to == mid)
                {
                    string str = (from == left || to == left) ? right : left;
                    int part1 = process(num - 1, left, mid, right, from, str);
                    int part2 = 1;
                    cout << "move " << num << " from " << from << " to " << to
<< endl; int part3 = process(num - 1 , left, mid, right, str, to); return part1
+ part2 + part3;
                }
                else {
                    int part1 = process(num - 1, left, mid, right, from, to);
                    int part2 = 1;
                    cout << "move " << num << " from " << from << " to " << mid
<< endl; int part3 = process(num - 1, left, mid, right, to, from); int part4 =
1; cout << "move " << num << " from " << mid << " to " <<to << endl; int part5 =
process(num - 1, left, mid, right, from, to); return part1 + part2 + part3 +
part4 + part5;
                }
            }

int hanoiProlem1(int num, string left, string mid, string right)
{
    if(num < 1)
        return 0;
    return process(num, left, mid, right, left, right);
}
*/

/*
 *  用非递归解法解汉诺塔问题
 *
 */
enum Action { No, LToM, MToL, MToR, RToM };
int fStackAction(Action& record, Action preNoAct, Action nowAct, stack<int>& LS,
                 stack<int>& MS, string from, string to) {
  if (record != preNoAct && LS.top() < MS.top()) {
    int val = LS.top();
    LS.pop();
    MS.push(val);
    cout << "move " << val << " from " << from << " to " << to << endl;
    record = nowAct;
    return 1;
  }
  return 0;
}

int hanoiProblem2(int num, string left, string mid, string right) {
  stack<int> Ls;
  stack<int> Ms;
  stack<int> Rs;

  Ls.push(INT_MAX);
  Ms.push(INT_MAX);
  Rs.push(INT_MAX);

  for (int i = num; i > 0; --i) Ls.push(i);

  Action record = No;
  int step = 0;
  while (Rs.size() != num + 1) {
    step += fStackAction(record, MToL, LToM, Ls, Ms, left, mid);
    step += fStackAction(record, LToM, MToL, Ms, Ls, mid, left);
    step += fStackAction(record, MToR, RToM, Rs, Ms, mid, right);
    step += fStackAction(record, RToM, MToR, Ms, Rs, right, mid);
  }
  return step;
}
int main() { cout << hanoiProblem2(3, "left", "mid", "right"); }
