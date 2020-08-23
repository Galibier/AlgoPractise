#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLatestStep(vector<int>& a, int m) {
    int n = a.size();
    set<pair<int, int>> ones;
    ones.insert({1, n});

    if (m == n) return n;

    int res = -1;
    for (int i = n - 1; i >= 0; --i) {
      int x = a[i];
      auto it = ones.upper_bound(pair<int, int>(x + 1, 0));
      --it;
      auto [left, right] = *it;
      ones.erase(it);
      if (left <= x - 1) {
        ones.insert({left, x - 1});
        if (x - left == m) res = max(res, i);
      }
      if (x + 1 <= right) {
        ones.insert({x + 1, right});
        if (right - x == m) res = max(res, i);
      }
    }

    return res;
  }
};

int main() {
  Solution sol;
  return 0;
}