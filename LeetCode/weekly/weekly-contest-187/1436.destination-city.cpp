#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string destCity(vector<vector<string>>& paths) {
    unordered_map<string, int> helper;
    for (auto p : paths) {
      helper[p[0]] += 1;
      helper[p[1]] += 0;
    }
    for (auto h : helper) {
      if (h.second == 0) {
        return h.first;
      }
    }
    return "";
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}