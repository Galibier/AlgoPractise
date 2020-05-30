

#include <deque>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    int ans = 0;
    deque<int> q1, q2;
    for (int i = 0, j = 0; i < nums.size(); i++) {
      while (!q1.empty() && q1.back() > nums[i]) q1.pop_back();
      q1.push_back(nums[i]);
      while (!q2.empty() && q2.back() < nums[i]) q2.pop_back();
      q2.push_back(nums[i]);

      while (!q1.empty() && !q2.empty() && q2.front() - q1.front() > limit) {
        if (nums[j] == q1.front()) q1.pop_front();
        if (nums[j] == q2.front()) q2.pop_front();
        j++;
      }
      ans = max(ans, i - j + 1);
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}