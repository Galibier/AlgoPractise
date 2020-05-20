#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxPower(string s) {
    int ans = 1, cur = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i - 1] == s[i]) {
        cur++;
      } else {
        ans = max(ans, cur);
        cur = 1;
      }
    }
    ans = max(ans, cur);
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.maxPower("leetcode") << endl;
  cout << sol.maxPower("abbcccddddeeeeedcba") << endl;
  cout << sol.maxPower("triplepillooooow") << endl;
  cout << sol.maxPower("hooraaaaaaaaaaay") << endl;
  cout << sol.maxPower("tourist") << endl;
  return 0;
}
