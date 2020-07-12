#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int numIdenticalPairs(vector<int>& nums) {
    map<int, int> mp;
    for (auto n : nums) {
      mp[n]++;
    }
    int ret = 0;
    for (auto p : mp) {
      ret += calcu(p.second);
    }
    return ret;
  }

 private:
  constexpr int calcu(int n) { return n * (n - 1) / 2; }
};

int main() {
  Solution sol = Solution();
  return 0;
}