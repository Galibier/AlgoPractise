#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int res = *max_element(nums.begin(), nums.end());
    if (res < 0) return res;

    for (auto n : nums) {
      if (sum + n < 0) {
        sum = 0;
      } else {
        res = max(res, sum + n);
        sum += n;
      }
    }
    return res;
  }

  int maxSubArray(vector<int>& nums) {
    int res = nums[0], sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (sum + nums[i] < nums[i])
        sum = nums[i];
      else
        sum += nums[i];
      res = max(res, sum);
    }
    return res;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}