#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> ans;
    bool flag = false;
    for (int i = 0; i < intervals.size(); i++) {
      if (newInterval[0] > intervals[i][1]) {
        ans.push_back(intervals[i]);
        continue;
      }
      if (newInterval[1] < intervals[i][0]) {
        ans.push_back(newInterval);
        flag = !flag;
        for (; i < intervals.size(); i++) ans.push_back(intervals[i]);
        break;
      }
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i][1]);
    }
    if (!flag) ans.push_back(newInterval);

    return ans;
  }
};

int main() {
  Solution sol = Solution();
  vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval = {4, 8};
  for (auto p : sol.insert(intervals, newInterval)) {
    cout << "[" << p[0] << ", " << p[1] << "] ";
  }
  cout << endl;
  return 0;
}