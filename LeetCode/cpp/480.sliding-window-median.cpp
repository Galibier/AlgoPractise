#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> medians;
    unordered_map<int, int> hashTable;
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;

    int i = 0;
    while (i < k) {
      lo.push(nums[i++]);
    }
    for (int j = 0; j < k / 2; j++) {
      hi.push(lo.top());
      lo.pop();
    }
    while (true) {
      medians.push_back(k & 1 ? lo.top()
                              : ((double)lo.top() + (double)hi.top()) * 0.5);
      if (i >= nums.size()) break;
      int out_num = nums[i - k];
      int in_num = nums[i++];
      int balance = 0;
      balance += (out_num <= lo.top() ? -1 : 1);
      hashTable[out_num]++;
      if (!lo.empty() && in_num <= lo.top()) {
        balance++;
        lo.push(in_num);
      } else {
        balance--;
        hi.push(in_num);
      }
      if (balance < 0) {
        lo.push(hi.top());
        hi.pop();
        balance++;
      }
      if (balance > 0) {
        hi.push(lo.top());
        lo.pop();
        balance--;
      }

      while (hashTable[lo.top()]) {
        hashTable[lo.top()]--;
        lo.pop();
      }
      while (!hi.empty() && hashTable[hi.top()]) {
        hashTable[hi.top()]--;
        hi.pop();
      }
    }
    return medians;
  }

  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> medians;
    multiset<int> window(nums.begin(), nums.begin() + k);

    auto mid = next(window.begin(), k / 2);

    for (int i = k;; i++) {
      // Push the current median
      medians.push_back(((double)(*mid) + *next(mid, k % 2 - 1)) * 0.5);

      // If all done, break
      if (i == nums.size()) break;

      // Insert incoming element
      window.insert(nums[i]);
      if (nums[i] < *mid) mid--;  // same as mid = prev(mid)

      // Remove outgoing element
      if (nums[i - k] <= *mid) mid++;  // same as mid = next(mid)

      window.erase(window.lower_bound(nums[i - k]));
    }

    return medians;
  }
};

int main() {
  Solution sol;
  vector<int> vec{1, 3, -1, -3, 5, 3, 6, 7};
  for (auto c : sol.medianSlidingWindow(vec, 3)) {
    cout << c << " ";
  }
  cout << endl;
  return 0;
}