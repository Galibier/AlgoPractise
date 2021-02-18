#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size(), cols = matrix[0].size(),
        maxValue = numeric_limits<int>::min();
    for (int l = 0; l < cols; l++) {
      vector<int> rowSum(rows, 0);
      for (int r = l; r < cols; r++) {
        for (int i = 0; i < rows; i++) {
          rowSum[i] += matrix[i][r];
        }
        maxValue = max(maxValue, dpmax(rowSum, k));
      }
    }
    return maxValue;
  }

 private:
  int dpmax(const vector<int>& arr, int k) {
    int max = numeric_limits<int>::min();
    for (int l = 0; l < arr.size(); l++) {
      int sum = 0;
      for (int r = l; r < arr.size(); r++) {
        sum += arr[r];
        if (sum > max && sum <= k) max = sum;
      }
    }
    return max;
  }
};

int main() {
  Solution sol;
  return 0;
}