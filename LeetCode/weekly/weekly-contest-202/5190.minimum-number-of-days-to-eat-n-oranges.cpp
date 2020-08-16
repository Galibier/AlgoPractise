#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  map<int, int> dp;
  int minDays(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp.count(n)) return dp[n];
    int res = min(minDays(n / 2) + n % 2 + 1, minDays(n / 3) + n % 3 + 1);
    dp[n] = res;
    return res;
  }
};

int main() {
  Solution sol;
  cout << sol.minDays(10) << endl;
  //   cout << sol.minDays(6) << endl;

  return 0;
}