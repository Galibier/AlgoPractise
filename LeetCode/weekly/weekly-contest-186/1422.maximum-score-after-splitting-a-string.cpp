#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxScore(string s) {
    int ans = 0;
    vector<int> dp(s.length() - 1, 0);
    if (s[0] == '0')
      dp[0] = 1;
    else
      dp[0] = 0;
    for (int i = 1; i < s.length(); i++)
      if (s[i] == '1') dp[0]++;
    for (int j = 1; j < s.length() - 1; j++) {
      if (s[j] == '0')
        dp[j] = dp[j - 1] + 1;
      else
        dp[j] = dp[j - 1] - 1;
    }
    for (int k = 0; k < dp.size(); k++) ans = max(ans, dp[k]);
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.maxScore("011101") << endl;
  cout << sol.maxScore("00111") << endl;
  cout << sol.maxScore("1111") << endl;
  return 0;
}