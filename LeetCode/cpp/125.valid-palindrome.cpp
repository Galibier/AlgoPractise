#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    string str;
    for (char ch : s) {
      if (isalnum(ch)) {
        str += tolower(ch);
      }
    }
    string rev(str.rbegin(), str.rend());
    return str == rev;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << sol.isPalindrome("race a car") << endl;
  return 0;
}