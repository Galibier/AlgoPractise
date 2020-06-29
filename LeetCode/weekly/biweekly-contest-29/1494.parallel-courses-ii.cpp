#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int minNumberOfSemesters(int n, vector<vector<int>> &d, int k) {
    // 记录每门课的依赖
    unordered_map<int, int> dep;
    for (int i = 1; i <= n; i++) {
      dep[i] = 0;
    }
    for (auto &v : d) {
      dep[v[1]] |= (1 << v[0]);
    }
    int res = 0;
    // 还有课未上
    while (dep.size() > 0) {
      // 记录本学期上的课
      vector<int> v;
      for (auto &[x, y] : dep) {
        // 只选择没有依赖的课
        if (y == 0) {
          v.push_back(x);
          if (v.size() == k) {
            break;
          }
        }
      }
      // 将选中的课删除,并且将其他课对该课的依赖删除
      for (int i : v) {
        for (auto &[x, y] : dep) {
          if (y > 0) {
            y &= ~(1 << i);
          }
        }
        dep.erase(i);
      }
      res++;
    }
    return res;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}