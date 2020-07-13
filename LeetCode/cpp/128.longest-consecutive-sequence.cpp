#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int ans = 0;

    for (const auto& n : nums) {
      if (st.count(n - 1) == 0) {
        int curr = n;
        int curr_ans = 1;
        while (st.count(curr + 1) != 0) {
          curr++;
          curr_ans++;
        }
        ans = max(ans, curr_ans);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}