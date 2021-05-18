#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int sum = nums[0], res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (sum + nums[i] < nums[i]) {
        sum = nums[i];
      } else {
        sum += nums[i];
      }
      res = max(res, sum);
    }
    return res;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}