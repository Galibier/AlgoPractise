#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    std::vector<char> s;
    std::string result = "";
    for (int i = 0; i < num.size(); i++) {
      while (s.size() != 0 && num[i] < s[s.size() - 1] && k > 0) {
        s.pop_back();
        k--;
      }
      if (num[i] != '0' || s.size() != 0) s.push_back(num[i]);
    }
    while (s.size() != 0 && k > 0) {
      s.pop_back();
      k--;
    }
    for (int i = 0; i < s.size(); i++) {
      result += s[i];
    }
    if (result == "") return "0";
    return result;
  }
};

int main() {
  Solution sol;
  cout << sol.removeKdigits("1432219", 3) << endl;
  cout << sol.removeKdigits("10200", 1) << endl;
  cout << sol.removeKdigits("10", 2) << endl;
  return 0;
}