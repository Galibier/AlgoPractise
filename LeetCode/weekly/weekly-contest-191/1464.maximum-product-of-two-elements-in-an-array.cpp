#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    return (nums.at(0) - 1) * (nums.at(1) - 1);
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}