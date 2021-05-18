#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int pre = 1, curr = 1;  // dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++) {
      int tmp = curr;
      if (s[i] == '0')
        if (st.find(s.substr(i - 1, 2)) != st.end())
          curr = pre;
        else
          return 0;
      else if (st.find(s.substr(i - 1, 2)) != st.end())
        curr = curr + pre;
      pre = tmp;
    }
    return curr;
  }

 private:
  set<string> st{"1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9",
                 "10", "11", "12", "13", "14", "15", "16", "17", "18",
                 "19", "20", "21", "22", "23", "24", "25", "26"};
};

int main() {
  Solution sol;
  cout << sol.numDecodings("12") << endl;
  cout << sol.numDecodings("226") << endl;
  cout << sol.numDecodings("0") << endl;
  cout << sol.numDecodings("06") << endl;
  return 0;
}