#include <iostream>
#include <string>
#include <vector>
using namespace std;

// DFA Solution
// https://leetcode-cn.com/problems/valid-number/solution/biao-qu-dong-fa-by-user8973/
class Solution {
 public:
  bool isNumber(string s) {
    if (s.empty()) return false;
    int n = s.size();

    int state = 0;
    vector<bool> finals({0, 0, 0, 1, 0, 1, 1, 0, 1});  // 合法的终止状态
    vector<vector<int> > transfer({
        {0, 1, 6, 2, -1, -1},
        {-1, -1, 6, 2, -1, -1},
        {-1, -1, 3, -1, -1, -1},
        {8, -1, 3, -1, 4, -1},
        {-1, 7, 5, -1, -1, -1},
        {8, -1, 5, -1, -1, -1},
        {8, -1, 6, 3, 4, -1},
        {-1, -1, 5, -1, -1, -1},
        {8, -1, -1, -1, -1, -1},
    });

    for (int i = 0; i < n; ++i) {
      state = transfer[state][resolve_char(s[i])];
      if (state < 0) return false;
    }
    return finals[state];
  }

 private:
  int resolve_char(const char& c) {
    switch (c) {
      case ' ':
        return 0;
      case '+':
        return 1;
      case '-':
        return 1;
      case '.':
        return 3;
      case 'e':
        return 4;
      default:
        return resolve_number(c);
    }
  }

  int resolve_number(const char& c) {
    if (c >= '0' && c <= '9')
      return 2;
    else
      return 5;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.isNumber("0") << endl;         // true
  cout << sol.isNumber(" 0.1 ") << endl;     // true
  cout << sol.isNumber("abc") << endl;       // false
  cout << sol.isNumber("1 a") << endl;       // false
  cout << sol.isNumber("2e10") << endl;      // true
  cout << sol.isNumber(" -90e3  ") << endl;  // true
  cout << sol.isNumber(" 1e") << endl;       // false
  cout << sol.isNumber("e3") << endl;        // false
  cout << sol.isNumber(" 6e-1") << endl;     // true
  cout << sol.isNumber(" 99e2.5 ") << endl;  // false
  cout << sol.isNumber("53.5e93") << endl;   // true
  cout << sol.isNumber(" --6 ") << endl;     // false
  cout << sol.isNumber("-+3") << endl;       // false
  cout << sol.isNumber("95a54e53") << endl;  // false
}