#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    if (points.size() < 2) {
      return points.size();
    }
    int res = 0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
      int p1_x = points[i][0];
      int p1_y = points[i][1];
      int max_points = 0;
      int same_points = 1;
      map<pair<int, int>, int> mp;
      for (int j = i + 1; j < n; j++) {
        int p2_x = points[j][0];
        int p2_y = points[j][1];
        if (p1_x == p2_x && p1_y == p2_y) {
          ++same_points;
        } else {
          max_points = max(max_points, ++mp[getSlope(p1_x, p1_y, p2_x, p2_y)]);
        }
      }
      res = max(res, max_points + same_points);
    }
    return res;
  }

 private:
  pair<int, int> getSlope(int p1_x, int p1_y, int p2_x, int p2_y) {
    int dx = p2_x - p1_x;
    int dy = p2_y - p1_y;
    if (dx == 0) {
      return {0, p1_x};
    }
    if (dy == 0) {
      return {p1_y, 0};
    }
    int d = gcd(dy, dx);
    return {dy / d, dx / d};
  }
  int gcd(int m, int n) { return n == 0 ? m : gcd(n, m % n); }
};

int main() {
  Solution sol;
  return 0;
}