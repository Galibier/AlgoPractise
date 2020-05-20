#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> simplifiedFractions(int n) {
    vector<string> res;

    for (int b = 2; b <= n; ++b) {
      for (int a = 1; a < b; ++a) {
        if (gcd(a, b) == 1) {
          res.push_back(to_string(a) + '/' + to_string(b));
        }
      }
    }

    return res;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.simplifiedFractions(1).size() << endl;
  cout << sol.simplifiedFractions(2).size() << endl;
  cout << sol.simplifiedFractions(3).size() << endl;
  cout << sol.simplifiedFractions(4).size() << endl;
  return 0;
}
