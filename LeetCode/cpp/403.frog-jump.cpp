#include <functional>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canCross(vector<int>& stones) {
    unordered_set<int> h(stones.begin(), stones.end());
    unordered_map<long long, bool> memo;

    function<bool(int, int)> dfs = [&](int x, int y) {
      if (y <= 0 || !h.count(x)) return false;
      if (x == 1 && y == 1) return true;

      long long t = (long long)x << 32 | y;
      if (memo.count(t)) return memo[t];

      if (dfs(x - y, y) || dfs(x - y, y - 1) || dfs(x - y, y + 1))
        return memo[t] = true;
      return memo[t] = false;
    };

    for (int i = 1; i <= 1001; i++)
      if (dfs(stones.back(), i)) return true;
    return false;
  }
};

int main() {
  Solution sol;
  return 0;
}