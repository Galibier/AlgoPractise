#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int getMaxLen(vector<int>& nums) {
    // vector<int> vec(nums.size(), 0);
    // for (int i = 0; i < nums.size(); i++) {
    //   if (nums[i] > 0) {
    //     vec[i] = 1;
    //   } else if (nums[i] < 0) {
    //     vec[i] = -1;
    //   }
    // }
    int upper = 0, lower = 0, cnt = 0;
    int ans = 0, ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        // cout << "====>" << nums[i] << endl;
        upper++;
        cnt++;
        if (lower % 2 == 0) ans++;
        ans = max(cnt, ans);
      } else if (nums[i] < 0) {
        lower++;
        cnt = 0;
        // cout << "+" << lower << endl;
        if (lower % 2 == 0) {
          //   cout << "==" << upper << " " << lower << endl;
          ans = upper + lower;
        }
      } else {
        ret = max(ret, ans);
        // cout << ret << " " << ans << endl;
        ans = 0;
      }
    }
    ret = max(ret, ans);
    return ret;
  }
};

class Solution {
 public:
  int getMaxLen(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (nums[i] == 0) continue;

      int j = i;
      while (j < (int)nums.size() && nums[j] != 0) ++j;
      int cnt = 0;
      for (int k = i; k < j; ++k) cnt += (nums[k] < 0);

      if (cnt % 2 == 0) {
        ans = max(ans, j - i);
      } else {
        int l = -1, r = -1;
        for (int k = i; k < j; ++k) {
          if (nums[k] < 0) {
            l = k;
            break;
          }
        }
        for (int k = j - 1; k >= i; --k) {
          if (nums[k] < 0) {
            r = k;
            break;
          }
        }
        // left + 1, j; i, right
        ans = max(ans, j - l - 1);
        ans = max(ans, r - i);
      }
      i = j;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> vec = {1, -2, -3, 4};
  cout << sol.getMaxLen(vec) << endl;
  vec = {0, 1, -2, -3, -4};
  cout << sol.getMaxLen(vec) << endl;
  vec = {-1, -2, -3, 0, 1};
  cout << sol.getMaxLen(vec) << endl;
  vec = {1, -2};
  cout << sol.getMaxLen(vec) << endl;
  vec = {1, 2, 3, 5, -6, 4, 0, 10};
  cout << sol.getMaxLen(vec) << endl;
  vec = {-1, 2};
  cout << sol.getMaxLen(vec) << endl;
  vec = {-16, 0, -5, 2, 2, -13, 11, 8};
  cout << sol.getMaxLen(vec) << endl;
  return 0;
}