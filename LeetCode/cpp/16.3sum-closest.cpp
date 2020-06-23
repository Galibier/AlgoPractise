#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; i++) {
      int left = i + 1, right = nums.size() - 1;
      while (left != right) {
        int sum = nums[left] + nums[right] + nums[i];
        if (abs(target - sum) < abs(target - ans)) {
          ans = sum;
        }
        if (sum > target) {
          right--;
        } else if (sum < target) {
          left++;
        } else {
          return ans;
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