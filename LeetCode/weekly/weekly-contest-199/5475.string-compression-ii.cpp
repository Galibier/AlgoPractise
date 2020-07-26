#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int getLengthOfOptimalCompression(string s, int k) {}
};

int main() {
  Solution sol;
  cout << sol.getLengthOfOptimalCompression("aaabcccd", 2) << endl;
  cout << sol.getLengthOfOptimalCompression("aabbaa", 2) << endl;
  cout << sol.getLengthOfOptimalCompression("aaaaaaaaaaa", 0) << endl;
  return 0;
}