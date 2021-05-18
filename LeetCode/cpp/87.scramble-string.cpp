#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    return Recursion(s1, s2);
  }
  bool Recursion(string s1, string s2) {
    if (s1 == s2) return true;
    string t1 = s1, t2 = s2;
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if (t1 != t2) return false;

    for (int i = 1; i < s1.size(); i++) {
      bool flag1 =
          Recursion(s1.substr(0, i), s2.substr(0, i)) &&
          Recursion(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i));
      bool flag2 =
          Recursion(s1.substr(0, i), s2.substr(s2.size() - i, i)) &&
          Recursion(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i));
      if (flag1 || flag2) return true;
    }
    return false;
  }
};

class Solution2 {
  bool isScramble(string s1, string s2) {
    if (s1 == s2) return true;
    if (s1.size() != s2.size()) return false;
    int n = s1.size();
    vector<vector<vector<bool>>> dp(
        n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j][1] = (s1[i] == s2[j]);
      }
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        for (int j = 0; j <= n - len; j++) {
          for (int k = 1; k < len; k++) {
            bool a = dp[i][j][k] && dp[i + k][j + k][len - k];
            bool b = dp[i][j + len - k][k] && dp[i + k][j][len - k];
            if (a || b) {
              dp[i][j][len] = true;
            }
          }
        }
      }
    }
    return dp[0][0][n];
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}