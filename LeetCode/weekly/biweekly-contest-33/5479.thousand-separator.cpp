#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  string thousandSeparator(int n) {
    string str = to_string(n);
    int len = str.size();
    if (n <= 3)
      return str;
    else {
      string ans = str.substr(0, len % 3);
      for (int i = 0; i * 3 < len; i++) {
        if (ans.size() != 0 && len % 3 + i * 3 != len) ans += ".";
        ans += str.substr(len % 3 + i * 3, 3);
      }
      return ans;
    }
  }
};

int main() {
  Solution sol;
  int n = 1;
  cout << n << " " << sol.thousandSeparator(n) << endl;
  n = 12;
  cout << n << " " << sol.thousandSeparator(n) << endl;
  n = 123;
  cout << n << " " << sol.thousandSeparator(n) << endl;
  n = 1234;
  cout << n << " " << sol.thousandSeparator(n) << endl;
  n = 12345;
  cout << n << " " << sol.thousandSeparator(n) << endl;
  n = 123456;
  cout << n << " " << sol.thousandSeparator(n) << endl;
  n = 1234567;
  cout << n << " " << sol.thousandSeparator(n) << endl;
  return 0;
}