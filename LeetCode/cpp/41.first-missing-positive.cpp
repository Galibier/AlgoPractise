#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (i + 1 == nums[i]) continue;
      int x = nums[i];
      while (x >= 1 && x <= nums.size() && x != nums[x - 1]) {
        swap(x, nums[x - 1]);
      }
    }
    cout << endl;
    for (int i = 0; i < nums.size(); i++) {
      if (i + 1 != nums[i]) return i + 1;
    }
    return nums.size() + 1;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> nums = {1, 2, 0};  // 3
  cout << sol.firstMissingPositive(nums) << endl;
  nums = {3, 4, -1, 1};  // 2
  cout << sol.firstMissingPositive(nums) << endl;
  nums = {7, 8, 9, 11, 12};  // 1
  cout << sol.firstMissingPositive(nums) << endl;
  return 0;
}