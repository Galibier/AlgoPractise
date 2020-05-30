#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool kLengthApart(vector<int>& nums, int k) {
    int i;
    int idx = INT16_MIN;

    for (i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        if (i - idx - 1 < k) {
          return false;
        }
        idx = i;
      }
    }

    return true;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}