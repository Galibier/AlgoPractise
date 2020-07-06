#include <vector>
using namespace std;

class Solution {
 public:
  int numSubmat(vector<vector<int>>& mat) {
    vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 0));
    int sum = 0;
    for (int i = 0; i < mat.size(); i++) {
      dp[i][0] = mat[i][0];
    }

    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[i].size(); j++) {
        if (mat[i][j] == 0) {
          dp[i][j] = 0;
          continue;
        }
        int min_len = INT_MAX;

        if (j != 0) {
          dp[i][j] = dp[i][j - 1] + 1;
        }
        for (int k = i; k >= 0; k--) {
          min_len = min(min_len, dp[k][j]);
          sum += min_len;
        }
      }
    }

    return sum;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}