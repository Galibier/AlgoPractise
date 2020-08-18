#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> res(k, 0);
    int n = nums1.size(), m = nums2.size();
    for (int s = max(0, k - m); s <= min(k, n); s++) {
      vector<int> tmp;
      int i = 0, j = 0;
      vector<int> tmp1 = maxKsequence(nums1, s);
      vector<int> tmp2 = maxKsequence(nums2, k - s);
      auto iter1 = tmp1.begin(), iter2 = tmp2.begin();
      while (iter1 != tmp1.end() || iter2 != tmp2.end()) {
        tmp.push_back(
            lexicographical_compare(iter1, tmp1.end(), iter2, tmp2.end())
                ? *iter2++ : *iter1++);
      }
      res = lexicographical_compare(res.begin(), res.end(), tmp.begin(), tmp.end())
                ? tmp : res;
    }
    return res;
  }

 private:
  vector<int> maxKsequence(vector<int> v, int k) {
    int n = v.size();
    if (n <= k) {
      return v;
    }
    vector<int> res;
    int pop = n - k;
    for (int i = 0; i < n; i++) {
      while (!res.empty() && v[i] > res.back() && pop-- > 0) {
        res.pop_back();
      }
      res.push_back(v[i]);
    }
    res.resize(k);
    return res;
  }
};

int main() {
  Solution sol;
  return 0;
}