#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int len = cardPoints.size();
    vector<int> sum(cardPoints.size() + 1, 0);
    for (int i = 0; i < len; i++) {
      sum[i + 1] = sum[i] + cardPoints[i];
    }
    int ans = -1;
    for (int i = 0; i <= k; i++) {
      ans = max(ans, sum[i] + sum[len] - sum[len - k + i]);
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
  cout << sol.maxScore(cardPoints, 3) << endl;
  cardPoints = {2, 2, 2};
  cout << sol.maxScore(cardPoints, 2) << endl;
  cardPoints = {9, 7, 7, 9, 7, 7, 9};
  cout << sol.maxScore(cardPoints, 7) << endl;
  cardPoints = {1, 1000, 1};
  cout << sol.maxScore(cardPoints, 1) << endl;
  cardPoints = {1, 79, 80, 1, 1, 1, 200, 1};
  cout << sol.maxScore(cardPoints, 3) << endl;
  return 0;
}