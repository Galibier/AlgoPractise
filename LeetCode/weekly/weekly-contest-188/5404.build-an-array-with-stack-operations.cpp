#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<int> tags(target[target.size() - 1], 0);
    for (auto t : target) {
      tags[t - 1] = 1;
    }
    vector<string> res;
    for (auto t : tags) {
      res.push_back("Push");
      if (t == 0) res.push_back("Pop");
    }
    return res;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}