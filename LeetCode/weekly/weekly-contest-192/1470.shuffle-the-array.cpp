#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> shuffle(vector<int> &nums, int n) {
    auto res = vector<int>();
    for (int i = 0; i < n; ++i) {
      res.push_back(nums[i]);
      res.push_back(nums[i + n]);
    }
    return res;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}