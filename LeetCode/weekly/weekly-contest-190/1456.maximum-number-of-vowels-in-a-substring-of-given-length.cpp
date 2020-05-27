#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int check(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      return 1;
    }
    return 0;
  }

  int maxVowels(string s, int k) {
    int cnt = 0, anw = 0;
    for (int i = 0; i < s.size(); i++) {
      cnt += check(s[i]);
      if (i >= k) {
        cnt -= check(s[i - k]);
      }
      anw = max(anw, cnt);
    }
    return anw;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.maxVowels("abciiidef", 3) << endl;
  cout << sol.maxVowels("aeiou", 2) << endl;
  cout << sol.maxVowels("leetcode", 3) << endl;
  cout << sol.maxVowels("rhythms", 4) << endl;
  cout << sol.maxVowels("tryhard", 4) << endl;
  return 0;
}