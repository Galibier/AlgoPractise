#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();
    vector<int> dp(n + 3, 0);
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = -0x7FFFFFFE;
      sum += stoneValue[i];
      for (int j = 1; j <= 3; j++) {
        dp[i] = max(dp[i], sum - dp[i + j]);
      }
    }
    if (sum - dp[0] == dp[0]) {
      return "Tie";
    } else if (sum - dp[0] > dp[0]) {
      return "Bob";
    }
    return "Alice";
  }
};

int main() {
  Solution sol = Solution();
  vector<int> values = {1, 2, 3, 7};
  cout << sol.stoneGameIII(values) << endl;
  values = {1, 2, 3, -9};
  cout << sol.stoneGameIII(values) << endl;
  values = {1, 2, 3, 6};
  cout << sol.stoneGameIII(values) << endl;
  values = {1, 2, 3, -1, -2, -3, 7};
  cout << sol.stoneGameIII(values) << endl;
  values = {-1, -2, -3};
  cout << sol.stoneGameIII(values) << endl;
  return 0;
}