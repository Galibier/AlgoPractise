#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string restoreString(string s, vector<int>& indices) {
    string ret = s;
    for (int i = 0; i < indices.size(); i++) {
      ret[indices[i]] = s[i];
    }
    return ret;
  }
};

int main() {
  Solution sol;
  return 0;
}