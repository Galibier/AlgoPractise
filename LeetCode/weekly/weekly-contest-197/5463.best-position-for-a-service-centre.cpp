#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  double sum(double x, double y, vector<vector<int>>& positions) {
    int n = positions.size();
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans += sqrt(pow(x - positions[i][0], 2) + pow(y - positions[i][1], 2));
    }
    return ans;
  }
  double getMinDistSum(vector<vector<int>>& positions) {
    int n = positions.size();
    double step = 100;
    double x = positions[0][0];
    double y = positions[0][1];
    while (step > 1e-5) {
      double rad = rand() % 360 + 1;
      double nx = x + step * cos(rad);
      double ny = y + step * sin(rad);
      if (sum(nx, ny, positions) < sum(x, y, positions)) {
        x = nx;
        y = ny;
      }
      step *= 0.99;
    }
    return sum(x, y, positions);
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}