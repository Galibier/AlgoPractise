#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCut(string s) {
    int len = s.size();
    vector<int> dp(len, 0);
    for (int i = 0; i < len; i++) {
      dp[i] = i;
    }
    vector<vector<bool>> isPalind(len, vector<bool>(len, false));
    for (int right = 0; right < len; right++) {
      for (int left = 0; left <= right; left++) {
        if (s[left] == s[right] &&
            (right - left <= 2 || isPalind[left + 1][right - 1])) {
          isPalind[left][right] = true;
        }
      }
    }
    for (int i = 0; i < len; i++) {
      if (isPalind[0][i]) {
        dp[i] = 0;
        continue;
      }
      for (int j = 0; j < i; j++) {
        if (isPalind[j + 1][i]) {
          dp[i] = min(dp[i], dp[j] + 1);
        }
      }
    }
    return dp[len - 1];
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}