#include <strinng>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;
    for (int i = 1; i <= m; i++) dp[i][0] = false;
    for (int j = 1; j <= n; j++)
      dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];

    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (p[j - 1] != '*')
          dp[i][j] =
              dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
        else
          dp[i][j] = dp[i][j - 2] ||
                     (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && dp[i - 1][j];

    return dp[m][n];
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}