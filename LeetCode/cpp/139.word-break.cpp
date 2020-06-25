#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    set<string> st(wordDict.begin(), wordDict.end());
    int lenStr = s.length();
    vector<bool> dp(lenStr + 1, false);
    dp[0] = true;
    for (int i = 1; i <= lenStr; i++) {
      for (int j = i; j >= 0; j--) {
        string lst = s.substr(j, i - j);
        if (st.find(lst) != st.end() && dp[j] == true) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[lenStr];
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}