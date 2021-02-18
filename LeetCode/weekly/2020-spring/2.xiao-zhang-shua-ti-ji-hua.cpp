#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minTime(vector<int>& time, int m) {
    int sum = 0;
    for (auto n : time) {
      sum += n;
    }
    int average = sum / m;
    cout << "average:" << average << endl;
    vector<int> days(m, 0);
    int index = 0;
    int max_time = -1;
    for (auto n : time) {
      days[index] += n;
      max_time = max(max_time, n);
      if (days[index] > average) {
        days[index] -= max_time;
        index++;
        max_time = -1;
      }
    }
    int ret = -1;
    for (auto day : days) {
      ret = max(ret, day);
    }
    return ret;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> time = {1, 2, 3, 3};
  cout << sol.minTime(time, 2) << endl;
  time = {999, 999, 999};
  cout << sol.minTime(time, 4) << endl;
  return 0;
}