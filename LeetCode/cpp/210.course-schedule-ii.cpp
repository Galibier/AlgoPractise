#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    auto graph = make_graph(prerequisites, numCourses);
    auto degree = compute_indegree(graph);
    queue<int> zeros;
    for (int i = 0; i < numCourses; i++) {
      if (degree[i] == 0) zeros.push(i);
    }
    vector<int> toposort;
    for (int i = 0; i < numCourses; i++) {
      if (zeros.empty()) return vector<int>();
      int zero = zeros.front();
      zeros.pop();
      toposort.push_back(zero);
      for (int node : graph[zero]) {
        if (--degree[node] == 0) zeros.push(node);
      }
    }
    return toposort;
  }

 private:
  vector<unordered_set<int>> make_graph(
      const vector<vector<int>> &prerequisites, int course_num) {
    vector<unordered_set<int>> ret(course_num);
    for (auto pre : prerequisites) {
      ret[pre[1]].insert(pre[0]);
    }
    return ret;
  }

  vector<int> compute_indegree(const vector<unordered_set<int>> &graph) {
    vector<int> ret(graph.size(), 0);
    for (auto node : graph) {
      for (auto next : node) {
        ret[next]++;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  return 0;
}