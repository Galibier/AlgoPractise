#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string makeGood(string s) {
    while (help(s))
      ;
    return s;
  }

 private:
  bool help(string &s) {
    for (int i = 0; i < s.size(); i++) {
      if (abs(s[i] - s[i + 1]) == 32) {
        s = s.substr(0, i) + s.substr(i + 2);
        // cout << s << endl;
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  cout << sol.makeGood("leEeetcode") << endl;
  cout << sol.makeGood("abBAcC") << endl;
  cout << sol.makeGood("s") << endl;

  return 0;
}