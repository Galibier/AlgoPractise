#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int ans = nums.size() + 1;
    if (s == 0) {
      return 0;
    }

    int start = 0, end = 0;
    int sum = 0;
    while (end < nums.size()) {
      sum += nums[end];
      while (sum >= s) {
        ans = min(ans, end - start + 1);
        sum -= nums[start];
        start++;
      }
      end++;
    }
    return ans == nums.size() + 1 ? 0 : ans;
  }
};

int main() {
  Solution sol = Solution();
  int target = 7;
  vector<int> nums{2, 3, 1, 2, 4, 3};
  cout << sol.minSubArrayLen(target, nums) << endl;
  return 0;
}