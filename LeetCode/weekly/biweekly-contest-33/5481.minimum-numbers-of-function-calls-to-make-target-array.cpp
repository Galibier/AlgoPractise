#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    int a = 0;
    for (int i = 0; i < nums.size(); i++) {
      bitset<32> bits{nums[i]};
      ans += bits.count();
      a = max(a, nums[i]);
    }
    int cnt = 0;
    while (a != 0) {
      cnt++;
      a /= 2;
    }
    return ans + cnt;
  }
};

int main() {
  Solution sol;
  return 0;
}