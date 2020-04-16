/*
 * @lc app=leetcode id=1411 lang=cpp
 *
 * [1411] Number of Ways to Paint N × 3 Grid
 */

// @lc code=start
class Solution {
 public:
  int numOfWays(int n) {
    long long dp[n][2], div = 1e9 + 7;
    dp[0][0] = 6;
    dp[0][1] = 6;

    for (int i = 1; i < n; ++i) {
      dp[i][0] = ((dp[i - 1][0] * 3) % div + (dp[i - 1][1] * 2) % div) % div;
      dp[i][1] = ((dp[i - 1][0] * 2) % div + (dp[i - 1][1] * 2) % div) % div;
    }
    return (dp[n - 1][0] % div + dp[n - 1][1] % div) % div;
  }
};
// @lc code=end
