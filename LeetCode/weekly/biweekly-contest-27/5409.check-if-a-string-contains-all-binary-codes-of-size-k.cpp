#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    int cnt = (1 << k);
    unordered_set<string> st;
    if ((int)s.size() - k + 1 < cnt) {
      return false;
    }
    for (int i = 0; i <= (int)s.size() - k; i++) {
      st.insert(s.substr(i, k));
    }
    return st.size() == cnt;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.hasAllCodes("00110110", 2) << endl;
  cout << sol.hasAllCodes("00110", 2) << endl;
  cout << sol.hasAllCodes("0110", 1) << endl;
  cout << sol.hasAllCodes("0110", 2) << endl;
  cout << sol.hasAllCodes("0000000001011100", 4) << endl;
  return 0;
}