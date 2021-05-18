#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) {
      return 0;
    }
    vector<vector<int>> width(matrix.size(), vector<int>(matrix[0].size(), 0));
    int maxArea = 0;
    for (int row = 0; row < matrix.size(); row++) {
      for (int col = 0; col < matrix[0].size(); col++) {
        if (matrix[row][col] == '1') {
          if (col == 0) {
            width[row][col] = 1;
          } else {
            width[row][col] = width[row][col - 1] + 1;
          }
        } else {
          width[row][col] = 0;
        }

        int minWidth = width[row][col];
        for (int up_row = row; up_row >= 0; up_row--) {
          int height = row - up_row + 1;
          minWidth = min(minWidth, width[up_row][col]);
          maxArea = max(maxArea, height * minWidth);
        }
      }
    }
    return maxArea;
  }
};

int main() {
  vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                              {'1', '0', '1', '1', '1'},
                              {'1', '1', '1', '1', '1'},
                              {'1', '0', '0', '1', '0'}};
  Solution sol = Solution();
  cout << sol.maximalRectangle(matrix) << endl;
  return 0;
}