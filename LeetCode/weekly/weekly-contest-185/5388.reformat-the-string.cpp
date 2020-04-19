#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  string reformat(string s) {
    string digits;
    string alphas;
    for (auto c : s) {
      if (isdigit(c)) digits += c;
      if (isalpha(c)) alphas += c;
    }
    int lend = digits.size();
    int lena = alphas.size();

    string ret = "";
    if (lend - lena == 1) {
      for (int i = 0; i < lena; i++) {
        ret += digits[i];
        ret += alphas[i];
      }
      ret += digits[digits.size() - 1];
    } else if (lena - lend == 1) {
      for (int i = 0; i < lend; i++) {
        ret += alphas[i];
        ret += digits[i];
      }
      ret += alphas[alphas.size() - 1];
    } else if (lena == lend) {
      for (int i = 0; i < lend; i++) {
        ret += alphas[i];
        ret += digits[i];
      }
    }
    return ret;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.reformat("a0b1c2") << endl;
  cout << sol.reformat("leetcode") << endl;
  cout << sol.reformat("1229857369") << endl;
  cout << sol.reformat("covid2019") << endl;
  cout << sol.reformat("ad123") << endl;
  return 0;
}