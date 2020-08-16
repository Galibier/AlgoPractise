#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  char findKthBit(int n, int k) {
    vector<int> vec(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      vec[i] = vec[i - 1] * 2 + 1;
      //   cout << vec[i] << " ";
    }
    bool reverse = false;
    for (int i = n; i > 0; i--) {
        // cout << i << " " << vec[i] << " " << k << endl;
      if (k > vec[i] / 2 + 1) {
        reverse = !reverse;
        k = vec[i] - k + 1;
        // cout << " ER" << reverse << endl;
      } else if (k == vec[i] / 2 + 1 && k != 1) {
        // cout << " 111" << endl;
        return reverse ? '0' : '1';
      }
    }
    return reverse ? '1' : '0';
  }
};

int main() {
  Solution sol;
  //   cout << sol.findKthBit(3, 1) << endl;
  //   cout << sol.findKthBit(4, 11) << endl;
  //   cout << sol.findKthBit(1, 1) << endl;
  //   cout << sol.findKthBit(2, 3) << endl;
  //   cout << sol.findKthBit(3, 2) << endl;
  //   cout << sol.findKthBit(3, 5) << endl;
  cout << sol.findKthBit(4, 12) << endl;
  return 0;
}

/*
if (k == vec[i]) {
        return '1';
      } else
*/