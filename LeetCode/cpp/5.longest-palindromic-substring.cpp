#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() < 2) return s;

    string max = s.substr(0, 1);
    for (int i = 0; i < s.size() - 1; i++) {
      string first = helper(s, i, i);
      if (first.size() > max.size()) max = first;

      string second = helper(s, i, i + 1);
      if (second.size() > max.size()) max = second;
    }
    return max;
  }

 private:
  string helper(string s, int left, int right) {
    while (left >= 0 && right < s.size() && s[right] == s[left]) {
      left--;
      right++;
    }
    return s.substr(left + 1, right - 1 - left);
  }
};

class SolutionDp {
 public:
  string longestPalindrome(string s) {
    auto len = s.size();
    if (len == 1) {
      return s;
    }
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int i = 0; i < len; i++) {
      dp[i][i] = true;
    }
    int maxLen = 1;
    int begin = 0;
    for (int length = 2; length <= len; length++) {
      for (int i = 0; i < len; i++) {
        int j = i + length - 1;
        if (j >= len) {
          break;
        }
        if (s[i] == s[j]) {
          if (j - i >= 2) {
            dp[i][j] = dp[i + 1][j - 1];
          } else {
            dp[i][j] = true;
          }
        } else {
          dp[i][j] = false;
        }
        if (dp[i][j] && length > maxLen) {
          cout << i << " " << j << " " << length << endl;
          maxLen = length;
          begin = i;
        }
      }
    }
    return s.substr(begin, maxLen);
  }
};

int main() {
  Solution sol1;
  SolutionDp sol2;
  sol2.longestPalindrome("bb");
  return 0;
}
