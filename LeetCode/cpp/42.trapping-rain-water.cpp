#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int trap1(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int res = 0;
    int maxleft = 0, maxright = 0;
    while (left <= right) {
      if (height[left] <= height[right]) {
        if (height[left] >= maxleft)
          maxleft = height[left];
        else
          res += maxleft - height[left];
        left++;
      } else {
        if (height[right] >= maxright)
          maxright = height[right];
        else
          res += maxright - height[right];
        right--;
      }
    }
    return res;
  }

  int trap2(vector<int> height) {
    int sum = 0;
    vector<int> max_left(height.size(), 0);
    vector<int> max_right(height.size(), 0);

    for (int i = 1; i < height.size() - 1; i++) {
      max_left[i] = max(max_left[i - 1], height[i - 1]);
    }
    for (int i = height.size() - 2; i >= 0; i--) {
      max_right[i] = max(max_right[i + 1], height[i + 1]);
    }
    for (int i = 1; i < height.size() - 1; i++) {
      int minHeight = min(max_left[i], max_right[i]);
      if (minHeight > height[i]) {
        sum = sum + (minHeight - height[i]);
      }
    }
    return sum;
  }
};

int main() {
  Solution sol;
  vector<int> vec{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << sol.trap2(vec) << endl;
  return 0;
}