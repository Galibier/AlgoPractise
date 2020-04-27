#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
 public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int ans = dp[0];
    deque<int> stk;
    stk.push_back(0);
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(dp[stk.front()] + nums[i], nums[i]);
      ans = max(ans, dp[i]);
      if (i - stk.front() == k) stk.pop_front();
      while (!stk.empty() && dp[stk.back()] < dp[i]) stk.pop_back();
      stk.push_back(i);
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> cardPoints = {10, 2, -10, 5, 20};
  cout << sol.constrainedSubsetSum(cardPoints, 2) << endl;
  cardPoints = {-1, -2, -3};
  cout << sol.constrainedSubsetSum(cardPoints, 1) << endl;
  cardPoints = {10, -2, -10, -5, 20};
  cout << sol.constrainedSubsetSum(cardPoints, 2) << endl;
  return 0;
}