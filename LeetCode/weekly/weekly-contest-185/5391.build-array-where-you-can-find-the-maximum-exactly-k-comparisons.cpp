#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int numOfArrays(int n, int m, int k) {
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i += 1)
      for (int j = 0; j <= m; j += 1)
        for (int k = 0; k <= i; k += 1)
          for (int x = 1; x <= m; x += 1)
            add(dp[i + 1][max(x, j)][k + (x > j)], dp[i][j][k]);
    int ans = 0;
    for (int i = 1; i <= m; i += 1) add(ans, dp[n][i][k]);
    return ans;
  }

 private:
  static constexpr int mod = 1000000007;
  int dp[51][101][51];
  void add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.numOfArrays(2, 3, 1) << endl;
  cout << sol.numOfArrays(5, 2, 3) << endl;
  cout << sol.numOfArrays(9, 1, 1) << endl;
  cout << sol.numOfArrays(50, 100, 25) << endl;
  cout << sol.numOfArrays(37, 17, 7) << endl;
  return 0;
}

// https://leetcode-cn.com/contest/weekly-contest-185/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
