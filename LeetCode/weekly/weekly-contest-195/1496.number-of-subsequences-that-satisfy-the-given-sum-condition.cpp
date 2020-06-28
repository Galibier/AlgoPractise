#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    const int mo = 1e9 + 7;
    vector<int> vec(1e5 + 1, 1);
    for (int i = 1; i < 1e5 + 1; i++) {
      vec[i] = 2 * vec[i - 1] % mo;
    }
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1;
    int res = 0;
    while (l <= r) {
      while (l <= r && nums[l] + nums[r] > target) {
        --r;
      }
      if (l <= r) {
        int len = r - l;
        int tmp = vec[len];
        res = (res % mo + tmp % mo) % mo;
      }
      ++l;
    }
    return res % mo;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> nums{14, 4,  6,  6,  20, 8,  5,  6,  8,  12, 6,  10,
                   14, 9,  17, 16, 9,  7,  14, 11, 14, 15, 13, 11,
                   10, 18, 13, 17, 17, 14, 17, 7,  9,  5,  10, 13,
                   8,  5,  18, 20, 7,  5,  5,  15, 19, 14};
  cout << sol.numSubseq(nums, 22) << endl;
  cout << 272148857 - 272187084 << endl;
  return 0;
}