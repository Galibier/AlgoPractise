#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  int calculate(string s) {
    stack<int> st;
    int res = 0, n = s.size(), sign = 1;
    for (int i = 0; i < n; i++) {
      int num = 0;
      if (s[i] >= '0') {
        while (i < n && s[i] >= '0') {
          num = num * 10 + (s[i] - '0');
          i++;
        }
        i--;
        res += sign * num;
      } else if (s[i] == '+')
        sign = 1;
      else if (s[i] == '-')
        sign = -1;
      else if (s[i] == '(') {
        st.push(res);
        st.push(sign);
        res = 0;
        sign = 1;
      } else if (s[i] == ')') {
        res *= st.top();
        st.pop();
        res += st.top();
        st.pop();
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  cout << sol.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
  return 0;
}