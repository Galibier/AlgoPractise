#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> dp(m, 1);
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        dp[j] = dp[j - 1] + dp[j];
      }
    }
    return dp[m - 1];
  }
};

int main() {
  Solution sol;
  return 0;
}