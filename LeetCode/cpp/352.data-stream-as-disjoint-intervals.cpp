#include <iostream>
#include <set>
#include <vector>
using namespace std;

class SummaryRanges {
 public:
  SummaryRanges() {}

  void addNum(int val) { ans.insert(val); }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> res;
    int left = *ans.begin();
    int right = *ans.begin();
    for (auto it = ans.begin(); it != ans.end(); it++) {
      if (*it > right + 1) {
        res.push_back({left, right});
        left = *it;
      }
      right = *it;
    }
    res.push_back({left, right});
    return res;
  }

 private:
  /** Initialize your data structure here. */
  set<int> ans;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

int main() {
  SummaryRanges* obj = new SummaryRanges();
  obj->addNum(1);
  vector<vector<int>> param_2 = obj->getIntervals();
  delete obj;
  return 0;
}