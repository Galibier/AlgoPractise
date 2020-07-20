#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string shortestPalindrome(string s) {
    int n = s.size();
    string rs = s;
    reverse(rs.begin(), rs.end());

    string st = s + "$" + rs;
    int n2 = st.size();
    vector<int> next(n2, 0);
    for (int i = 1; i < n2; i++) {
      int t = next[i - 1];
      while (t > 0 && st[t] != st[i]) {
        t = next[t - 1];
      }
      if (st[t] == st[i]) t++;
      next[i] = t;
    }

    for (auto n : next) {
      cout << n << " ";
    }
    cout << endl;
    int maxLen = next[n2 - 1];
    int sy = n - maxLen;
    string pre = rs.substr(0, sy);
    return pre + s;
  }
};

int main() {
  Solution sol;
  cout << sol.shortestPalindrome("aacecaaa") << endl;
  return 0;
}