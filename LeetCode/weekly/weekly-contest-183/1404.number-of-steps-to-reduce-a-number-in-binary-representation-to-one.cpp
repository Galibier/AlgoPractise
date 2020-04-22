#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int numSteps(string s) {
    int idx = s.size() - 1;
    int ans = 0;
    while (idx > 0) {
      if (s[idx] == '0') {
        ans++;
        idx--;
      } else {
        ans++;
        while (idx >= 0 && s[idx] == '1') {
          ans++;
          idx--;
        }
        if (idx > 0) s[idx] = '1';
      }
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}