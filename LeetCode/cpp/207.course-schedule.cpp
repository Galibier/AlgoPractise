#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> degrees(numCourses);
    vector<vector<int>> adjacents(numCourses);
    queue<int> zero;
    int num = numCourses;
    for (int i = 0; i < prerequisites.size(); i++) {
      degrees[prerequisites[i][0]]++;
      adjacents[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    for (int i = 0; i < numCourses; i++)
      if (degrees[i] == 0) {
        zero.push(i);
        num--;
      }

    while (!zero.empty()) {
      int temp = zero.front();
      zero.pop();
      for (int j = 0; j < adjacents[temp].size(); j++)
        if (--degrees[adjacents[temp][j]] == 0) {galibier
          zero.push(adjacents[temp][j]);
          num--;
        }
    }
    if (num == 0) return true;
    return false;
  }
};

int main() {
  Solution sol;
  return 0;
}