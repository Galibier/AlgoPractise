#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
  static constexpr long mod = 1000000000 + 7;

 public:
  int maxSum(vector<int>& nums1, vector<int>& nums2) {
    set<long> a(nums1.begin(), nums1.end());
    set<long> b(nums2.begin(), nums2.end());
    vector<long> c;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
    // for (long n : c) cout << n << " ";
    // puts("");
    long ans = 0;
    long index1 = 0, index2 = 0;
    for (long i = 0; i < c.size(); i++) {
      long sum1 = 0, sum2 = 0;
      for (index1; nums1[index1] != c[i]; index1++) {
        sum1 = (sum1 + nums1[index1]) % mod;
      }
      for (index2; nums2[index2] != c[i]; index2++) {
        sum2 = (sum2 + nums2[index2]) % mod;
      }
      //   cout << index1 << " " << index2 << endl;
      //   cout << sum1 << " " << sum2 << endl;
      ans = ((ans + max(sum1, sum2))% mod + c[i]) % mod;
      index1++, index2++;
    }
    long sum1 = 0, sum2 = 0;
    for (index1; index1 < nums1.size(); index1++)
      sum1 = (sum1 + nums1[index1]) % mod;
    for (index2; index2 < nums2.size(); index2++)
      sum2 = (sum2 + nums2[index2]) % mod;
    ans = (ans + max(sum1, sum2)) % mod;
    return ans;
  }
};

long main() {
  Solution sol;
  cout << sol.maxSum(nums1, nums2) << endl;
  return 0;
}
