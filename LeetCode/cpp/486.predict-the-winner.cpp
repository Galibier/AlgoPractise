#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp1(n, vector<int>(n, 0));
    vector<vector<int>> dp2(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      dp1[i][i] = nums[i];
      dp2[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
      for (int i = 0; i <= n - l; i++) {
        int j = i + l - 1;
        int left = nums[i] + dp2[i + 1][j];
        int right = nums[j] + dp2[i][j - 1];

        if (left > right) {
          dp1[i][j] = left;
          dp2[i][j] = dp1[i + 1][j];
        } else {
          dp1[i][j] = right;
          dp2[i][j] = dp1[i][j - 1];
        }
      }
    }

    return dp1[0][n - 1] >= dp2[0][n - 1];
  }
};

int main() {
  Solution sol = Solution();
  vector<int> input1{1, 5, 2};
  cout << sol.PredictTheWinner(input1) << endl;
  vector<int> input2 = {1, 5, 233, 7};
  cout << sol.PredictTheWinner(input2) << endl;
  return 0;
}
