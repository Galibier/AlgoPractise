/*
 * https://leetcode-cn.com/problems/nGK0Fy/
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int calculate(string s) {
    int x = 1, y = 0;
    for (auto c : s) {
      if (c == 'A') {
        x = 2 * x + y;
      }
      if (c == 'B') {
        y = 2 * y + x;
      }
    }
    return x + y;
  }
};

int main() {
  Solution sol;
  cout << sol.calculate("AB") << endl;
  return 0;
}