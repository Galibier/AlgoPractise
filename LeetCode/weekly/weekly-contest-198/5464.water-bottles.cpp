#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int cnt = numBottles;
    int bot = numBottles;
    while (bot >= numExchange) {
      cnt += bot / numExchange;
      bot = bot / numExchange + bot % numExchange;
    }
    return cnt;
  }
};

int main() {
  Solution sol;
  cout << sol.numWaterBottles(9, 3) << endl;
  cout << sol.numWaterBottles(15, 4) << endl;
  cout << sol.numWaterBottles(5, 5) << endl;
  cout << sol.numWaterBottles(2, 3) << endl;
  return 0;
}