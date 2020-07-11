#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minDifference(vector<int>& nums) {
    if (nums.size() < 5) return 0;
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    int tmp1 = nums[right] - nums[left + 3];
    int tmp2 = nums[right - 1] - nums[left + 2];
    int tmp3 = nums[right - 2] - nums[left + 1];
    int tmp4 = nums[right - 3] - nums[left];
    return min(min(tmp1, tmp2), min(tmp(3, tmp4)));
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}