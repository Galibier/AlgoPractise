#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int ans = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        ++a;
        ++b;
        ans = max(ans, a);
      } else {
        a = b;
        b = 0;
      }
    }
    if (ans == nums.size()) ans--;
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> nums{1, 1, 0, 1};
  cout << sol.longestSubarray(nums) << endl;
  nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
  cout << sol.longestSubarray(nums) << endl;
  nums = {1, 1, 1};
  cout << sol.longestSubarray(nums) << endl;
  nums = {1, 1, 0, 0, 1, 1, 1, 0, 1};
  cout << sol.longestSubarray(nums) << endl;
  nums = {0, 0, 0};
  cout << sol.longestSubarray(nums) << endl;
  return 0;
}