#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isSelfCrossing(vector<int>& x) {
    int x_size = x.size();
    for (int i = 3; i < x_size; ++i) {
      if (i >= 3 && x.at(i - 1) <= x.at(i - 3) && x.at(i) >= x.at(i - 2))
        return true;
      if (i >= 4 && x.at(i - 3) == x.at(i - 1) &&
          x.at(i) + x.at(i - 4) >= x.at(i - 2))
        return true;
      if (i >= 5 && x.at(i) + x.at(i - 4) >= x.at(i - 2) &&
          x.at(i - 1) + x.at(i - 5) >= x.at(i - 3) &&
          x.at(i - 2) > x.at(i - 4) && x.at(i - 3) > x.at(i - 1))
        return true;
    }
    return false;
  }
};

// 作者：LZH_Yves
// 链接：https://leetcode-cn.com/problems/self-crossing/solution/yi-bu-yi-bu-fen-xi-by-lzh_yves/

int main() {
  Solution sol;
  vector<int> vec{2, 1, 1, 2};
  cout << sol.isSelfCrossing(vec) << endl;
  vec = {1, 2, 3, 4};
  cout << sol.isSelfCrossing(vec) << endl;
  vec = {1, 1, 1, 1};
  cout << sol.isSelfCrossing(vec) << endl;
  return 0;
}