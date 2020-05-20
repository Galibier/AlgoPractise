#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string largestNumber(vector<int>& cost, int target) {
    vector<string> dp(target + 1, "#");
    dp[0] = "";
    for (int c = 0; c <= target; ++c) {
      for (int i = 0; i < cost.size(); ++i) {
        if (dp[c] == "#" || c + cost[i] > target) continue;

        string cur = to_string(i + 1) + dp[c];
        if (dp[c + cost[i]] == "#" || cmp(cur, dp[c + cost[i]]))
          dp[c + cost[i]] = cur;
      }
    }
    return dp[target] == "#" ? string("0") : dp[target];
  }

  bool cmp(string& s1, string& s2) {
    return (s1.size() > s2.size()) or ((s1.size() == s2.size()) and (s1 > s2));
  };
};

int main() {
  Solution sol = Solution();
  vector<int> cost;
  int target;
  cost = {4, 3, 2, 5, 6, 7, 2, 5, 5};
  target = 9;
  cout << sol.largestNumber(cost, target) << endl;
  cost = {7, 6, 5, 5, 5, 6, 8, 7, 8};
  target = 12;
  cout << sol.largestNumber(cost, target) << endl;
  cost = {2, 4, 6, 2, 4, 6, 4, 4, 4};
  target = 5;
  cout << sol.largestNumber(cost, target) << endl;
  cost = {6, 10, 15, 40, 40, 40, 40, 40, 40};
  target = 47;
  cout << sol.largestNumber(cost, target) << endl;
  return 0;
}
