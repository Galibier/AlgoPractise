#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<int> vec(n * (n + 1) / 2, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j];
        vec[cnt++] = sum;
      }
    }
    sort(vec.begin(), vec.end());
    int ret = 0;
    for (int i = left - 1; i < right; i++) {
      ret += vec[i];
    }
    return ret;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> nums = {1, 2, 3, 4};
  cout << sol.rangeSum(nums, 4, 1, 5) << endl;
  return 0;
}