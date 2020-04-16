/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
      if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (p[j - 1] != '*')
          dp[i][j] =
              dp[i - 1][j - 1] and (p[j - 1] == '?' or s[i - 1] == p[j - 1]);
        else
          dp[i][j] = dp[i][j - 1] or dp[i - 1][j];
      }
    }
    return dp[m][n];
  }
};
// @lc code=end
