#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    if (len < 3) return ans;
    for (int i = 0; i < len; i++) {
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int left = i + 1;
      int right = len - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          ans.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1]) left++;
          while (left < right && nums[right] == nums[right - 1]) right--;
          left++;
          right--;
        } else if (sum < 0)
          left++;
        else if (sum > 0)
          right--;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  for (auto vec : sol.threeSum(nums)) {
    for (auto n : vec) {
      cout << n << " ";
    }
    cout << endl;
  }
}