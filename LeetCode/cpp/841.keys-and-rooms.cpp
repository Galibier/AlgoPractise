#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    int num = 0;
    vector<int> vis(n, false);
    dfs(rooms, vis, 0, num);
    return num == n;
  }

 private:
  vector<int> vis;
  int num;

  void dfs(vector<vector<int>>& rooms, vector<int>& vis, int x, int& num) {
    vis[x] = true;
    num++;
    for (auto& it : rooms[x]) {
      if (!vis[it]) {
        dfs(rooms, vis, it, num);
      }
    }
  }
};

int main() {
  Solution sol;
  return 0;
}