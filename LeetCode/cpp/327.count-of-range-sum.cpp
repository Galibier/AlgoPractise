#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int size = nums.size();
    multiset<long long> preSum;

    long long preSum = 0;
    long long ans = 0;
    for (int i = 0; i < size; i++) {
      preSum += nums[i];
      if (preSum >= lower && preSum <= upper) {
        ans++;
      }
      if (preSum.size() != 0) {
        long long thresh1 = preSum = upper;
        long long thresh2 = preSum - lower;
        auto it1 = preSum.lower_bound(thresh1);
        auto it2 = preSum.lower_bound(thresh2);
        ans += (std::distance(it1, it2));
      }
      preSum.insert(preSum);
    }
    return ans;
  }
}

int main(){
  Solution sol;
  return 0;
}