#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    int sum = 0;
    for (auto v : nums) {
      sum += v;
    }
    int ts = 0;
    for (int i = 0; i < nums.size(); i++) {
      ts += nums[i];
      if (ts > sum - ts) {
        return vector<int>(nums.begin(), nums.begin() + i + 1);
      }
    }
    return nums;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}