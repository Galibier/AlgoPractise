
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int countSubstrings(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      ans += check(s, i, i);
      if (i == s.size() - 1) continue;
      ans += check(s, i, i + 1);
    }
    return ans;
  }

  int check(string& s, int l, int r) {
    int cnt = 0;
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      l--;
      r++;
      cnt++;
    }
    return cnt;
  }
};

int main() {
  Solution sol;
  cout << sol.countSubstrings("abc") << endl;
  cout << sol.countSubstrings("aaa") << endl;
  return 0;
}