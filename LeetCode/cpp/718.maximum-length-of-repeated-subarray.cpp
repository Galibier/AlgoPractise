#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (A[i] == B[j]) {
          dp[i + 1][j + 1] = 1 + dp[i][j];
          ans = max(ans, dp[i + 1][j + 1]);
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}