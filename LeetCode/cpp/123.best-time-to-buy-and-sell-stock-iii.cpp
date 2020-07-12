#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int k = 2;
    vector<int> dp_ik0(k + 1, 0);
    vector<int> dp_ik1(k + 1, INT_MIN);

    for (int price : prices) {
      for (int j = k; j > 0; j--) {
        // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
        dp_ik0[j] = max(dp_ik0[j], dp_ik1[j] + price);
        // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
        dp_ik1[j] = max(dp_ik1[j], dp_ik0[j - 1] - price);
      }
    }
    return dp_ik0[k];
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}