#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    return Recursion(s1, s2);
  }
  bool Recursion(string s1, string s2) {
    if (s1 == s2) return true;
    string t1 = s1, t2 = s2;
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if (t1 != t2) return false;

    for (int i = 1; i < s1.size(); i++) {
      bool flag1 =
          Recursion(s1.substr(0, i), s2.substr(0, i)) &&
          Recursion(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i));
      bool flag2 =
          Recursion(s1.substr(0, i), s2.substr(s2.size() - i, i)) &&
          Recursion(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i));
      if (flag1 || flag2) return true;
    }
    return false;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}