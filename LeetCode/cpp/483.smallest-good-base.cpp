#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  string smallestGoodBase(string n) {
    long long int num = atoll(n.c_str());
    for (int m = log2(num); m >= 1; m--) {
      long long l = 2, r = powl(num, 1.0 / m) + 1, mid, sum;
      while (l < r) {
        mid = (l + r) / 2;
        sum = 1;
        for (int j = 0; j < m; ++j) {
          sum = sum * mid + 1;
        }
        if (sum == num) {
          return string(to_string(mid));
        } else if (sum < num) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
    }
    return "";
  }
};

int main() {
  Solution sol;
  cout << sol.smallestGoodBase("1000000000000000000") << endl;
  cout << sol.smallestGoodBase("4681") << endl;
  cout << sol.smallestGoodBase("13") << endl;
  return 0;
}