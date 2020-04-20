#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> processQueries(vector<int>& queries, int m) {
    vector<int> ans;
    vector<int> dm(m, 0);
    for (int i = 1; i <= m; i++) dm[i - 1] = i;
    for (int i = 0; i < queries.size(); i++) {
      for (int j = 0; j < m; j++) {
        if (dm[j] == queries[i]) {
          ans.push_back(j);
          for (int k = j; k >= 1; k--) {
            dm[k] = dm[k - 1];
          }
          dm[0] = queries[i];
          break;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> queries1 = {3, 1, 2, 1};
  for (auto str : sol.processQueries(queries1, 5)) cout << str << " ";
  cout << endl;
  vector<int> queries2 = {4, 1, 2, 2};
  for (auto str : sol.processQueries(queries2, 4)) cout << str << " ";
  cout << endl;
  vector<int> queries3 = {7, 5, 5, 8, 3};
  for (auto str : sol.processQueries(queries3, 8)) cout << str << " ";
  cout << endl;
  return 0;
}