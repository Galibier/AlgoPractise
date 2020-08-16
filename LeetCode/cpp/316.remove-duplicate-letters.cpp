#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> dict;
    unordered_map<char, int> used;
    for (int i = 0; i < s.size(); ++i) {
      dict[s[i]] = i;
    }

    vector<char> stk;
    for (int i = 0; i < s.size(); ++i) {
      if (used[s[i]] != 0) continue;
      while (stk.size() && s[i] < stk.back() && dict[stk.back()] > i) {
        --used[stk.back()];
        stk.pop_back();
      }
      stk.push_back(s[i]);
      ++used[s[i]];
    }
    string res;
    for (auto& i : stk) res += i;
    return res;
  }
};

int main() {
  Solution sol;
  cout << sol.removeDuplicateLetters("bcabc") << endl;
  cout << sol.removeDuplicateLetters("cbacdcbc") << endl;
  return 0;
}