#include <iostream>
#include <limits>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    int X1 = numeric_limits<int>::max();
    int Y1 = numeric_limits<int>::max();
    int X2 = numeric_limits<int>::min();
    int Y2 = numeric_limits<int>::min();

    int areas = 0;
    set<pair<int, int>> points;
    for (auto rect : rectangles) {
      int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
      X1 = min(x1, X1);
      Y1 = min(y1, Y1);
      X2 = max(x2, X2);
      Y2 = max(y2, Y2);

      areas += (x2 - x1) * (y2 - y1);
      vector<pair<int, int>> point{make_pair(x1, y1), make_pair(x2, y2),
                                   make_pair(x2, y1), make_pair(x1, y2)};

      for (auto p : point) {
        if (points.count(p)) {
          points.erase(p);
        } else {
          points.insert(p);
        }
      }
    }
    int expected = (X2 - X1) * (Y2 - Y1);
    if (areas != expected) {
      return false;
    }
    if (points.size() != 4 || points.count(make_pair(X1, Y1)) == 0 ||
        points.count(make_pair(X2, Y2)) == 0 ||
        points.count(make_pair(X1, Y2)) == 0 ||
        points.count(make_pair(X2, Y1)) == 0) {
      return false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> rectangles = {
      {1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
  cout << sol.isRectangleCover(rectangles) << endl;
  return 0;
}