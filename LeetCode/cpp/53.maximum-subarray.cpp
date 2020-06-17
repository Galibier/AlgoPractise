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
};

int main() {
  Solution sol = Solution();
  return 0;
}