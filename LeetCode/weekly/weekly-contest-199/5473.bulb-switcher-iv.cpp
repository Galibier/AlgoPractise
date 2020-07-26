#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minFlips(string target) {
    int cnt = 0;
    for (int i = 0; i < target.size(); i++) {
      if (target[i] == '0' && cnt % 2 == 0) {
        continue;
      } else if (target[i] == '1' && cnt % 2 == 1) {
        continue;
      }
      cnt++;
    }
    return cnt;
  }
};

int main() {
  Solution sol;
  cout << sol.minFlips("10111") << endl;
  cout << sol.minFlips("101") << endl;
  cout << sol.minFlips("00000") << endl;
  cout << sol.minFlips("001011101") << endl;
  return 0;
}