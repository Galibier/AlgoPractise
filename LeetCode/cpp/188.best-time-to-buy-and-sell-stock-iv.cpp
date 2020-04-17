/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    if (k >= prices.size() / 2) {
      int dp_i_0 = 0, dp_i_1 = INT_MIN;
      for (int i = 0; i < prices.size(); i++) {
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, tmp - prices[i]);
      }

      return dp_i_0;
    }

    vector<int> dp_ik0(k + 1, 0);
    vector<int> dp_ik1(k + 1, INT_MIN);

    for (int price : prices) {
      for (int j = k; j > 0; j--) {
        // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
        dp_ik0[j] = max(dp_ik0[j], dp_ik1[j] + price);
        // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
        dp_ik1[j] = max(dp_ik1[j], dp_ik0[j - 1] - price);
      }
    }
    return dp_ik0[k];
  }
};
// @lc code=end
