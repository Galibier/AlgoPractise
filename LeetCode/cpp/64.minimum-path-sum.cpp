#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dp = grid[0];
    for (int j = 1; j < n; ++j) dp[j] += dp[j - 1];

    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j == 0)
          dp[j] = dp[j] + grid[i][j];
        else
          dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
      }
    }
    return dp[n - 1];
  }
};

int main() {
  Solution sol;
  return 0;
}