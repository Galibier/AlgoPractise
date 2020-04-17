/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // vector<vector<int>> dp(n, vector<int>(2, 0));

    // dp[0][0] = 0;
    // dp[0][1] = INT_MIN;
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for (int i = 0; i < n; i++) {
      //   dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
      //   dp[i][1] = max(dp[i - 1][1], -prices[i]);
      dp_i_1 = max(dp_i_1, -prices[i]);
    }

    // return dp[n - 1][0];
    return dp_i_0;
  }
};
// @lc code=end
