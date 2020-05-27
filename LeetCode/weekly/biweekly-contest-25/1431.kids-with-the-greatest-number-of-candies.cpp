#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxc = *max_element(candies.begin(), candies.end());
    vector<bool> ans((int)candies.size(), false);
    for (int i = 0; i < candies.size(); ++i)
      if (candies[i] + extraCandies >= maxc) ans[i] = true;

    return ans;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}