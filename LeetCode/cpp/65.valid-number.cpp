#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  bool isNumber(string s) {}
};

int main() {
  Solution sol = Solution();
  cout << sol.isNumber("0" ) << endl;          // true
  cout << sol.isNumber(" 0.1 " ) << endl;      // true
  cout << sol.isNumber("abc" ) << endl;        // false
  cout << sol.isNumber("1 a" ) << endl;        // false
  cout << sol.isNumber("2e10" ) << endl;       // true
  cout << sol.isNumber(" -90e3   " ) << endl;  // true
  cout << sol.isNumber(" 1e" ) << endl;        // false
  cout << sol.isNumber("e3" ) << endl;         // false
  cout << sol.isNumber(" 6e-1" ) << endl;      // true
  cout << sol.isNumber(" 99e2.5 " ) << endl;   // false
  cout << sol.isNumber("53.5e93" ) << endl;    // true
  cout << sol.isNumber(" --6 " ) << endl;      // false
  cout << sol.isNumber("-+3" ) << endl;        // false
  cout << sol.isNumber("95a54e53" ) << endl;   // false
}