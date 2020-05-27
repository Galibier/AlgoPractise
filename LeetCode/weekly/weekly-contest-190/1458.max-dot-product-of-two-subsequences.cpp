#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int sz1 = nums1.size(), sz2 = nums2.size();
    vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, -1e8));

    for (int i = 1; i <= sz1; i++) {
      for (int j = 1; j <= sz2; j++) {
        dp[i][j] = nums1[i - 1] * nums2[j - 1];
        dp[i][j] = max(dp[i][j], nums1[i - 1] * nums2[j - 1] + dp[i - 1][j - 1]);
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
    }
    return dp[sz1][sz2];
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}